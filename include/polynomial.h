#ifndef POLYNOMIAL_H
#define POLYNOMIAL_H

#include <stdint.h>

typedef struct {
    uint32_t degree;         
    double *coeffs;     
} Polynomial;

Polynomial* poly_create(uint32_t degree);
void poly_free(Polynomial *p);

void poly_set_coeff(Polynomial *p, uint32_t power, double coeff);
double poly_get_coeff(const Polynomial *p, int power);

Polynomial* poly_add(const Polynomial *p1, const Polynomial *p2);
Polynomial* poly_subtract(const Polynomial *p1, const Polynomial *p2);
Polynomial* poly_multiply(const Polynomial *p1, const Polynomial *p2);

double poly_evaluate(const Polynomial *p, double x);
Polynomial* poly_derivative(const Polynomial *p);

void poly_print(const Polynomial *p);

#endif