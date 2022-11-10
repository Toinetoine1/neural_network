//
// Created by toinetoine1 on 15/10/2021.
//

#include "2DArray.h"
#include <stdlib.h>
#include <stdio.h>

double **create2DArray(int row, int column) {
    double **array;

    array = malloc(sizeof(double) * row);

    for (int i = 0; i < row; i++) {
        array[i] = malloc(sizeof(double) * column);
    }

    return array;
}

void freeArray(double **array, int row){
    for (int i = 0; i < row; i++){
        free(array[i]);
    }
    free(array);
}

void print2DArray(double **array, int row, int column){
    for (int i = 0; i < row; ++i) {
        for (int j = 0; j < column; ++j) {
            printf("%f", array[i][j]);
        }
        printf("\n");
    }
}