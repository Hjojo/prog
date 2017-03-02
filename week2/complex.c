#include <stdio.h>
#include <math.h>
#include <complex.h>

int main() {
	double _Complex sqrtNeg2 = csqrt(-2);
	printf("sqrt(-2): Real part: %g, Imag part: %g\n",creal(sqrtNeg2),cimag(sqrtNeg2));

	double _Complex eI = cexp(I);
	printf("e^i: Real part: %g, Imag part: %g\n",creal(eI),cimag(eI));

	double _Complex eIPi = cexp(I*M_PI);
	printf("e^iPi: Real part: %g, Imag part: %g\n",creal(eIPi),cimag(eIPi));

	double _Complex ie = cpow(I,M_E);
	printf("i^e: Real part: %g, Imag part: %g\n",creal(ie),cimag(ie));

	return 0;
}
