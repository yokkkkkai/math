#include "include/complex.h"


void add(Complex num1, Complex num2) {
	Complex result = {num1.real + num2.real, num1.imag + num2.imag};
	return result;
}

void sub(Complex num1, Complex num2) {
	Complex result = {num1.real - num2.real, num1.imag - num2.imag};
	return result;
}