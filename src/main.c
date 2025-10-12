#include <stdio.h>
#include "bisection.h"

int main() {
    printf("Task_1\n");
    
    double intersection1 = find_intersection(0.0, 1.0, 0.0001);
    printf("Intersection point #1: x = %f\n", intersection1);

    double intersection2 = find_intersection(1.0, 2.0, 0.0001);
    printf("Intersection point #2: x = %f\n\n", intersection2);

    return 0;
}