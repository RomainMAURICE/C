CC=gcc
CFLAGS=-Wall
OBJ=bibliotheque.o main.o
EXEC=main

all: $(OBJ)
		$(CC) -o $(EXEC) $(OBJ)

bibliotheque.o: bibliotheque.c bibliotheque.h
		$(CC) -c bibliotheque.c -o bibliotheque.o $(CFLAGS)

main.o: main.c bibliotheque.h
		$(CC) -c main.c -o main.o $(CFLAGS)