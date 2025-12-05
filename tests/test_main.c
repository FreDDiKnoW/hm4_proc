#include <stdio.h>
#include <assert.h>
#include <math.h>
#include <string.h>
#include "../include/bisection.h"
#include "../include/array_utils.h"

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

// (root near edge, accuracy break)
void test_bisection_edge_cases() {
    printf("Running test 'test_bisection_edge_cases'...\n");

    double tolerance = 0.00001;
    double expected_root1 = 0.619061;
    double expected_root2 = 1.512135;
    double a_near = 1.51213;
    double b_far = 1.6;
    double actual_root_near_a = find_intersection(a_near, b_far, 0.0000001);
    assert(fabs(actual_root_near_a - expected_root2) < tolerance);
    printf("  Subtest 'root_near_a' - SUCCEED\n");

    double a_far = 0.6;
    double b_near = 0.61907;
    double actual_root_near_b = find_intersection(a_far, b_near, 0.0000001);
    assert(fabs(actual_root_near_b - expected_root1) < tolerance);
    printf("  Subtest 'root_near_b' - SUCCEED\n");

    double a_break = 0.6125; 
    double b_break = 0.625;  
    double accuracy_large = 0.001; 
    double expected_c = (a_break + b_break) / 2.0; 
    
    double actual_root_break = find_intersection(a_break, b_break, accuracy_large);
    assert(fabs(actual_root_break - expected_c) < tolerance); 
    printf("  Subtest 'break_on_accuracy' - SUCCEED\n");
    
    printf("Test 'test_bisection_edge_cases' - SUCCEED\n");
}

// (Error Handling)
void test_bisection_no_root() {
    printf("Running test 'test_bisection_no_root'...\n");
    
    double result = find_intersection(2.0, 3.0, 0.001);
    assert(result == -1.0);
    
    printf("Test 'test_bisection_no_root' - SUCCEED\n");
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

void test_rotate_array_full_cycle() {
    printf("Running test 'test_rotate_array_full_cycle'...\n");
    
    int original[N][N] = {
        {1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12}, {13, 14, 15, 16}
    };
    
    int temp1[N][N], temp2[N][N];
    rotate_array(original, temp1);
    rotate_array(temp1, temp2);
    rotate_array(temp2, temp1);
    rotate_array(temp1, temp2);

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            assert(temp2[i][j] == original[i][j]);
        }
    }
    printf("Test 'test_rotate_array_full_cycle' - SUCCEED\n");
}

void test_rotate_uniform_matrix() {
    printf("Running test 'test_rotate_uniform_matrix'...\n");
    int uniform[N][N] = {
        {5, 5, 5, 5}, {5, 5, 5, 5},
        {5, 5, 5, 5}, {5, 5, 5, 5}
    };
    int result[N][N];
    
    rotate_array(uniform, result);
    for(int i=0; i<N; i++) {
        for(int j=0; j<N; j++) {
            assert(result[i][j] == 5);
        }
    }
    printf("Test 'test_rotate_uniform_matrix' - SUCCEED\n");
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

void test_checksum_edge_cases() {
    printf("Running test 'test_checksum_edge_cases'...\n");
    
    int single_element[] = {42};
    assert(calculate_checksum(single_element, 1) == 42);
    
    int zeros[] = {0, 0, 0};
    assert(calculate_checksum(zeros, 3) == 0);

    int empty[1] = {0}; 
    assert(calculate_checksum(empty, 0) == 0);

    printf("Test 'test_checksum_edge_cases' - SUCCEED\n");
}

void test_checksum_patterns() {
    printf("Running test 'test_checksum_patterns'...\n");
    int alternating[] = {10, -10, 20, -20};
    assert(calculate_checksum(alternating, 4) == 0);
    int negatives[] = {-1, -1, -1, -1};
    assert(calculate_checksum(negatives, 4) == -4);
    
    printf("Test 'test_checksum_patterns' - SUCCEED\n");
}

int main() {
    printf("========== Starting All Tests ==========\n\n");
    
    // 1. BISECTION TESTS
    test_find_intersection();
    test_bisection_edge_cases();
    test_bisection_no_root();      
    printf("\n");
    
    // 2. ARRAY ROTATION TESTS
    test_rotate_array();
    test_rotate_array_full_cycle();
    test_rotate_uniform_matrix();   
    printf("\n");
    
    // 3. CHECKSUM TESTS
    test_checksum_positive_numbers();
    test_checksum_mixed_numbers();
    test_checksum_edge_cases();
    test_checksum_patterns();
    
    printf("\n========== All tests SUCCEED! ==========\n");
    return 0;
}