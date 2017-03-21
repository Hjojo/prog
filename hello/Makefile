CFLAGS := -Wall -std=gnu99
.PHONEY: all clean

all: output.txt
	cat $<

output.txt: hello
	./$< > $@

clean:
	$(RM) hello hello.o output.txt
