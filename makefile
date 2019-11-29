CC = gcc
CFLAGS = -Wall -g
DEPS = myBank.h

%.o: %.c $(DEPS)
	$(CC) -c $< $(CFLAGS)

all: mybanks mains 
mybanks: myBank.o
	ar rcs libmyBank.a myBank.o

mains: libmyBank.a main.c
	$(CC) -c -Wall main.c
	$(CC) -o mains main.o libmyBank.a

.PHONY: clean

clean:
	rm -f *.o *.a *.so *.out mains
