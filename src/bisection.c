#include "bisection.h"
#include <stdio.h>
#include <math.h> 

double h(double x) {
    return exp(x) - 3.0 * x;
}

double find_intersection(double a, double b, double accuracy) {
    if (h(a) * h(b) >= 0) {
        printf("Error: There is no root in the given interval [%f, %f].\n", a, b);
        return -1.0; 
    }

    double c = a;
    int iterations = 0;

    while ((b - a) >= accuracy) {
        iterations++;
        c = (a + b) / 2.0;

        if (fabs(h(c)) < accuracy) {
            break;
        } else if (h(c) * h(a) < 0) {
            b = c;
        } else {
            a = c;
        }
    }

    printf("Number of iterations to achieve accuracy %f: %d\n", accuracy, iterations);
    return c;
}