#include <stdio.h>
#include <math.h>

int main() {
	printf("%i\n",1/2);
	printf("gamma: %g and bessel: %g\n",tgamma(5),j0(0.5));
	return 0;
}
