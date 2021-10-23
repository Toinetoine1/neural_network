//
// Created by toinetoine1 on 15/10/2021.
//

#include <stdlib.h>
#include <stdio.h>
#include "MatrixUtils.h"

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}


void shuffleArray(int array[], int size)
{
    int i;
    for(i = size-1; i > 0; i--) {
        int j = rand() % (i+1);
        swap(&array[i], &array[j]);
    }
}

double init_weight() { return ((double)rand())/((double)RAND_MAX); }

void initMatrixWithRandomValue(double **array, int row, int column) {
    for(int i = 0; i < row; i++){
        for(int j = 0; j < column; j++){
            array[i][j] = init_weight();
        }
    }

}

void initArrayWithZero(double *array, int row)
{
    for (int i = 0; i < row; i++) {
        array[i] = 0;
    }
}

void printArray(double **array, int row, int column){
    printf("-------------------------------\n");
    for(int i = 0; i < row; i++){
        for(int j = 0; j < column; j++){
            printf("%f ", array[i][j]);
        }
        printf("\n");
    }

    printf("-------------------------------\n");
}