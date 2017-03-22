CFLAGS := -Wall -std=gnu99 $$(gsl-config --cflags)
LDLIBS := $$(gsl-config --libs)
.PHONEY: all clean

all: outArctan.txt report.pdf plotMin.pdf


report.pdf: report.tex
	pdflatex $<
	pdflatex $<


outArctan.txt outLog.txt: main
	./$< 1>> $@ 2>> outLog.txt

main: main.o numArctan.o equal.o


plotMin.pdf: plotMin.gpi outMini32.txt
	gnuplot $<

outMini32.txt logMini32.txt: mini32
	./$< 1>> $@ 2>> logMini32.txt


clean:
	$(RM) *.o *.txt *.pdf *.aux *.log main mini32
