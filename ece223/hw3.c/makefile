# The makefile for HW3
CC	= gcc
CFLAGS	= -Wall -g
LFLAGS	=

queue: queue.o
	$(CC) $(CFLAGS) -o queue queue.o

queue.o: queue.c queue.h
	$(CC) $(CFLAGS) -c queue.c

.PHONY: clean
clean:
	rm	-f	queue.o	queue
