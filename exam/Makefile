CFLAGS := -Wall -std=gnu99 $$(gsl-config --cflags)
LDLIBS := $$(gsl-config --libs)
.PHONEY: clean

report.pdf: report.tex plotArctan.pdf
	pdflatex $<
	pdflatex $<


plotArctan.pdf: plotArctan.gpi outArctan.txt
	gnuplot $<

outArctan.txt outLog.txt: main
	./$< 1> $@ 2> outLog.txt

main: main.o numArctan.o equal.o


clean:
	$(RM) *.o *.txt *.pdf *.aux *.log main
