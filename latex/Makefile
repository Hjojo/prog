CFLAGS := -Wall -std=gnu99 $$(gsl-config --cflags)
LDLIBS := $$(gsl-config --libs)

.PHONEY: clean

report.pdf: report.tex plotErrorFun.pdf
	pdflatex $<
	pdflatex $<

plotErrorFun.pdf: plotErrorFun.gpi output.txt
	gnuplot $<

output.txt: errorFun
	./$< -3 3 0.05 > $@

clean:
	$(RM) *.o *.txt errorFun *.pdf *.aux *.log
