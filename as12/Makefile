CC=g++
CFLAGS=-c -Wall -g

all: main

main: driver.o Float_array.o
	$(CC) driver.o Float_array.o -o program

driver.o: driver.cpp
	$(CC) $(CFLAGS) driver.cpp

Float_array.o: Float_array.cpp Float_array.h
	$(CC) $(CFLAGS) Float_array.cpp

clean:
	rm -rf *.o program
