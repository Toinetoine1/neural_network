//
// Created by toinetoine1 on 15/10/2021.
//

#ifndef XOR_MATRIXUTILS_H
#define XOR_MATRIXUTILS_H

void initMatrixWithRandomValue(double **array, int row, int column);
void additionMatrix(double **m0, double **m1, int row, int column);
double **subtractionMatrix(double **m1, double **m0, int row, int column);
double **hadamardProduct(double **m0, double **m1, int row, int column);
double **multiplyMatrix(double **m0, double **m1, int row_m0, int column_m0, int row_m1, int column_m1);
double **transposeMatrix(double **array, int row, int column);
double **applySigmoidToArray(double **array, int row, int column);
double **applySigmoidPrimeToArray(double **array, int row, int column);
void printArray(double **array, int row, int column);

#endif //XOR_MATRIXUTILS_H
