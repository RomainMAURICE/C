#ifndef AFFICHAGE_H
#define AFFICHAGE_H

#define NB_SQUARES 9 /* squares number of the board */
#define SQUARES_SIZE 75 /* size of a squares */
#define WINDOW_WIDTH 1500 /* largeur de la fenêtre */
#define WINDOW_HEIGHT 1000 /* longeur de la fenêtre */

#include"../game_play/jeux.h"

/* game board */
typedef int Board[9][9];

/* grafics part */
/* create the game */
void create_board(Board game_board); 
/* draw only the game board */
void draw_game_board();
/* drow only the number choice board */
void draw_choice_board();
/* drow a new number after the user add a number */
void draw_new_number(int column, int line, int val);
/* rase a number */
void rase_a_number(int x, int y);
/* add the number on the game board */
void initialize_game_board(Board game_board);
/* add the number on the choice board */
void initialize_choice_board();
/* victory message */
void victory();

/* DEBUG */
/* print the board on a terminal (from tp 6) */
void print_board(Board grid);

#endif /* AFFICHAGE_H */
