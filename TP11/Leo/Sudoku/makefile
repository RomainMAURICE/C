GD=src/game_design/
GP=src/game_play/
CC=gcc
CFLAGS=-Wall -ansi
LDFLAGS=-lMLV
OBJ=main.o $(GD)affichage.o $(GP)jeux.o $(GD)in_out.o

sudoku: $(OBJ)
	$(CC) -o main $(OBJ) $(CFLAGS) $(LDFLAGS)

main.o: main.c 
	$(CC) -c main.c $(CFLAGS) $(LDFLAGS)
	
affichage.o: affichage.c
	$(CC) -c src/game_design/affichage.c $(CFLAGS) $(LDFLAGS)
	
jeux.o: jeux.c
	$(CC) -c src/game_play/jeux.c $(CFLAGS) $(LDFLAGS)
	
in_out.o: in_out.c
	$(CC) -c src/game_design/in_out.c $(CFLAGS) $(LDFLAGS)
	
clean: 
	rm -f $(GP)*.o
	rm -f $(GD)*.o
	rm -f *.o
	rm -f *~
	rm -f main
