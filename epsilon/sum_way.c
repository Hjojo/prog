#include <stdio.h>
#include <limits.h>
#include <float.h>

const int MAX = INT_MAX/2;
float sum_up_float() {
	float sum_float = 0.0f;
	for(int i = 1; i<=MAX; i++) {
		sum_float += 1.0f/i;
	}
	return sum_float;
}

float sum_down_float() {
	float sum_float = 0.0f;
	for(int i = MAX; i>0; i--) {
		sum_float += 1.0f/i;
	}
	return sum_float;
}

double sum_up_double() {
	double sum_double = 0.0;
	for(int i = 1; i<=MAX; i++) {
		sum_double += 1.0/i;
	}
	return sum_double;
}

double sum_down_double() {
	double sum_double = 0.0;
	for(int i = MAX; i>0; i--) {
		sum_double += 1.0/i;
	}
	return sum_double;
}
