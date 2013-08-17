CC=g++
CFLAGS=-c -Wall -g
all: main

main: primes.o prime.o
	$(CC) primes.o prime.o -o primes
primes.o: primes.cpp prime.h
	$(CC) $(CFLAGS)  primes.cpp
prime.o: prime.cpp prime.h
	$(CC) $(CFLAGS) prime.cpp
clean:
	rm -rf *.o primes
