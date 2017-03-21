#include <stdio.h>
#include <gsl/gsl_linalg.h>

int main(void) {
	const int N = 3;

	double aData[] = { 6.13, -2.90, 5.86,
			   8.08, -6.31, -3.89,
			   -4.36, 1.00, 0.19 };

	double bData[] = {6.23, 5.37, 2.29};

	gsl_matrix_view m = gsl_matrix_view_array(aData,N,N);

	gsl_vector_view b = gsl_vector_view_array(bData,N);

	gsl_vector *x = gsl_vector_alloc(N);

	int s;

	gsl_permutation * p = gsl_permutation_alloc(N);

	gsl_linalg_LU_decomp(&m.matrix,p,&s);

	gsl_linalg_LU_solve(&m.matrix,p,&b.vector,x);

	printf("x = \n");
	gsl_vector_fprintf(stdout,x,"%g");

	gsl_permutation_free(p);
	gsl_vector_free(x);
	return 0;
}
