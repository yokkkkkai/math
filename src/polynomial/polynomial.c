#include "/home/k_andrey/math/include/polynomial.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

//create and delete
Polynomial* poly_create(uint32_t degree) {
    Polynomial* pol = (Polynomial*)malloc(sizeof(Polynomial));
    if(pol == NULL) {
        fprintf(stderr, "Error creating polynomial!");
        return NULL;
    }

    pol->degree = degree;
    pol->coeffs = (double*)calloc(degree + 1, sizeof(double)); 
    if(pol->coeffs == NULL) {
        free(pol);
        fprintf(stderr, "Error creating coeffs!");
        return NULL;
    }

    return pol;
}

void poly_free(Polynomial *p) {
    free(p->coeffs);
    free(p);
}