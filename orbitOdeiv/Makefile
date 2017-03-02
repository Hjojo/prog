CFLAGS := -Wall -std=gnu99 `gsl-config --cflags`
LDLIBS := `gsl-config --libs`
.PHONEY = all clean

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
	$(RM) outY.txt yDiffEq.o yDiffEq \
		outOrbit.txt orbit.o orbit \
		plotY.pdf plotOrbit.pdf
