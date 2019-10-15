# The makefile for HW3
CC	= gcc
CFLAGS	= -Wall -g

queue: queue.o	queuetest.o
	$(CC) $(CFLAGS) queue.o	queuetest.o	-o queue

queue.o: queue.c queue.h
	$(CC) $(CFLAGS) -c queue.c

.PHONY: clean
clean:
	rm	-f	queuetest.o	queue.o	queue
