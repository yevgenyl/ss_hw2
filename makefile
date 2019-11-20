CC = gcc
CFLAGS = -Wall -g
DEPS = myBank.h

%.o: %.c $(DEPS)
	$(CC) -c $< $(CFLAGS)

all: mybanks mybankd mains maind 
mybanks: myBank.o
	ar rcs libmyBank.a myBank.o

mybankd: myBank.o
	$(CC) -fPIC -shared -o libmyBank.so myBank.o 

mains: mybanks main.c
	$(CC) -c -Wall main.c
	$(CC) -o mains main.o libmyBank.a

maind: mybankd main.c
	$(CC) -c -Wall main.c 
	$(CC) -o maind main.o libmyBank.so

.PHONY: clean

clean:
	rm -f *.o *.a *.so *.out mains maind