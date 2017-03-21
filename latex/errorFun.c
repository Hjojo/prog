#include <stdio.h>
#include <math.h>
#include <gsl/gsl_errno.h>
#include <gsl/gsl_odeiv2.h>

int errorDiffFun(double x, const double u[], double dudx[], void * params) {
	dudx[0] = 2/sqrt(M_PI) * exp( -pow(x,2) );
	return GSL_SUCCESS;
}

double errorFun(double x1) {
	gsl_odeiv2_system sys;
	sys.function = errorDiffFun;
	sys.jacobian = NULL;
	sys.dimension = 1;
	sys.params = NULL;

	double acc = 1e-6, eps = 1e-6, hstart = copysign(0.1,x1);
	gsl_odeiv2_driver *driver = gsl_odeiv2_driver_alloc_y_new
		(&sys,gsl_odeiv2_step_rkf45,hstart,acc,eps);

	double x = 0, u[1] = {0};
	gsl_odeiv2_driver_apply(driver,&x,x1,u);

	gsl_odeiv2_driver_free(driver);
	return u[0];
}

int main(int argc, char * argv[]) {
	double x0 = atof(argv[1]);
	double xFinal = atof(argv[2]);
	double dx = atof(argv[3]);

	printf("x \t u \n");
	for(double x = x0; x <= xFinal; x += dx) {
		double u = errorFun(x);
		printf("%g \t %g \n",x,u);
	}
}
