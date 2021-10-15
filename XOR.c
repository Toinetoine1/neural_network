//
// Created by toinetoine1 on 10/10/2021.
//

#include "2DArray.h"
#include "XOR.h"
#include "MathUtils.h"
#include "MatrixUtils.h"


void createNeuralNetwork() {
    double **inputs = create2DArray(4, 2);
    inputs[0][0] = 0;
    inputs[0][1] = 0;

    inputs[1][0] = 0;
    inputs[1][1] = 1;

    inputs[2][0] = 1;
    inputs[2][1] = 0;

    inputs[3][0] = 1;
    inputs[3][1] = 1;

    double **responses= create2DArray(4, 1);
    inputs[0][0] = 0;
    inputs[1][0] = 1;
    inputs[2][0] = 1;
    inputs[3][0] = 0;

    int inputNeurons = 2;
    int hiddenNeurons = 2;
    int outputNeurons = 1;

    double **hidden_layer_weights = create2DArray(inputNeurons, hiddenNeurons);
    initMatrixWithRandomValue(hidden_layer_weights, inputNeurons, hiddenNeurons);

    double **output_layer_weights = create2DArray(hiddenNeurons, outputNeurons);
    initMatrixWithRandomValue(output_layer_weights, hiddenNeurons, outputNeurons);

    //Training
    for (int i = 0; i < 1; i++) {

        //                        FEED FORWARD
        double **hiddenLayer = applySigmoidToArray(
                multiplyMatrix(inputs,
                               hidden_layer_weights,
                               4,
                               2,
                               inputNeurons,
                               hiddenNeurons),
                               4, hiddenNeurons);

        double **outputLayer = applySigmoidToArray(
                multiplyMatrix(hiddenLayer,
                               output_layer_weights,
                               4,
                               hiddenNeurons,
                               hiddenNeurons,
                               outputNeurons),
                4, outputNeurons);


        //                      BACKPROPAGATION
        double **outputLayerError = subtractionMatrix(responses, outputLayer, 4, outputNeurons);
        printArray(outputLayerError, 4, outputNeurons);

        double **outputLayerDelta = hadamardProduct(outputLayerError,
                                                    applySigmoidPrimeToArray(outputLayer, 4, outputNeurons),
                                                    4, outputNeurons);

        double **outputLayerWeightTransposed = transposeMatrix(output_layer_weights, hiddenNeurons, outputNeurons);
        double **hiddenLayerError = multiplyMatrix(outputLayerDelta, outputLayerWeightTransposed, 4, outputNeurons, outputNeurons, hiddenNeurons);

        double **hiddenLayerDelta = hadamardProduct(hiddenLayerError,
                                                    applySigmoidPrimeToArray(hiddenLayer, 4, outputNeurons),
                                                    4, outputNeurons);

        double **hiddenLayerTransposed = transposeMatrix(hiddenLayer, 4, hiddenNeurons);
        additionMatrix(output_layer_weights,
                       multiplyMatrix(hiddenLayerTransposed, outputLayerDelta, hiddenNeurons, 4, 4, outputNeurons),
                       hiddenNeurons, outputNeurons);

        double **inputLayerTransposed = transposeMatrix(inputs, 4, 2);
        additionMatrix(hidden_layer_weights,
                       multiplyMatrix(inputLayerTransposed, hiddenLayerDelta, 2, 4, 4, outputNeurons),
                       inputNeurons, hiddenNeurons);
    }
}