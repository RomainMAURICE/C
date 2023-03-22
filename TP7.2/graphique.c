#include <stdio.h>
#include <MLV/MLV_all.h>
#define WIDTH 600
#define HEIGHT 600


void affiche_grille(){
    int x=10;
    int y=50;
    int nb_sqr = 9;
    int i;
    int y;
    for (i=0; i<nb_sqr; i++){
        for (y=0; y<nb_sqr; y++){
            MLV_draw_rectangle(x, y, WIDTH/nb_sqr, HEIGHT/nb_sqr, MLV_COLOR_WHITE );
        }
    }
    MLV_actualise_window();
}

int main(int argc, char* argv[]){
    MLV_create_window( "sudoku", "sudoku", 1200, 800 );
    MLV_clear_window(0x000000FF);
    affiche_grille();
    MLV_wait_seconds( 10 );
        return 1;
}