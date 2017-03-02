#include <stdio.h>
#include <math.h>
#include <gsl/gsl_odeiv2.h>
#include <gsl/gsl_errno.h>

int yDiffEquation(double t, const double y[], double dydt[], void * params) {
	dydt[0] = y[0]*(1-y[0]);
	return GSL_SUCCESS;
}

double yFunction(double x) {
	gsl_odeiv2_system sys;
	sys.function = yDiffEquation;
	sys.jacobian = NULL;
	sys.dimension = 1;
	sys.params = NULL;

	double acc = 1e-6, eps = 1e-6, hstart = copysign(0.1,x);
	gsl_odeiv2_driver *driver = gsl_odeiv2_driver_alloc_y_new
		(&sys,gsl_odeiv2_step_rkf45,hstart,acc,eps);

	double t = 0, y[1] = {0.5};
	gsl_odeiv2_driver_apply(driver,&t,x,y);

	gsl_odeiv2_driver_free(driver);
	return y[0];
}

int main() {
	printf("t\t y(t)\t exact\n");
	for(double t = 0; t<=3; t += 0.1 ) {
		double exact = 1.0/(1+exp(-t));
		printf("%g\t %g\t %g\n",t,yFunction(t),exact);
	}
	return 0;
}
