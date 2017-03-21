CFLAGS := -Wall -std=gnu99
LDLIBS := -lm
.PHONEY: all stdio cmdline clean

all: cmdplot.pdf stdioplot.pdf

stdio: outstdio.txt
	cat $<

stdioplot.pdf: stdioplot.gpi outstdio.txt
	gnuplot $<

outstdio.txt: main-stdio in.txt
	./$< < $(word 2,$^) > $@



cmdline: outcmdline.txt
	cat $<

cmdplot.pdf: cmdplot.gpi outcmdline.txt
	gnuplot $<

outcmdline.txt: main-cmdline in.txt
	./$< `cat $(word 2,$^)` > $@

in.txt: Makefile
	cat /dev/null > $@
	for x in `seq 0 0.1 10`; do echo $$x >> $@; done


clean:
	$(RM) main-stdio main-cmdline *.o *.txt *.pdf
