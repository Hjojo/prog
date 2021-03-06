#include <stdio.h>
#include "komplexFun.h"

//typedef struct {double re,im;} komplex;

int main() {
	komplex a = {1,2}, b = {3,4};
	komplex r1 = komplex_add(a,b);
	komplex R1 = {4,6};
	printf("Adding:\n");
	printf("(%g,%g) + (%g,%g)",a.re,a.im,b.re,b.im);
	komplex_print(" =",r1);
	komplex_print("should be",R1);
	printf("\n");

	komplex r2 = komplex_sub(a,b);
	komplex R2 = {-2,-2};
	printf("Subtracting:\n");
	printf("(%g,%g) - (%g,%g)",a.re,a.im,b.re,b.im);
	komplex_print(" =",r2);
	komplex_print("should be",R2);
	printf("\n");

	komplex r3 = komplex_conjugate(a);
	komplex R3 = {1,-2};
	printf("Conjugate:\n");
	printf("conj(%g,%g) = (%g,%g)\n",a.re,a.im,r3.re,r3.im);
	komplex_print("should be",R3);
	printf("\n");

	return 0;
}
