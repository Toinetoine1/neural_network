//
// Created by toinetoine1 on 10/10/2021.
//

#include "2DArray.h"
#include "XOR.h"
#include "MathUtils.h"
#include "MatrixUtils.h"


void createNeuralNetwork() {
    double inputs[4][2] =
            {
                    {0, 0},
                    {0, 1},
                    {1, 0},
                    {1, 1}
            };

    int responses[4][1] =
            {
                    {0},
                    {1},
                    {1},
                    {0}
            };

    int inputNeurons = 2;
    int hiddenNeurons = 2;
    int outputNeurons = 1;

    double **hidden_layer_weights = create2DArray(inputNeurons, hiddenNeurons);
    initMatrixWithRandomValue(hidden_layer_weights, inputNeurons, hiddenNeurons);

    double **output_layer_weights = create2DArray(hiddenNeurons, outputNeurons);
    initMatrixWithRandomValue(output_layer_weights, hiddenNeurons, outputNeurons);

    //Training
    for(int i = 0; i < 2; i++){
        double **hidden_layer = applySigmoidToArray(
                multiplyMatrix(inputs, hidden_layer_weights, 4,2, inputNeurons, hiddenNeurons)
                , )




    }
}








