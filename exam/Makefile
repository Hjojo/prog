CFLAGS := -Wall -std=gnu99 $$(gsl-config --cflags)
LDLIBS := $$(gsl-config --libs)
.PHONEY: all clean

all: outArctan.txt
	cat $<

outArctan.txt: main
	./$< > $@

main: main.o numArctan.o

clean:
	$(RM) *.o *.txt *.pdf *.aux *.log
