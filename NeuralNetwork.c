//
// Created by toinetoine1 on 23/10/2021.
//

#include <stdlib.h>
#include "NeuralNetwork.h"
#include "MatrixUtils.h"
#include "MathUtils.h"
#include "2DArray.h"

void feedForward(struct NeuralNetwork *nn, int trainingIndex);

void backPropagation(struct NeuralNetwork *nn, int trainingIndex);

void trainNeuralNetwork(struct NeuralNetwork *nn) {
    for (int n = 0; n < nn->epoch; n++) {

        int order[] = {0, 1, 2, 3};
        shuffleArray(order, nn->trainingSets);

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








