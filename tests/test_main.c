#include <stdio.h>
#include <assert.h>
#include <math.h>
#include "../include/bisection.h"
#include "../include/array_utils.h"

void test_bisection_edge_cases() {
    printf("Running test 'test_bisection_edge_cases'...\n");
    double tolerance = 0.00001;
    double expected_root1 = 0.619061;
    double expected_root2 = 1.512135;
    double a_near = 1.51213;
    double b_far = 1.6;
    double actual_root_near_a = find_intersection(a_near, b_far, 0.0000001);
    printf("Test 'root_near_a': a=%f, b=%f, result=%f\n", a_near, b_far, actual_root_near_a);
    assert(fabs(actual_root_near_a - expected_root2) < tolerance);
    printf("Test 'root_near_a' - SUCCEED\n");

    double a_far = 0.6;
    double b_near = 0.61907;
    double actual_root_near_b = find_intersection(a_far, b_near, 0.0000001);
    printf("Test 'root_near_b': a=%f, b=%f, result=%f\n", a_far, b_near, actual_root_near_b);
    assert(fabs(actual_root_near_b - expected_root1) < tolerance);
    printf("Test 'root_near_b' - SUCCEED\n");

    double a_break = 0.6125; 
    double b_break = 0.625;  
    double accuracy_large = 0.001;
    double expected_c = (a_break + b_break) / 2.0; 
    double actual_root_break = find_intersection(a_break, b_break, accuracy_large);
    
    printf("Test 'break_on_accuracy': a=%f, b=%f, accuracy=%f\n", a_break, b_break, accuracy_large);
    printf("expected_c = %f, actual_result = %f\n", expected_c, actual_root_break);
    assert(fabs(actual_root_break - expected_c) < tolerance); 
    printf("Test 'break_on_accuracy' - SUCCEED\n");
    
    printf("Test 'test_bisection_edge_cases' - SUCCEED\n");
}

void test_find_intersection() {
    printf("Running test 'test_find_intersection'...\n");
    double tolerance = 0.001;
    double expected_root1 = 0.619;
    double expected_root2 = 1.512;
    double actual_root1 = find_intersection(0.0, 1.0, 0.0001);
    double actual_root2 = find_intersection(1.0, 2.0, 0.0001);
    assert(fabs(actual_root1 - expected_root1) < tolerance);
    assert(fabs(actual_root2 - expected_root2) < tolerance);
    printf("Test 'test_find_intersection' - SUCCEED\n");
}

void test_rotate_array() {
    printf("Running test 'test_rotate_array'...\n");
    int original[N][N] = {
        { 1,  2,  3,  4},
        { 5,  6,  7,  8},
        { 9, 10, 11, 12},
        {13, 14, 15, 16}
    };
    
    int expected_rotated[N][N] = {
        {13,  9,  5,  1},
        {14, 10,  6,  2},
        {15, 11,  7,  3},
        {16, 12,  8,  4}
    };

    int actual_rotated[N][N]; 
    rotate_array(original, actual_rotated);
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            assert(actual_rotated[i][j] == expected_rotated[i][j]);
        }
    }
    
    printf("Test 'test_rotate_array' - SUCCEED\n");
}


void test_checksum_positive_numbers() {
    printf("Running test 'test_checksum_positive_numbers'...\n");
    int arr[] = {1, 2, 3, 4, 5};
    assert(calculate_checksum(arr, 5) == 15);
    printf("Test 'test_checksum_positive_numbers' - SUCCEED\n");
}

void test_checksum_mixed_numbers() {
    printf("Running test 'test_checksum_mixed_numbers'...\n");
    int arr[] = {-1, 1, -10, 5};
    assert(calculate_checksum(arr, 4) == -5);
    printf("Test 'test_checksum_mixed_numbers' - SUCCEED\n");
}

int main() {
    printf("========== Starting All Tests ==========\n\n");
    
    test_find_intersection();
    test_bisection_edge_cases();
    printf("\n");
    test_rotate_array();
    printf("\n");
    test_checksum_positive_numbers();
    test_checksum_mixed_numbers();
    
    printf("\n========== All tests SUCCEED! ==========\n");
    return 0;
}