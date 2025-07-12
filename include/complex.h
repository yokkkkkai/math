#ifndef COMPLEX_H
#define COMPLEX_H

typedef struct {
	double real;
	double imag;
} Complex;

void add(Complex num1, Complex num2);
void sub(Complex num1, Complex num2);

#endif