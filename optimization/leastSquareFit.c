#include <stdio.h>
#include <gsl/gsl_multimin.h>

struct experimentalData {int n; double *t, *y, *e;};

double deviationData(const gsl_vector *x, void *params) {
	double A = gsl_vector_get(x,0);
	double T = gsl_vector_get(x,1);
	double B = gsl_vector_get(x,2);

	struct experimentalData *p = (struct experimentalData*)params;
	int n = (*p).n;
	double *t = (*p).t;
	double *y = (*p).y;
	double *e = (*p).e;

	double sum = 0;
	#define model(t) A*exp(-(t)/T)+B
	for(int i = 0; i<n; i++) {
		sum += pow( (model(t[i])-y[i]) / e[i] ,2);
	}
	return sum;
}

int printState(int iter, gsl_multimin_fminimizer *state, int n) {
	fprintf(stderr,"iter = %d, A = %.3g, T = %.3g, B = %.3g, size = %.3g, fval/n = %.3g\n",
		iter,
		gsl_vector_get((*state).x,0),
		gsl_vector_get((*state).x,1),
		gsl_vector_get((*state).x,2),
		(*state).size,
		(*state).fval/n);
	return 0;
}

int main() {
	double t[]= {0.47,1.41,2.36,3.30,4.24,5.18,6.13,7.07,8.01,8.95};
	double y[]= {5.49,4.08,3.54,2.61,2.09,1.91,1.55,1.47,1.45,1.25};
	double e[]= {0.26,0.12,0.27,0.10,0.15,0.11,0.13,0.07,0.15,0.09};
	int n = sizeof(t)/sizeof(t[0]);

	fprintf(stderr,"Number of data points to fit to: %d\n",n);

	printf("# t \t y \t e\n");
	for(int i = 0; i<n; i++) {
		printf("%g \t %g \t %g\n",t[i],y[i],e[i]);
	}
	printf("\n\n");

	struct experimentalData params = {n,t,y,e};
	size_t dimension = 3;

	gsl_multimin_function F;
	F.f = deviationData;
	F.n = dimension;
	F.params = (void*)&params;

	gsl_vector *start = gsl_vector_alloc(dimension);
	gsl_vector_set(start,0,1);
	gsl_vector_set(start,1,1);
	gsl_vector_set(start,2,0);

	gsl_vector *step = gsl_vector_alloc(dimension);
	gsl_vector_set(step,0,1);
	gsl_vector_set(step,1,1);
	gsl_vector_set(step,2,1);

	gsl_multimin_fminimizer *state =
		gsl_multimin_fminimizer_alloc(gsl_multimin_fminimizer_nmsimplex2,dimension);
	gsl_multimin_fminimizer_set(state,&F,start,step);

	const int maxIter = 1000;
	int iter = 0, status;
	do {
		iter++;
		int iteration_status = gsl_multimin_fminimizer_iterate(state);
		if(iteration_status != 0) {
			fprintf(stderr,"can not improve\n");
			break;
		}

		double acc = 0.01;
		status = gsl_multimin_test_size((*state).size,acc);
		if(status == GSL_SUCCESS) {
			fprintf(stderr,"converged\n");
		}
		printState(iter,state,n);

	} while(status == GSL_CONTINUE && iter < maxIter);

	double A = gsl_vector_get((*state).x,0);
	double T = gsl_vector_get((*state).x,1);
	double B = gsl_vector_get((*state).x,2);

	printf("# t \t A*exp(-t/T)+B\n");
	double dt = (t[n-1]-t[0])/100;
	for(double ti = t[0]; ti<t[n-1]+dt; ti+=dt) {
		printf("%g \t %g\n",ti,A*exp(-ti/T)+B);
	}

	gsl_multimin_fminimizer_free(state);
	gsl_vector_free(start);
	gsl_vector_free(step);

	return 0;
}
