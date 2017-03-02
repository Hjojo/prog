CFLAGS = -std=gnu99 -Wall
.PHONEY: default clean

default: main.o epsilon.o sum_way.o equal.o
	cc main.o epsilon.o sum_way.o equal.o -o main

main.o: main.c epsilon.h sum_way.h equal.h
	cc -c $(CFLAGS) main.c

epsilon.o: epsilon.c
	cc -c $(CFLAGS) epsilon.c

sum_way.o: sum_way.c
	cc -c $(CFLAGS) sum_way.c

equal.o: equal.c
	cc -c $(CFLAGS) equal.c

clean:
	$(RM) main main.o epsilon.o sum_way.o equal.o
