CFLAGS := -Wall -std=gnu99 $$(gsl-config --cflags)
LDLIBS := $$(gsl-config --libs)
.PHONEY: exercise1 clean

all: exercise1

exercise1: output1.txt
	cat $<

output1.txt: rosenbrockMin
	./$< > $@


clean:
	rosenbrockMin rosenbrockMin.o output1.txt
