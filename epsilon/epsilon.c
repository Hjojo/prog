#include <stdio.h>
#include <limits.h>
#include <float.h>

void maxInt() {
	int i = 1;

	while(i+1>i) {
		i++;
	}
	printf("\t While loop\n");
	printf("Calculated Int max: %i\nReal Int max: %i\n\n",i,INT_MAX);

	i = 1;
	for(i = 1; i<i+1; i++) {}
	printf("\t For loop\n");
	printf("Calculated Int max: %i\nReal Int max: %i\n\n",i,INT_MAX);

	i = 1;
	do {
		i++;
	} while(i+1>i);
	printf("\t Do while loop\n");
	printf("Calculated Int max: %i\nReal Int max: %i\n\n",i,INT_MAX);

}

void minInt() {
	int i = 1;

	while(i-1<i) {
		i--;
	}
	printf("\t While loop\n");
	printf("Calculated Int min: %i\nReal Int min: %i\n\n",i,INT_MIN);

	i = 1;

	for(i = 1; i>i-1; i--) {}
	printf("\t For loop\n");
	printf("Calculated Int min: %i\nReal Int min: %i\n\n",i,INT_MIN);

	i = 1;

	do {
		i--;
	} while(i-1<i);
	printf("\t Do while loop\n");
	printf("Calculated Int min: %i\nReal Int min: %i\n\n",i,INT_MIN);

}

void machineEpsilon() {

	printf("Machine Epsilon\n");
	printf("Only one of each loop type have been done for one of each types\n\n");

	double x = 1;
	while(1+x != 1) {
		x /= 2;
	}
	x *= 2;
	printf("\tWhile loop\n");
	printf("Calculated double eps: %g\nReal double eps: %g\n\n",x,DBL_EPSILON);

	float f;
	for(f=1; 1+f != 1; f /= 2) {}
	f *= 2;
	printf("\tFor loop\n");
	printf("Calculated float eps: %g\nReal float eps: %g\n\n",f,FLT_EPSILON);

	long double ld = 1;
	do {
		ld /= 2;
	} while(1+ld != 1);
	ld *= 2;
	printf("\tdo while loop\n");
	printf("Calculated long double eps: %Lg\nReal long double eps: %Lg\n\n",ld,LDBL_EPSILON);

}
