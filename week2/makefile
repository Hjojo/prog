CFLAGS = -std=gnu99 -Wall
.PHONEY: default clean

default: out.txt besAndj0

out.txt: complex
	./complex -> out.txt

complex: complex.c
	cc $(CFLAGS) complex.c -o complex

besAndj0: besAndj0.c
	cc $(CFLAGS) besAndj0.c -o besAndj0

clean:
	$(RM) complex out.txt besAndj0
