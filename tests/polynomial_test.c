#include "/home/k_andrey/math/include/polynomial.h" // <-- ИСПОЛЬЗУЙТЕ ЗАГОЛОВОЧНЫЙ ФАЙЛ!
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h> // Добавьте, если используете uint32_t в тестах напрямую, или если polynomial.h его не включает

typedef struct {
    int total;
    int failed;
} TestPolynomial;

void err_print(const char *func_name, const char *err_code) {
    printf("%s: FAILED (%s)\n", func_name, err_code);
}

void test_poly_create(TestPolynomial *result) {
    const uint32_t degree = 4; // Используйте uint32_t, как в poly_create
    result->total++;

    // Теперь poly_create и poly_free будут вызваны из скомпилированной polynomial.c
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

    for (uint32_t i = 0; i <= degree; i++) { // Используйте uint32_t для i
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

TestPolynomial* all_test() {
    TestPolynomial *result = (TestPolynomial*)malloc(sizeof(TestPolynomial));
    if (!result) {
        fprintf(stderr, "Memory allocation failed for test result\n");
        exit(1);
    }

    result->total = 0;
    result->failed = 0;

    test_poly_create(result);
    return result;
}

int main() {
    TestPolynomial *res_test = all_test();
    printf("\nTotal: %d\nFailed: %d\n", res_test->total, res_test->failed);
    free(res_test);
    return 0;
}