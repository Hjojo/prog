#include <stdio.h>

int main() {
	float f = 0.1111111111111111111111111111;
	double d = 0.1111111111111111111111111111;
	long double ld = 0.1111111111111111111111111111L;

	printf("Float digits: %.25g\n",f);
	printf("Double digits: %.25lg\n",d);
	printf("Long double: %.25Lg\n",ld);

	return 0;
}
