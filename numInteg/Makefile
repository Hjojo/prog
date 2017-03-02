CFLAGS := -Wall -std=gnu99 $$(gsl-config --cflags)
LDLIBS := $$(gsl-config --libs)
.PHONEY = clean output1 all

all : output1 plot.pdf

output1 : out1.txt
	cat $<

out1.txt : integ1
	./$< > $@

plot.pdf : plot.gpi outHam.txt
	gnuplot $<

outHam.txt : integHam
	./$< > $@


clean:
	$(RM) integ1 integ1.o out1.txt \
		integHam integHam.o plot.pdf
