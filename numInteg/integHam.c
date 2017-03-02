#include <stdio.h>
#include <gsl/gsl_integration.h>
#include <math.h>
#include <gsl/gsl_errno.h>

double normFun(double x, void * params) {
	double alpha = *(double *) params;
	return exp(-alpha*pow(x,2));
}

double normInteg(double alpha) {
	gsl_function f;
	f.function = &normFun;
	f.params = (void*)&alpha;

	int limit = 100;
	double acc = 1e-6, eps = 1e-6, result, error;
	gsl_integration_workspace * workspace
		= gsl_integration_workspace_alloc(limit);

	int status = gsl_integration_qagi(&f,acc,eps,limit,workspace,&result,&error);

	gsl_integration_workspace_free(workspace);

	if(status != GSL_SUCCESS) {
		return NAN;
	} else {
		return result;
	}
}

double hamFun(double x, void * params) {
	double alpha = *(double*) params;
	return ( -pow(alpha*x,2)/2 + alpha/2 + pow(x,2)/2 ) * exp( -alpha*pow(x,2) );
}

double hamInteg(double alpha) {
	gsl_function f;
	f.function = &hamFun;
	f.params = (void*)&alpha;

	int limit = 100;
	double acc = 1e-6, eps = 1e-6, result, error;
	gsl_integration_workspace * workspace
		= gsl_integration_workspace_alloc(limit);

	int status = gsl_integration_qagi(&f,acc,eps,limit,workspace,&result,&error);

	gsl_integration_workspace_free(workspace);

	if(status != GSL_SUCCESS) {
		return NAN;
	} else {
		return result;
	}
}

int main(void) {
	printf("alpha \t E\n");
	for(double alpha = 0.1; alpha <= 2; alpha = alpha + 0.05) {
		double E = hamInteg(alpha)/normInteg(alpha);
		printf("%g \t %g\n",alpha,E);
	}
}
