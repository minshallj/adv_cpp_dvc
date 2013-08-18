CC=g++
CFLAGS=-c -Wall -g

all: gcf pal

gcf: gcf.o
	$(CC) gcf.o -o gcf
gcf.o: gcf.cpp
	$(CC) $(CFLAGS) gcf.cpp
pal: pal.o
	$(CC) pal.o -o pal
pal.o: pal.cpp
	$(CC) $(CFLAGS) pal.cpp
clean:
	rm -rf gcf.o gcf pal.o pal
