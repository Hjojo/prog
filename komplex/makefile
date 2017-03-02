CFLAGS := -std=gnu99 -Wall
LDLIBS := -lm
.PHONEY: default clean

default: out.txt
	cat $<

out.txt: main
	./$< > $@

main: main.o komplexFun.o 

komplexFun.o main.o : komplexFun.h

clean:
	rm -f main main.o komplex.o
