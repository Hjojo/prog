#include <stdio.h>
#include <math.h>
#include <gsl/gsl_errno.h>
#include <gsl/gsl_odeiv2.h>
#include <gsl/gsl_multiroots.h>
#include <gsl/gsl_vector.h>
#include <assert.h>

int hydrogenDiff(double r, const double f[], double dfdr[], void *params) {
	double e = *(double*)params;
	dfdr[0] = f[1];
	dfdr[1] = -2*(e+1.0/r)*f[0];
	return GSL_SUCCESS;
}

double hydrogenSolution(double e, double r) {
	assert(r>=0);
	const double rmin = 1e-3;
	if(r<rmin) {
		return r-r*r;
	}

	gsl_odeiv2_system sys;
	sys.function = hydrogenDiff;
	sys.jacobian = NULL;
	sys.dimension = 2;
	sys.params = (void*)&e;

	double hstart = 1e-3, absErr = 1e-6, relErr = 1e-6;
	gsl_odeiv2_driver * driver = gsl_odeiv2_driver_alloc_y_new(
		&sys, gsl_odeiv2_step_rkf45,hstart,absErr,relErr);

	double t = rmin, y[2] = {t-t*t,1-2*t};
	int status = gsl_odeiv2_driver_apply(driver,&t,r,y);

	if(status != GSL_SUCCESS) {
		fprintf(stderr,"hydrogenSolution: odeiv2 error: %d\n",status);
	}

	gsl_odeiv2_driver_free(driver);
	return y[0];
}

int hydrogenFun(const gsl_vector *v, void *params, gsl_vector *f) {
	double e = gsl_vector_get(v,0);
	assert(e<0);
	double rmax = *(double*)params;
	double fval = hydrogenSolution(e,rmax);
	gsl_vector_set(f,0,fval);
	return GSL_SUCCESS;
}

int printState(size_t iter, gsl_multiroot_fsolver *s) {
	fprintf(stderr,"iter = %lu e = %.3g f(e) = %.3g\n",
		iter,
		gsl_vector_get((*s).x,0),
		gsl_vector_get((*s).f,0));
	return 0;
}

int main(int argc, char** argv) {
	double rmax = argc>1 ? atof(argv[1]):10;
	fprintf(stderr,"rmax = %g\n",rmax);

	const gsl_multiroot_fsolver_type *T =
		gsl_multiroot_fsolver_hybrids;
	size_t n = 1;
	gsl_multiroot_fsolver *s =
		gsl_multiroot_fsolver_alloc(T,n);

	gsl_multiroot_function f = {&hydrogenFun,n,(void*)&rmax};

	gsl_vector *v = gsl_vector_alloc(n);
	double vInit = -1;
	gsl_vector_set(v,0,vInit);

	gsl_multiroot_fsolver_set(s,&f,v);


	int maxIter = 1000, status;
	size_t iter = 0;
	double epsabs = 1e-3;
	printState(iter,s);
	do {
		iter++;
		status = gsl_multiroot_fsolver_iterate(s);

		printState(iter,s);

		if(status) {
			break;
		}

		status = gsl_multiroot_test_residual((*s).f,epsabs);
	} while(status == GSL_CONTINUE && iter < maxIter);

	fprintf(stderr,"status = %s\n",gsl_strerror(status));

	double e = gsl_vector_get((*s).x,0);
	printf("rmax = %.3g, e = %g\n\n",rmax,e);

	printf("r \t Fe(e,r) \t exact\n");
	for(double r = 0; r<=rmax; r+=rmax/100) {
		printf("%g %g %g\n",r,hydrogenSolution(e,r),r*exp(-r));
	}

	gsl_multiroot_fsolver_free(s);
	gsl_vector_free(v);

	return 0;
}
