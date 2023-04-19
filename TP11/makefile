CC=gcc
CFLAGS=-Wall
LDFLAGS= -lMLV
OBJ=jeu.o main.o
EXEC=main

all: $(OBJ)
		$(CC) -o $(EXEC) $(OBJ) $(LDFLAGS)

jeu.o: jeu.c jeu.h
		$(CC) -c jeu.c -o jeu.o $(CFLAGS) $(LDFLAGS)

main.o: main.c jeu.h
		$(CC) -c main.c -o main.o $(CFLAGS) $(LDFLAGS)