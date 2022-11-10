//
// Created by toinetoine1 on 23/10/2021.
//

#include <stdlib.h>
#include "NeuralNetwork.h"
#include "MatrixUtils.h"
#include "MathUtils.h"
#include "2DArray.h"
#include "stdio.h"

void feedForward(struct NeuralNetwork *nn, int trainingIndex);

void backPropagation(struct NeuralNetwork *nn, int trainingIndex);

void trainNeuralNetwork(struct NeuralNetwork *nn) {
    for (int n = 0; n < nn->epoch; n++) {

        int order[nn->trainingSets];
        for (int i = 0; i < nn->trainingSets; ++i) {
            order[i] = i;
        }
        shuffleArray(order, nn->trainingSets);
        //printf("Epoch: %d\n", n);

        for (int x = 0; x < nn->trainingSets; x++) {
            int i = order[x];
            feedForward(nn, i);
            backPropagation(nn, i);
        }
    }
}

void feedForward(struct NeuralNetwork *nn, int trainingIndex) {
    for (int j = 0; j < nn->hiddenNeurons; j++) {
        double activation = nn->hiddenLayerBias[j];
        for (int k = 0; k < nn->inputNeurons; k++) {
            activation += nn->trainingInputs[trainingIndex][k] * nn->hiddenWeights[k][j];
        }
        nn->hiddenLayer[j] = sigmoid(activation);
    }

    // Compute output layer activation
    for (int j = 0; j < nn->outputNeurons; j++) {
        double activation = nn->outputLayerBias[j];
        for (int k = 0; k < nn->hiddenNeurons; k++) {
            activation += nn->hiddenLayer[k] * nn->outputWeights[k][j];
        }
        nn->outputLayer[j] = sigmoid(activation);
    }
}

void backPropagation(struct NeuralNetwork *nn, int trainingIndex) {
    double deltaOutput[nn->outputNeurons];
    for (int j = 0; j < nn->outputNeurons; j++) {
        double expectedValue = nn->trainingOutputs[trainingIndex][j];
        double predictedValue = nn->outputLayer[j];
        double dError = (expectedValue - predictedValue);
        deltaOutput[j] = dError * sigmoidPrime(predictedValue);
    }

    // Compute change in hidden weights
    double deltaHidden[nn->hiddenNeurons];
    for (int j = 0; j < nn->hiddenNeurons; j++) {
        double dError = 0.0f;
        for (int k = 0; k < nn->outputNeurons; k++) {
            dError += deltaOutput[k] * nn->outputWeights[j][k];
        }
        deltaHidden[j] = dError * sigmoidPrime(nn->hiddenLayer[j]);
    }

    // Apply change in output weights
    for (int j = 0; j < nn->outputNeurons; j++) {
        nn->outputLayerBias[j] += deltaOutput[j] * nn->learningRate;
        for (int k = 0; k < nn->hiddenNeurons; k++) {
            nn->outputWeights[k][j] += nn->hiddenLayer[k] * deltaOutput[j] * nn->learningRate;
        }
    }

    // Apply change in hidden weights
    for (int j = 0; j < nn->hiddenNeurons; j++) {
        nn->hiddenLayerBias[j] += deltaHidden[j] * nn->learningRate;
        for (int k = 0; k < nn->inputNeurons; k++) {
            nn->hiddenWeights[k][j] += nn->trainingInputs[trainingIndex][k] * deltaHidden[j] * nn->learningRate;
        }
    }
}

void predict(struct NeuralNetwork *nn, double *array) {
    for (int j = 0; j < nn->hiddenNeurons; j++) {
        double activation = nn->hiddenLayerBias[j];
        for (int k = 0; k < nn->inputNeurons; k++) {
            activation += array[k] * nn->hiddenWeights[k][j];
        }
        nn->hiddenLayer[j] = sigmoid(activation);
    }

    // Compute output layer activation
    for (int j = 0; j < nn->outputNeurons; j++) {
        double activation = nn->outputLayerBias[j];
        for (int k = 0; k < nn->hiddenNeurons; k++) {
            activation += nn->hiddenLayer[k] * nn->outputWeights[k][j];
        }
        nn->outputLayer[j] = sigmoid(activation);
    }
}

void freeNeuralNetwork(struct NeuralNetwork *nn) {
    freeArray(nn->trainingInputs, nn->trainingSets);
    freeArray(nn->trainingOutputs, nn->trainingSets);

    free(nn->hiddenLayer);
    free(nn->outputLayer);

    free(nn->hiddenLayerBias);
    free(nn->outputLayerBias);

    freeArray(nn->hiddenWeights, nn->inputNeurons);
    freeArray(nn->outputWeights, nn->hiddenNeurons);
}


void saveNeuralNetworkInFile(struct NeuralNetwork *nn, char path[]) {
    FILE *fptr = fopen(path, "w");

    fprintf(fptr, "%d\n", nn->hiddenNeurons);

    for (int i = 0; i < nn->inputNeurons; ++i) {
        for (int j = 0; j < nn->hiddenNeurons; ++j) {
            if (j != 0)
                fprintf(fptr, " ");
            fprintf(fptr, "%f", nn->hiddenWeights[i][j]);
        }
        fprintf(fptr, "\n");
    }

    fprintf(fptr, "\n");

    for (int i = 0; i < nn->hiddenNeurons; ++i) {
        for (int j = 0; j < nn->outputNeurons; ++j) {
            if (j != 0)
                fprintf(fptr, " ");
            fprintf(fptr, "%f", nn->outputWeights[i][j]);
        }
        fprintf(fptr, "\n");
    }

    fprintf(fptr, "\n");

    for (int i = 0; i < nn->hiddenNeurons; ++i) {
        if (i != 0)
            fprintf(fptr, " ");
        fprintf(fptr, "%f", nn->hiddenLayerBias[i]);
    }

    fprintf(fptr, "\n");
    fprintf(fptr, "\n");

    for (int i = 0; i < nn->outputNeurons; ++i) {
        if (i != 0)
            fprintf(fptr, " ");
        fprintf(fptr, "%f", nn->outputLayerBias[i]);
    }

    fclose(fptr);
}

struct NeuralNetwork loadNeuralNetwork(char path[]) {
    struct NeuralNetwork neuralNetwork;
    neuralNetwork.inputNeurons = NN_INPUT_SIZE * NN_INPUT_SIZE;
    neuralNetwork.outputNeurons = NN_OUTPUT_SIZE;

    FILE *fptr = fopen(path, "r");

    if (!fptr) // file == NULL
    {
        printf("oops, file can't be read\n");
        exit(-1);
    }

    int hiddenNeurons = 0;
    fscanf(fptr, "%d", &hiddenNeurons);
    neuralNetwork.hiddenNeurons = hiddenNeurons;

    neuralNetwork.hiddenLayer = malloc(sizeof(double) * neuralNetwork.hiddenNeurons);
    neuralNetwork.outputLayer = malloc(sizeof(double) * neuralNetwork.outputNeurons);
    neuralNetwork.hiddenLayerBias = malloc(sizeof(double) * neuralNetwork.hiddenNeurons);
    neuralNetwork.outputLayerBias = malloc(sizeof(double) * neuralNetwork.outputNeurons);
    neuralNetwork.hiddenWeights = create2DArray(neuralNetwork.inputNeurons, neuralNetwork.hiddenNeurons);
    neuralNetwork.outputWeights = create2DArray(neuralNetwork.hiddenNeurons, neuralNetwork.outputNeurons);

    int maxValue = NN_INPUT_SIZE * NN_INPUT_SIZE * neuralNetwork.hiddenNeurons;
    int weightIndex = 0;
    double value = 0;
    while (weightIndex < maxValue && fscanf(fptr, "%lf", &value) == 1) {
        int i = weightIndex / neuralNetwork.hiddenNeurons;
        int j = weightIndex % neuralNetwork.hiddenNeurons;

        neuralNetwork.hiddenWeights[i][j] = value;
        weightIndex++;
    }

    maxValue = neuralNetwork.hiddenNeurons * neuralNetwork.outputNeurons;
    weightIndex = 0;
    value = 0;
    while (weightIndex < maxValue && fscanf(fptr, "%lf", &value) == 1) {
        int i = weightIndex / neuralNetwork.outputNeurons;
        int j = weightIndex % neuralNetwork.outputNeurons;

        neuralNetwork.outputWeights[i][j] = value;
        weightIndex++;
    }

    maxValue = neuralNetwork.hiddenNeurons;
    weightIndex = 0;
    value = 0;
    while (weightIndex < maxValue && fscanf(fptr, "%lf", &value) == 1) {
        neuralNetwork.hiddenLayerBias[weightIndex] = value;
        weightIndex++;
    }

    maxValue = neuralNetwork.outputNeurons;
    weightIndex = 0;
    value = 0;
    while (weightIndex < maxValue && fscanf(fptr, "%lf", &value) == 1) {
        neuralNetwork.outputLayerBias[weightIndex] = value;
        weightIndex++;
    }

    return neuralNetwork;
}