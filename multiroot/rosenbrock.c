#include <stdio.h>
#include <math.h>
#include <gsl/gsl_multiroots.h>
#include <gsl/gsl_errno.h>
#include <gsl/gsl_odeiv2.h>
#include <gsl/gsl_vector.h>
#include <assert.h>

int rosenbrockGradFun(const gsl_vector *v, void *params, gsl_vector *f) {
	double const x = gsl_vector_get(v,0);
	double const y = gsl_vector_get(v,1);

	double const dfdx = 2*(1-x) - 400*x*( y-pow(x,2) );
	double const dfdy = 200*( y-pow(x,2) );
	gsl_vector_set(f,0,dfdx);
	gsl_vector_set(f,1,dfdy);

	return GSL_SUCCESS;
}


int printState(size_t iter, gsl_multiroot_fsolver *s) {
	fprintf(stderr,"iter = %lu x = %.3g %.3g "
		"f(x) = %.3g %.3g\n",
		iter,
		gsl_vector_get((*s).x,0),
		gsl_vector_get((*s).x,1),
		gsl_vector_get((*s).f,0),
		gsl_vector_get((*s).f,1));
	return 0;
}


int main(void) {
	const gsl_multiroot_fsolver_type *T =
		gsl_multiroot_fsolver_hybrids;
	const size_t n = 2;

	gsl_multiroot_fsolver *s =
		gsl_multiroot_fsolver_alloc(T,n);

	gsl_multiroot_function f = {&rosenbrockGradFun,n,NULL};

	gsl_vector *v = gsl_vector_alloc(n);
	double vInit[2] = {0.5,0.5};
	gsl_vector_set(v,0,vInit[0]);
	gsl_vector_set(v,1,vInit[1]);

	gsl_multiroot_fsolver_set(s,&f,v);


	int maxIter = 1000, status;
	size_t iter = 0;
	double epsabs = 1e-7;
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

	fprintf(stderr,"status = %s\n", gsl_strerror(status));

	printf("Minimum at x = %.3g and y = %.3g\n",gsl_vector_get((*s).x,0),gsl_vector_get((*s).x,1));

	gsl_multiroot_fsolver_free(s);
	gsl_vector_free(v);

	return 0;
}
