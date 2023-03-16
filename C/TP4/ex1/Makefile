# Makefile TP 4 IR1/IG1

CC=gcc
CFLAGS=-Wall
OBJ=stack.o main.o
EXEC=main

all: $(OBJ)
	$(CC) -o $(EXEC) $(OBJ)

stack.o: stack.c stack.h
	$(CC) -c stack.c -o stack.o $(CFLAGS)

main.o: main.c stack.h
	$(CC) -c main.c -o main.o $(CFLAGS)


clean:
	rm -f *.o
	rm -f calc
	rm -f *~
