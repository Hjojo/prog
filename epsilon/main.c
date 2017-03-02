#include <stdio.h>
#include "epsilon.h"
#include "sum_way.h"
#include "equal.h"

int main() {
	maxInt();
	minInt();
	machineEpsilon();

	printf("Float sum up: %g\n",sum_up_float());
	printf("Float sum down: %g\n",sum_down_float());

	double a = 2.4; double b = 2.6; double tau = 0.25; double epsilon = 50;
	printf("a=%g, b=%g, tau=%g and epsilon=%g: equals = %i\n",a,b,tau,epsilon,equal(a,b,tau,epsilon));

	return 0;
}
