CFLAGS := -Wall -std=gnu99 `gsl-config --cflags`
LDLIBS := `gsl-config --libs`
.PHONEY: all eigenval clean

all: plot.pdf eigenval

eigenval: outEigen.txt
	cat $<

outEigen.txt: eigenvalues
	./$< > $@


plot.pdf: plot.gpi outBox.txt
	gnuplot $<

outBox.txt logBox.txt: qpInBox
	./$< 1> $@ 2> logBox.txt

clean:
	$(RM) qpInBox eigenvalues *.o *.txt plot.pdf
