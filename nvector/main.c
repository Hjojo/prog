#include <stdio.h>
#include "nvector.h"
#include "stdlib.h"
#define RND (double)rand()/RAND_MAX

int main() {

	int n = 3;

	printf("\nmain: testing nvector_alloc ...\n");
	nvector* v = nvector_alloc(n);
	if(v == NULL) {
		printf("test failed\n");
	} else {
		printf("test succeeded\n");
	}

	printf("\nmain: testing nvector_set ang get ...\n");
	nvector_set(v,2,42);
	double v_2nd_element = nvector_get(v,2);
	if( v_2nd_element == 42) {
		printf("test succeeded\n");
	} else {
		printf("test failed\n");
	}

	printf("\nmain: testing nvector_dot_product ...\n");
	nvector* a = nvector_alloc(n);
	nvector* b = nvector_alloc(n);
	double dotShouldBeResult = 0;
	for(int i = 0; i<n; i++) {
		double x = RND, y = RND;
		nvector_set(a,i,x);
		nvector_set(b,i,y);
		dotShouldBeResult += x*y;
	}
	double dotProduct = nvector_dot_product(a,b);
	if( dotProduct == dotShouldBeResult ) {
		printf("test succeeded\n");
	} else {
		printf("test failed\n");
	}

	nvector_free(v); v = NULL;
	nvector_free(a); a = NULL;
	nvector_free(b); b = NULL;

	return 0;
}
