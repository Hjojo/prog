#include <gsl/gsl_integration.h>
#include <gsl/gsl_errno.h>
#include <math.h>

double arctanInteg(double x, void *params) {
	return 1/(x*x+1);
}

double numArctan(double x) {
	if(x == 0) return 0;
	if(x < 0) return -numArctan(-x);
	if(x > 1) return M_PI/2 - numArctan(1/x);

	gsl_function f;
	f.function = arctanInteg;
	f.params = NULL;

	size_t limit = 100;
	int key = 4;
	double a = 0, epsabs = 1e-6, epsrel = 1e-6, result, error;
	gsl_integration_workspace *workspace =
		gsl_integration_workspace_alloc(limit);

	int status = gsl_integration_qag(&f,a,x,epsabs,epsrel,limit,key,workspace,&result,&error);

	gsl_integration_workspace_free(workspace);

	if(status != GSL_SUCCESS) {
		return NAN;
	} else {
		return result;
	}
}
