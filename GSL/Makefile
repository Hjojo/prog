CFLAGS := -Wall -std=gnu99 `gsl-config --cflags`
LDLIBS := `gsl-config --libs`
.PHONEY: all clean

all : out.txt
	cat $<

out.txt : eigenvalues
	./$< > $@

clean :
	$(RM) eigenvalues eigenvalues.o out.txt
