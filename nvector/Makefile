CFLAGS = -Wall -std=gnu99
LDLIBS = -lm
.PHONEY: all clean

all: out.txt
	cat $<

out.txt: main
	./$< > $@

main: main.o nvector.o

main.o nvector.o : nvector.h

clean:
	rm -f main *.o *.txt
