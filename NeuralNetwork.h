//
// Created by toinetoine1 on 23/10/2021.
//

#ifndef XOR_NEURALNETWORK_H
#define XOR_NEURALNETWORK_H

struct NeuralNetwork {
    int inputNeurons;
    int hiddenNeurons;
    int outputNeurons;

    double learningRate;
    int epoch;

    int trainingSets;
    double **trainingInputs;
    double **trainingOutputs;

    double *hiddenLayer;
    double *outputLayer;

    double *hiddenLayerBias;
    double *outputLayerBias;

    double **hiddenWeights;
    double **outputWeights;
};

void trainNeuralNetwork(struct NeuralNetwork *nn);
void predict(struct NeuralNetwork *nn, double *array);
void freeNeuralNetwork(struct NeuralNetwork *nn);

#endif //XOR_NEURALNETWORK_H