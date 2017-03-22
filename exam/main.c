#include <stdio.h>
#include <math.h>

double numArctan(double x);

int main() {
	double x = 6124201;
	printf("Self made arctan(%g) = %g\n",x,numArctan(x));
	printf("math.h arctan(%g) = %g\n",x,atan(x));

	return 0;
}
