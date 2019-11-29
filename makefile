CC = gcc
CFLAGS = -Wall -g -fPIC
DEPS = myBank.h

%.o: %.c $(DEPS)
	$(CC) -c $< $(CFLAGS)

all: mybanks mybankd mains maind 
mybanks: myBank.o
	ar rcs libmyBank.a myBank.o

mybankd: myBank.o
	$(CC) -fPIC -shared -o libmyBank.so myBank.o 

mains: libmyBank.a main.c
	$(CC) -c -Wall main.c
	$(CC) -o mains main.o libmyBank.a

maind: libmyBank.so main.c
	$(CC) -c -Wall main.c 
	$(CC) -o maind main.o libmyBank.so

.PHONY: clean

clean:
	rm -f *.o *.a *.so *.out mains maind