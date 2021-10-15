//
// Created by toinetoine1 on 15/10/2021.
//

#include <stdlib.h>
#include <stdio.h>
#include "MatrixUtils.h"
#include "MathUtils.h"
#include "2DArray.h"


void initMatrixWithRandomValue(double **array, int row, int column) {
    for(int i = 0; i < row; i++){
        for(int j = 0; j < column; j++){
            array[i][j] = randfrom(-1, 1);
        }
    }

}

void additionMatrix(double **m0, double **m1, int row, int column)
{
    for(int i = 0; i < row; i++){
        for(int j = 0; j < column; j++){
            m0[i][j] = m0[i][j] + m1[i][j];
        }
    }
}

double **subtractionMatrix(double **m1, double **m0, int row, int column)
{
    double **result = create2DArray(row, column);

    for(int i = 0; i < row; i++){
        for(int j = 0; j < column; j++){
            result[i][j] = m1[i][j] - m0[i][j];
        }
    }

    return result;
}

double **hadamardProduct(double **m0, double **m1, int row, int column)
{
    double **result = create2DArray(row, column);

    for(int i = 0; i < row; i++){
        for(int j = 0; j < column; j++){
            result[i][j] = m0[i][j] * m1[i][j];
        }
    }

    return result;
}

double **multiplyMatrix(double **m0, double **m1, int row_m0, int column_m0, int row_m1, int column_m1)
{
    if(column_m0 != row_m1)
    {
        printf("Produit matricielle impossible: %d différent de %d", column_m0, row_m1);
        exit(-1);
    }

    double **result = create2DArray(row_m0, column_m1);

    for (int i = 0; i < row_m0; ++i) {
        for (int j = 0; j < column_m1; ++j) {
            for (int k = 0; k < row_m1; ++k) {
                result[i][j] += m0[i][k] * m1[k][j];
            }
        }
    }

    return result;
}

double **applySigmoidToArray(double **array, int row, int column){
    for(int i = 0; i < row; i++){
        for(int j = 0; j < column; j++){
            array[i][j] = sigmoid(array[i][j]);
        }
    }

    return array;
}

double **applySigmoidPrimeToArray(double **array, int row, int column){
    for(int i = 0; i < row; i++){
        for(int j = 0; j < column; j++){
            array[i][j] = sigmoidPrime(array[i][j]);
        }
    }

    return array;
}

double **transposeMatrix(double **array, int row, int column){
    double **result = create2DArray(column, row);

    for(int i = 0; i < row; i++){
        for(int j = 0; j < column; j++){
            result[j][i] = array[i][j];
        }
    }

    return result;
}

void printArray(double **array, int row, int column){
    for(int i = 0; i < row; i++){
        for(int j = 0; j < column; j++){
            printf("%f ", array[i][j]);
        }
        printf("\n");
    }

}