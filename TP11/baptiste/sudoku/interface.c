#include "interface.h"
#include <stdlib.h>


void afficher_plateau(Board board){
    int i;
    int j;
    for (i=0; i<9; i++){
        for (j=0; j<9; j++){
            draw_rectangle(MARGIN+SIZE_SQUARE*i, MARGIN+SIZE_SQUARE*j, MARGIN+SIZE_SQUARE*(i+1), MARGIN+SIZE_SQUARE*(j+1));
        }
    }
    MLV_actualise_window();
    print_grid(board);
}

void draw_rectangle(int x1, int y1, int x2, int y2) {
    MLV_draw_line(x1, y1, x1, y2, MLV_COLOR_WHITE);
    MLV_draw_line(x1, y2, x2, y2, MLV_COLOR_WHITE);
    MLV_draw_line(x2, y2, x2, y1, MLV_COLOR_WHITE);
    MLV_draw_line(x2, y1, x1, y1, MLV_COLOR_WHITE);
    MLV_draw_filled_rectangle(x1+1, y1+1, x2-x1-1, y2-y1-1, MLV_COLOR_BLACK);

}

void print_grid(Board board) {
    int i;
    int j;
    char buffer[5];
    for (i = 0; i<9; i++){
        for (j=0; j<9; j++) {
            if (board[i][j]!= 0) {
                sprintf(buffer,"%d", board[i][j]);
                MLV_draw_text_with_font(MARGIN+SIZE_SQUARE/3+SIZE_SQUARE*i, MARGIN+SIZE_SQUARE/4+SIZE_SQUARE*j, buffer, FONT, MLV_COLOR_WHITE);
            }
        }
    }
    MLV_actualise_window();
}

void show_choice_grid(Board grid, int x, int y){
    draw_rectangle(SIZE_SQUARE*10, SIZE_SQUARE*4, SIZE_SQUARE*13, SIZE_SQUARE*7);
    int i;
    int j;
    char buffer[5];
    for (i=0; i<3; i++){
        for (j=0; j<3; j++){
            draw_rectangle(SIZE_SQUARE*(i+10), SIZE_SQUARE*(j+4), SIZE_SQUARE*(i+11), SIZE_SQUARE*(j+5));
            if (isAffectable(grid, 3*j+i+1, x, y)){
                sprintf(buffer,"%d", 3*j+i+1);
                MLV_draw_text_with_font(SIZE_SQUARE/3+SIZE_SQUARE*(i+10), SIZE_SQUARE/4+SIZE_SQUARE*(j+4), buffer, FONT, MLV_COLOR_WHITE);
            }
        }
    }
    MLV_actualise_window();
    int choice = choice_grid();
    if (isAffectable(grid, choice, x, y))
        grid[x][y] = choice;
    else 
        grid[x][y] = 0;
    MLV_clear_window(MLV_COLOR_BLACK);
    afficher_plateau(grid);
    MLV_actualise_window();
}

