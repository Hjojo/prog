#include <stdio.h>
#include <math.h>
#include <gsl/gsl_odeiv2.h>
#include <gsl/gsl_errno.h>

int yDiffEquation(double t, const double y[], double dydt[], void * params) {
	double epsilon = *(double *) params;
	dydt[0] = y[1];
	dydt[1] = 1-y[0]+epsilon*y[0]*y[0];
	return GSL_SUCCESS;
}

double yFunction(double x, double y[], double epsilon) {
	gsl_odeiv2_system sys;
	sys.function = yDiffEquation;
	sys.jacobian = NULL;
	sys.dimension = 2;
	sys.params = (void *) &epsilon;

	double acc = 1e-6, eps = 1e-6, hstart = copysign(0.1,x);
	gsl_odeiv2_driver *driver = gsl_odeiv2_driver_alloc_y_new
		(&sys,gsl_odeiv2_step_rkf45,hstart,acc,eps);

	double t = 0;
	gsl_odeiv2_driver_apply(driver,&t,x,y);

	gsl_odeiv2_driver_free(driver);
	return y[0];
}

int main() {
	printf("phi\t u1\t u2\t u3\n");
	for(double phi = 0; phi<=4*M_PI; phi += 0.1 ) {
		double y1[2] = {1,0}, y2[2] = {1,-0.5}, y3[2] = {1,-0.5};
		printf("%g\t %g\t %g\t %g\n",phi,
					yFunction(phi,y1,0),
					yFunction(phi,y2,0),
					yFunction(phi,y3,0.01));
	}
	return 0;
}
