#include <stdio.h>
#include <limits.h>
#include <float.h>

void maxInt() {
	int i = 1;

	while(i+1>i) {
		i++;
	}

	printf("Calculated Int max: %i\nReal Int max: %i\n",i,INT_MAX);

}

void minInt() {
	int i = 1;
	while(i-1<i) {
		i--;
	}

	printf("Calculated Int min: %i\nReal Int max: %i\n",i,INT_MIN);
}

void machineEpsilon() {
	double x = 1;
	while(1+x != 1) {
		x /= 2;
	}
	x *= 2;
	printf("\tWhile loop\n");
	printf("Calculated double eps: %g\nReal double eps: %g\n",x,DBL_EPSILON);

	float f;
	for(f=1; 1+f != 1; f /= 2) {}
	f *= 2;
	printf("\tFor loop\n");
	printf("Calculated float eps: %g\nReal float eps: %g\n",f,FLT_EPSILON);

	long double ld = 1;
	do {
		ld /= 2;
	} while(1+ld != 1);
	ld *= 2;
	printf("\tdo while loop\n");
	printf("Calculated long double eps: %Lg\nReal long double eps: %Lg\n",ld,LDBL_EPSILON);

}
