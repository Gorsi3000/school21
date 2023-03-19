#include "math_func.h"

#include <math.h>
#include <stdio.h>
#include <stdlib.h>

double sum(double a, double b) { return a + b; }

double binary_minus(double a, double b) { return a - b; }

double unary_minus(double a) { return -a; }

double multiply(double a, double b) { return a * b; }

double _division(double a, double b) {
    if (b == 0) {
        printf("division by zero");
        exit(EXIT_FAILURE);
    }
    return a / b;
}

double ctg(double x) { return tan(M_PI / 2 - x); }
