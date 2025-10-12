#include "array_utils.h"
#include <stdio.h>
#include <stdlib.h> 
#include <time.h>   

void fill_array_random(int arr[N][N]) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            arr[i][j] = rand() % 100;
        }
    }
}

void rotate_array(int original[N][N], int rotated[N][N]) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            rotated[j][N - 1 - i] = original[i][j];
        }
    }
}

void print_array(int arr[N][N]) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            printf("%-3d ", arr[i][j]);
        }
        printf("\n");
    }
}

int calculate_checksum(int arr[], int size) {
    int sum = 0;
    for (int i = 0; i < size; i++) {
        sum += arr[i];
    }
    return sum;
}