#include <stdio.h>
#include "epsilon.h"
#include "sum_way.h"
#include "equal.h"

int main() {
	maxInt();
	minInt();
	machineEpsilon();

	printf("Float sum up: %g\n\n",sum_up_float());
	printf("Float sum down: %g\n\n",sum_down_float());

	printf("Explain the difference.\n");
	printf("In sum_up_float we start with a 'big' number. Therefore the last small digits in the last contribution will be ignored.\n");
	printf("In sum_down_float we start with the small numbers and let the snowball up to 'big' numbers.\n\n");

	printf("Does this sum converge as function of max?\n");
	printf("Since it is a harmonic series it diverge\n\n");

	printf("Double sum up: %g\n\n",sum_up_double());
	printf("Double sum down: %g\n\n",sum_down_double());

	printf("Explain the result of sum doubles.\n");
	printf("The last digit of the smallest number is still within the range of the double.\n\n");

	double a = 2.4; double b = 2.6; double tau = 0.25; double epsilon = 50;
	printf("a=%g, b=%g, tau=%g and epsilon=%g: equals = %i\n\n",\
			a,b,tau,epsilon,equal(a,b,tau,epsilon));

	return 0;
}
