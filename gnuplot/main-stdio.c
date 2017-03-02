#include <stdio.h>
#include <math.h>
#include <tgmath.h>

int main() {
	double x;
	while( scanf("%lg ",&x) != EOF ) {
		printf("%lg \t %g\n",x,cos(x));
	}

	return 0;
}
