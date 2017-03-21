CFLAGS := -Wall -std=gnu99 $$(gsl-config --cflags)
LDLIBS := $$(gsl-config --libs)
.PHONEY: all rosen clean

all: rosen plotHydrogen.pdf

rosen: outRosen.txt
	cat $<

outRosen.txt logRosen.txt: rosenbrock
	./$< 1>> $@ 2>> logRosen.txt

plotHydrogen.pdf: plotHydrogen.gpi outHydrogen.txt
	gnuplot $<

outHydrogen.txt logHydrogen.txt: shootHydrogen
	./$< 8 1>> $@ 2>> logHydrogen.txt

clean:
	$(RM) *.o *.txt *.pdf rosenbrock shootHydrogen
