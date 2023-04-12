#ifndef JEUX_H
#define JEUX_H

#include "../game_design/affichage.h"

/* position on the board */
typedef struct {
	int line;
	int column;
}Position;

typedef int Board[9][9];

/* game */
/* normal round */
void game(Board game_board, Board initial_board);
/* add new val on board */ 
void add_new_val(Board game_board, Board initial_board);
/* get value of choice board */
int val_of_case(int l, int c);

/* make convertion */
/* user click to position in board */
Position mouse_position_to_board();

/* check rule */
/* check the user val is valid (from tp 6) */
int check_value(Board game_board, int ligne, int colone, int solution);
/* check if the board is full */
int grid_is_valid(Board game_board);
/* check if the click is on the board */
int check_click_in_board(Position current);

#endif /* JEUX_H */
