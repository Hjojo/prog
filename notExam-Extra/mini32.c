#include <stdio.h>
#include <gsl/gsl_min.h>
#include <gsl/gsl_errno.h>

double funToMin(double x, void *params) {
	return (x*x-0.5*x)/2;
}

int main() {
	const gsl_min_fminimizer_type *T =
		gsl_min_fminimizer_brent;
	gsl_min_fminimizer *s = gsl_min_fminimizer_alloc(T);

	gsl_function F;
	F.function = &funToMin;
	F.params = NULL;

	double m = 0.1, a = 0.001, b = 1;
	gsl_min_fminimizer_set(s,&F,m,a,b);


	int status;
	int iter = 0, maxIter = 1000;
	fprintf(stderr,"iter \t x\n");
	fprintf(stderr,"%d \t %g\n",iter,m);
	do {
		iter++;
		status = gsl_min_fminimizer_iterate(s);

		m = gsl_min_fminimizer_x_minimum(s);
		a = gsl_min_fminimizer_x_lower(s);
		b = gsl_min_fminimizer_x_upper(s);

		status = gsl_min_test_interval(a,b,1e-6,1e-6);

		if(status == GSL_SUCCESS) {
			fprintf(stderr,"Converged:\n");
		}
		fprintf(stderr,"%d \t %g\n",iter,m);
	} while(status == GSL_CONTINUE && iter < maxIter);

	printf("# x \t f(x)\n");
	for(double x = -1; x<=2; x+=0.01) {
		printf("%g \t %g\n",x,funToMin(x,NULL));
	}
	printf("\n\n");

	double minFx = gsl_min_fminimizer_f_minimum(s);
	printf("# xmin \t f(xmin)\n");
	printf("%g \t %g\n",m,minFx);


	gsl_min_fminimizer_free(s);

	return 0;
}
