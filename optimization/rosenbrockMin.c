#include <stdio.h>
#include <math.h>
#include <gsl/gsl_errno.h>
#include <gsl/gsl_multimin.h>
#include <gsl/gsl_vector.h>

double rosenbrockFun(const gsl_vector * v, void * params) {
	double x, y;
	x = gsl_vector_get(v,0);
	y = gsl_vector_get(v,1);

	return pow(1-x,2)+100*pow(y-pow(x,2),2);
}

int main(void) {
	const gsl_multimin_fminimizer_type *T =
		gsl_multimin_fminimizer_nmsimplex2;
	gsl_multimin_fminimizer *s = NULL;
	gsl_vector *ss, *x;
	gsl_multimin_function fun;

	size_t iter = 0;
	int status;
	double size;

	x = gsl_vector_alloc(2);
	gsl_vector_set(x,0,2.0);
	gsl_vector_set(x,1,1.0);

	ss = gsl_vector_alloc(2);
	gsl_vector_set_all(ss,1.0);

	fun.n = 2;
	fun.f = rosenbrockFun;
	fun.params = NULL;

	s = gsl_multimin_fminimizer_alloc(T,2);
	gsl_multimin_fminimizer_set(s,&fun,x,ss);

	printf("iteration \t x \t y \t f \t size\n");
	do {
		iter++;
		status = gsl_multimin_fminimizer_iterate(s);

		if(status) {
			break;
		}

		size = gsl_multimin_fminimizer_size(s);
		status = gsl_multimin_test_size(size,1e-2);

		if(status == GSL_SUCCESS) {
			printf("converged to minimum at\n");
		}

		printf("%lu \t %.3g \t %.3g \t %.3g \t %.3g\n",
			iter,
			gsl_vector_get(s->x,0),
			gsl_vector_get(s->x,1),
			s->fval, size);
	} while(status == GSL_CONTINUE && iter < 100);

	gsl_vector_free(x);
	gsl_vector_free(ss);
	gsl_multimin_fminimizer_free(s);

	return status;
}
