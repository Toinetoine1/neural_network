//
// Created by toinetoine1 on 15/10/2021.
//

#ifndef XOR_MATHUTILS_H
#define XOR_MATHUTILS_H

double randfrom(double min, double max);
double **multiplyMatrix(double **m0, double **m1, int row_m0, int column_m0, int row_m1, int column_m1);

double sigmoid(double x);
double sigmoidPrime(double x);

#endif //XOR_MATHUTILS_H
