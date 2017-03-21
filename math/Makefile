CFLAGS = -std=gnu99 -Wall
.PHONEY: default clean

default: outC.txt outGandB.txt outSig.txt
	cat outC.txt
	cat outGandB.txt
	cat outSig.txt

outC.txt: complex
	./complex -> outC.txt

complex: complex.c
	cc $(CFLAGS) complex.c -o complex


outGandB.txt: gammaAndBes
	./$< > $@

gammaAndBes: gammaAndBes.c
	cc $(CFLAGS) gammaAndBes.c -o gammaAndBes

outSig.txt: significant
	./$< > $@

clean:
	$(RM) complex gammaAndBes significant \
		*.txt *.o
