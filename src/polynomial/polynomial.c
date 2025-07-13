#include "/home/k_andrey/math/include/polynomial.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

//create and delete
Polynomial* poly_create(uint32_t degree) {
    Polynomial* pol = (Polynomial*)malloc(sizeof(Polynomial));
    if(pol == NULL) {
        fprintf(stderr, "Error creating polynomial!\n");
        return NULL;
    }

    pol->degree = degree;
    pol->coeffs = (double*)calloc(degree + 1, sizeof(double)); 
    if(pol->coeffs == NULL) {
        free(pol);
        fprintf(stderr, "Error creating coeffs!\n");
        return NULL;
    }

    return pol;
}

void poly_free(Polynomial *p) {
    if(p == NULL) {
        return;
    }

    free(p->coeffs);
    free(p);
}

//getters/setters

void poly_set_coeff(Polynomial *p, uint32_t power, double coeff) {
    if(p == NULL) {
        fprintf(stderr, "Polynomial pointer is NULL\n");
        return;
    }

    if(p->coeffs == NULL) {
        fprintf(stderr, "Coeffs pointer is NULL\n");
        return;
    }

    if(power > p->degree) {
        fprintf(stderr, "Power > degree\n");
    }

    p->coeffs[power] = coeff;
}


double poly_get_coeff(const Polynomial *p, int power) {
    if(p == NULL) {
        fprintf(stderr, "Error: Polynomial pointer is NULL\n");
        return 0.0;
    }

    if(p->coeffs == NULL) {
        fprintf(stderr, "Error: Coeffs pointer is NULL\n");
        return 0.0;
    }

    if(power > p->degree) {
        fprintf(stderr, "Error: Power > degree\n");
        return 0.0;
    }
    return p->coeffs[power];
}
