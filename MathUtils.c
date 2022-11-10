//
// Created by toinetoine1 on 15/10/2021.
//

#include <math.h>
#include "MathUtils.h"

double sigmoid(double x) {
    return 1/(1+exp(-x));
}

double sigmoidPrime(double x) {
    return x*(1-x);
}


