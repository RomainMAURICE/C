#include <stdio.h>
#include <MLV/MLV_all.h>
#include "in_out.h"
#define FONT MLV_load_font("./batman_forever/batmfo__.ttf", 50)



void afficher_plateau(Board board);

void draw_rectangle(int x1, int y1, int x2, int y2);

void print_grid(Board board);

void show_choice_grid(Board board, int x, int y);