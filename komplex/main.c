#include <stdio.h>
#include "komplexFun.h"

//typedef struct {double re,im;} komplex;

int main() {
	komplex a = {1,2}, b = {3,4};
	komplex r = komplex_add(a,b);
	komplex R = {4,6};
	printf("(%g,%g) + (%g,%g)",a.re,a.im,b.re,b.im);
	printf(" = (%g,%g)\n",r.re,r.im);
	printf("should be (%g,%g)\n",R.re,R.im);
	return 0;
}
