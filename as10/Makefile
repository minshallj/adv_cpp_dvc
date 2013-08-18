CC=g++
CFLAGS=-c -Wall -g

all: link

link: link_list.o
	$(CC) link_list.o -o link_list
link_list.o: link_list.cpp
	$(CC) $(CFLAGS) link_list.cpp
clean:
	rm -rf link_list.o link_list
