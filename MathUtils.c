//
// Created by toinetoine1 on 15/10/2021.
//

#include <stdlib.h>
#include <math.h>
#include "MathUtils.h"

double randfrom(double min, double max)
{
    double range = (max - min);
    double div = RAND_MAX / range;
    return min + (rand() / div);
}

double sigmoid(double x) {
    return 1/(1+ exp(-x));
}

double sigmoidPrime(double x) {
    return x*(1-x);
}


