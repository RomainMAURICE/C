CC=gcc
CFLAGS=-Wall -lMLV
OBJ=plateau.o jeu.o main.o
EXEC=main

all: $(OBJ)
		$(CC) -o $(EXEC) $(OBJ)

plateau.o: plateau.c plateau.h
		$(CC) -c plateau.c -o plateau.o $(CFLAGS)

jeu.o: jeu.c jeu.h
		$(CC) -c jeu.c -o jeu.o $(CFLAGS)

main.o: main.c plateau.h jeu.h
		$(CC) -c main.c -o main.o $(CFLAGS)