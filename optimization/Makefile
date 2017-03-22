CFLAGS := -Wall -std=gnu99 $$(gsl-config --cflags)
LDLIBS := $$(gsl-config --libs)
.PHONEY: all exercise1 clean

all: exercise1 plotLeastSquare.pdf

exercise1: output1.txt
	cat $<

output1.txt: rosenbrockMin
	./$< > $@


plotLeastSquare.pdf: plotLeastSquare.gpi outLeastSquare.txt
	gnuplot $<

outLeastSquare.txt logLeastSquare.txt: leastSquareFit
	./$< 1>> $@ 2>> logLeastSquare.txt


clean:
	$(RM) rosenbrockMin leastSquareFit *.o *.txt *.pdf
