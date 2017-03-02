#include <stdio.h>
#include <gsl/gsl_matrix.h>
#include <gsl/gsl_eigen.h>
#include <gsl/gsl_vector.h>
#include <math.h>

int main(void) {

	int n = 20;
	double s = 1.0/(n+1);
	gsl_matrix * H = gsl_matrix_calloc(n,n);

	for(int i = 0; i<n-1; i++) {
		gsl_matrix_set(H,i,i,-2);
		gsl_matrix_set(H,i,i+1,1);
		gsl_matrix_set(H,i+1,i,1);
	}
	gsl_matrix_set(H,n-1,n-1,-2);
	gsl_matrix_scale(H,-1/s/s);

	fprintf(stderr,"(%d,%d) element of m: %g\n",4,4,gsl_matrix_get(H,4,4));
	fprintf(stderr,"Should be: %g\n",-1/s/s*(-2));


	gsl_eigen_symmv_workspace * w = gsl_eigen_symmv_alloc(n);
	gsl_vector * eval = gsl_vector_alloc(n);
	gsl_matrix * evec = gsl_matrix_alloc(n,n);
	gsl_eigen_symmv(H,eval,evec,w);

	gsl_eigen_symmv_sort(eval,evec,GSL_EIGEN_SORT_VAL_ASC);


	fprintf(stderr, "i\t exact\t calculated\n");
	for(int k = 0; k<n/3; k++) {
		double exact = M_PI*M_PI*(k+1)*(k+1);
		double calculated = gsl_vector_get(eval,k);
		fprintf(stderr, "%i\t %g\t %g\n",k,exact,calculated);
	}

	for(int k = 0; k<3; k++) {
		printf("%i \t %f \n",0,0.0);
		for(int i = 0; i<n; i++) {
			printf("%g \t %f \n",(i+1.0),gsl_matrix_get(evec,i,k));
		}
		printf("%i \t %f \n",n+1,0.0);
		printf("\n\n");
	}

	gsl_matrix_free(H);
	gsl_eigen_symmv_free(w);
	gsl_vector_free(eval);
	gsl_matrix_free(evec);
	return 0;
}
