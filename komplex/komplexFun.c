#include <stdio.h>
#include "komplexFun.h"

void komplex_set(komplex* z, double x, double y) {
	(*z).re = x;
	(*z).im = y;
}

komplex komplex_new(double x, double y) {
	komplex result = {x,y};
	return result;
}

komplex komplex_add(komplex a, komplex b) {
	komplex result = {a.re+b.re,a.im+b.im};
	return result;
}

komplex komplex_sub(komplex a, komplex b) {
	komplex result = {a.re-b.re,a.re-b.re};
	return result;
}

komplex komplex_conjugate(komplex z) {
	komplex result = {z.re,-z.re};
	return result;
}
