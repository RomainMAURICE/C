#ifndef __SUDOKU__
#define __SUDOKU__

#define HEIGHT 1000
#define WIDTH 1000
#define NB_SQUARE 9
#define MARGIN 50
#define SIZE_SQUARE (HEIGHT - 2*MARGIN)/NB_SQUARE

typedef int Board[9][9];

int isFinished(Board grid);
void initialize_empty_board(Board grid);
void print_board(Board grid);
void click(Board grid, int x, int y);
int choice_grid();
int get_coord_case(int x, int isChoice);
int isAffectable(Board grid, int value, int x, int y);

#endif
