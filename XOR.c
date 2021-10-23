//
// Created by toinetoine1 on 10/10/2021.
//

#include <stdio.h>
#include <stdlib.h>
#include "XOR.h"
#include "MatrixUtils.h"
#include "NeuralNetwork.h"
#include "2DArray.h"

void createAndRunXOR(){
    struct NeuralNetwork neuralNetwork;
    struct NeuralNetwork* nn = &neuralNetwork;
    neuralNetwork.inputNeurons = 2;
    neuralNetwork.hiddenNeurons = 2;
    neuralNetwork.outputNeurons = 1;

    neuralNetwork.learningRate = 0.1;
    neuralNetwork.epoch = 10000;

    neuralNetwork.trainingSets = 4;

    double **trainingInputs = create2DArray(neuralNetwork.trainingSets, neuralNetwork.inputNeurons);
    trainingInputs[0][0] = 0;
    trainingInputs[0][1] = 0;

    trainingInputs[1][0] = 0;
    trainingInputs[1][1] = 1;

    trainingInputs[2][0] = 1;
    trainingInputs[2][1] = 0;

    trainingInputs[3][0] = 1;
    trainingInputs[3][1] = 1;
    nn->trainingInputs = trainingInputs;

    double **trainingOutputs = create2DArray(neuralNetwork.trainingSets, neuralNetwork.outputNeurons);
    trainingOutputs[0][0] = 0;
    trainingOutputs[1][0] = 1;
    trainingOutputs[2][0] = 1;
    trainingOutputs[3][0] = 0;
    nn->trainingOutputs = trainingOutputs;

    neuralNetwork.hiddenLayer = malloc(sizeof(double) * neuralNetwork.hiddenNeurons);
    neuralNetwork.outputLayer = malloc(sizeof(double) * neuralNetwork.outputNeurons);

    neuralNetwork.hiddenLayerBias = malloc(sizeof(double) * neuralNetwork.hiddenNeurons);
    neuralNetwork.outputLayerBias = malloc(sizeof(double) * neuralNetwork.outputNeurons);

    neuralNetwork.hiddenWeights = create2DArray(neuralNetwork.inputNeurons, neuralNetwork.hiddenNeurons);
    neuralNetwork.outputWeights = create2DArray(neuralNetwork.hiddenNeurons, neuralNetwork.outputNeurons);

    initArrayWithZero(nn->hiddenLayerBias, nn->hiddenNeurons);
    initArrayWithZero(nn->outputLayerBias, nn->outputNeurons);

    initMatrixWithRandomValue(nn->hiddenWeights, nn->inputNeurons, nn->hiddenNeurons);
    initMatrixWithRandomValue(nn->outputWeights, nn->hiddenNeurons, nn->outputNeurons);

    trainNeuralNetwork(nn);

    predict(nn, trainingInputs[0]);
    printf("Result: %f\n", nn->outputLayer[0]);

    predict(nn, trainingInputs[1]);
    printf("Result: %f\n", nn->outputLayer[0]);

    predict(nn, trainingInputs[2]);
    printf("Result: %f\n", nn->outputLayer[0]);

    predict(nn, trainingInputs[3]);
    printf("Result: %f\n", nn->outputLayer[0]);

    printf("\nsize: %zu\n", sizeof(neuralNetwork));

    freeNeuralNetwork(nn);
}