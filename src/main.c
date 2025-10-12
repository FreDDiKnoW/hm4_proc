#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "bisection.h"
#include "array_utils.h" 

int main() {
    srand(time(NULL));

    printf("--- Task 1: Finding the intersection of functions ---\n");
    double intersection1 = find_intersection(0.0, 1.0, 0.0001);
    printf("Intersection point #1: x = %f\n", intersection1);
    double intersection2 = find_intersection(1.0, 2.0, 0.0001);
    printf("Intersection point #2: x = %f\n\n", intersection2);

    printf("--- Task 2: Matrix Rotation ---\n");
    int original_array[N][N];
    int rotated_array[N][N];

    fill_array_random(original_array);
    printf("Original matrix:\n");
    print_array(original_array);

    rotate_array(original_array, rotated_array);
    printf("\nMatrix after 90-degree rotation:\n");
    print_array(rotated_array);
    
    printf("\n--- Complexity Analysis for Task 2 ---\n");
    printf("The time complexity of the N x N matrix rotation algorithm is O(N^2).\n\n");

    printf("--- Task 3: Checksum Calculation ---\n");
    int test_array[] = {10, 20, 30, 40, 50};
    int size = sizeof(test_array) / sizeof(test_array[0]);
    int checksum = calculate_checksum(test_array, size);
    printf("Test array: {10, 20, 30, 40, 50}\n");
    printf("Checksum (sum of elements): %d\n", checksum);

    return 0;
}