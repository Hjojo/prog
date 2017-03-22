#include <stdio.h>
#include <math.h>

double numArctan(double x);
int equal(double a, double b, double tau, double epsilon);

int main() {
	printf("# x \t self made \t math.h \t error\n");
	for(double x = -1000; x < 1000; x++) {
		if(equal(numArctan(x),atan(x),1e-6,1e-6) == 0) fprintf(stderr,"numArctan and atan are not equal for %g\n",x);
		printf("%g \t %g \t %g \t %g\n",x,numArctan(x),atan(x),numArctan(x)-atan(x));
	}

	return 0;
}
