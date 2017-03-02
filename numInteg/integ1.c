#include <stdio.h>
#include <gsl/gsl_integration.h>
#include <math.h>
#include <gsl/gsl_errno.h>

double simpleInteg(double x, void * params) {
	return log(x)/sqrt(x);
}

double integrationFun() {
	gsl_function f;
	f.function = simpleInteg;
	f.params = NULL;

	int limit = 100, key = 4;
	double a = 0, b = 1, acc = 1e-6, eps = 1e-6, result, err;
	gsl_integration_workspace * workspace
		= gsl_integration_workspace_alloc(limit);

	int status = gsl_integration_qag(&f,a,b,acc,eps,limit,key,workspace,&result,&err);

	gsl_integration_workspace_free(workspace);

	if(status != GSL_SUCCESS) {
		return NAN;
	} else {
		return result;
	}
}

int main(void) {
	double intValue = integrationFun();
	printf("Value of int_a^b dx (ln(x)/sqrt(x)): %g\n",intValue);
	printf("Real value: %g\n",-4.0);
}
