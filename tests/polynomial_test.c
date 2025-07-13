#include "/home/k_andrey/math/include/polynomial.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <math.h>

typedef struct {
    int total;
    int failed;
} TestPolynomial;

void err_print(const char *func_name, const char *err_code) {
    printf("%s: FAILED (%s)\n", func_name, err_code);
}

void test_poly_create(TestPolynomial *result) {
    const uint32_t degree = 4;
    result->total++;

    Polynomial* pol = poly_create(degree); 
    if (pol == NULL) {
        err_print("test_poly_create", "polynomial null pointer");
        result->failed++;
        return;
    }

    if (pol->coeffs == NULL) {
        err_print("test_poly_create", "coeffs null pointer");
        result->failed++;
        free(pol);
        return;
    }

    if (pol->degree != degree) {
        err_print("test_poly_create", "degree mismatch");
        result->failed++;
        poly_free(pol);
        return;
    }

    for (uint32_t i = 0; i <= degree; i++) {
        if (pol->coeffs[i] != 0.0) {
            err_print("test_poly_create", "coeff not zero-initialized");
            result->failed++;
            poly_free(pol);
            return;
        }
    }

    printf("test_poly_create: PASSED\n");
    poly_free(pol);
}

void test_poly_set_get_coeff(TestPolynomial *result) {
    result->total++; 

    const uint32_t degree = 3;
    Polynomial *pol = poly_create(degree);
    
    if (pol == NULL) {
        err_print("test_poly_set_get_coeff", "poly_create failed");
        result->failed++;
        return;
    }

    double coeff_0 = 5.0;  
    double coeff_1 = -2.5; 
    double coeff_3 = 10.0; 

    poly_set_coeff(pol, 0, coeff_0);
    poly_set_coeff(pol, 1, coeff_1);
    poly_set_coeff(pol, 3, coeff_3);

    if (poly_get_coeff(pol, 0) != coeff_0) {
        err_print("test_poly_set_get_coeff", "get_coeff mismatch for power 0");
        result->failed++;
        poly_free(pol);
        return;
    }

    if (poly_get_coeff(pol, 1) != coeff_1) {
        err_print("test_poly_set_get_coeff", "get_coeff mismatch for power 1");
        result->failed++;
        poly_free(pol);
        return;
    }

    if (poly_get_coeff(pol, 3) != coeff_3) {
        err_print("test_poly_set_get_coeff", "get_coeff mismatch for power 3");
        result->failed++;
        poly_free(pol);
        return;
    }

    if (poly_get_coeff(pol, 2) != 0.0) {
        err_print("test_poly_set_get_coeff", "uninitialized coefficient at power 2 is not 0.0");
        result->failed++;
        poly_free(pol);
        return;
    }

    if (poly_get_coeff(pol, degree + 1) != 0.0) {
        err_print("test_poly_set_get_coeff", "get_coeff returned non-zero for power > degree");
        result->failed++;
        poly_free(pol);
        return;
    }

    printf("test_poly_set_get_coeff: PASSED\n");
    poly_free(pol);
}

TestPolynomial* all_test_polynomial() {
    TestPolynomial *result = (TestPolynomial*)malloc(sizeof(TestPolynomial));
    if (!result) {
        fprintf(stderr, "Memory allocation failed for test result\n");
        exit(1);
    }

    result->total = 0;
    result->failed = 0;

    test_poly_create(result);
    test_poly_set_get_coeff(result); 
    
    return result;
}

int main() {
    TestPolynomial *res_test = all_test_polynomial();
    printf("\nTotal: %d\nFailed: %d\n", res_test->total, res_test->failed);
    free(res_test);
    return 0;
}