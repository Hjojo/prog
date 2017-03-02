CFLAGS := -Wall -std=gnu99
LDLIBS := -lm
.PHONEY: all stdio cmdline clean

all : cmdlineplot.pdf

stdio : outstdio.txt
	cat $<

outstdio.txt : main-stdio in.dat
	./$< < $(word 2,$^) > $@


cmdline : outcmdline.txt
	cat $<

cmdlineplot.pdf : cmdplot.gpi outcmdline.txt
	gnuplot cmdplot.gpi

outcmdline.txt : main-cmdline in.dat
	./$< `cat $(word 2,$^)` > $@

in.dat : Makefile
	cat /dev/null > $@
	for x in `seq 0 0.1 10`; do echo $$x >> $@; done


clean:
	$(RM) main-stdio main-stdio.o outstdio.txt \
		main-cmdline main-cmdline.o outcmdline.txt \
		cmdlineplot.pdf
