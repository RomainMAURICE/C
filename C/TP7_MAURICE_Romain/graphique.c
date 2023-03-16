#include <stdio.h>
#include <MLV/MLV_all.h>
#define WIDTH 600
#define HEIGHT 600


void affiche_grille(){
    int x=10;
    int y=50;
    int nb_sqr = 9;
    int i;
    int j;
    for (i=0; i<nb_sqr; i++){
        for (j=0; j<nb_sqr; j++){
            MLV_draw_rectangle(x, y, WIDTH/nb_sqr, HEIGHT/nb_sqr, MLV_COLOR_WHITE );
            x=x+65;
        }
        y=y+65;
        x=10;
    }
    MLV_actualise_window();
}

void print_grid(Board board) {
    int i;
    int j;
    char buffer[5];
    for (i = 0; i<9; i++){
        for (j=0; j<9; j++) {
            if (board[i][j]!= 0) {
                sprintf(buffer,"%d", board[i][j]);
                MLV_draw_text_with_font(MARGIN+SIZE_SQUARE/3+SIZE_SQUAREi, MARGIN+SIZE_SQUARE/4+SIZE_SQUAREj, buffer, FONT, MLV_COLOR_WHITE);
            }
        }
    }
    MLV_actualise_window();
}

void afficher_plateau(Board board){
    int i;
    int j;
    for (i=0; i<9; i++){
        for (j=0; j<9; j++){
            draw_rectangle(MARGIN+SIZE_SQUAREi, MARGIN+SIZE_SQUAREj, MARGIN+SIZE_SQUARE(i+1), MARGIN+SIZE_SQUARE(j+1));
        }
    }
    MLV_actualise_window();
    print_grid(board);
}