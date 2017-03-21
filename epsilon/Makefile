CFLAGS = -std=gnu99 -Wall
.PHONEY: default clean

default: output.txt
	cat $<

output.txt: main
	./$< > $@

main: main.o epsilon.o sum_way.o equal.o

main.o: epsilon.h sum_way.h equal.h

epsilon.o: epsilon.h

sum_way.o: sum_way.h

equal.o: equal.h

clean:
	$(RM) main *.o *.txt
