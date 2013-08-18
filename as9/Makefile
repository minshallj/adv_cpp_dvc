CC=g++
CFLAGS=-c -Wall -g

all: binaryio enc_dec

binaryio: binaryio.o
	$(CC) binaryio.o -o binaryio
binaryio.o: binaryio.cpp
	$(CC) $(CFLAGS) binaryio.cpp

enc_dec: enc_dec.o
	$(CC) enc_dec.o -o enc_dec
enc_dec.o: enc_dec.cpp
	$(CC) $(CFLAGS) enc_dec.cpp

clean:
	rm -rf binaryio.o enc_dec.o binaryio enc_dec
