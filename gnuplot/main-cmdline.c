#include <stdio.h>
#include <math.h>
#include <tgmath.h>
#include <stdlib.h>

int main(int argc,char* argv[]) {
	for(int i = 1; i<argc; i++) {
		double currNumber = atof(argv[i]);
		printf("%lg\t%lg\n",currNumber,sin(currNumber));
	}

	return 0;
}
