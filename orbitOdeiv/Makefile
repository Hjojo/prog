CFLAGS := -Wall -std=gnu99 `gsl-config --cflags`
LDLIBS := `gsl-config --libs`
.PHONEY: all clean

all: plotY.pdf plotOrbit.pdf

plotY.pdf: plotY.gpi outY.txt
	gnuplot plotY.gpi

outY.txt: yDiffEq
	./$< > $@

plotOrbit.pdf: plotOrbit.gpi outOrbit.txt
	gnuplot plotOrbit.gpi

outOrbit.txt: orbit
	./$< > $@

clean:
	$(RM) *.txt *.o yDiffEq orbit *.pdf
