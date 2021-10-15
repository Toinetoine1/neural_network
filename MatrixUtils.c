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
