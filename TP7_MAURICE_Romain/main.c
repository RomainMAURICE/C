#include <stdio.h>
#include "graphique.c"

int main(int argc, char* argv[]){
    MLV_create_window( "sudoku", "sudoku", 1200, 800 );
    MLV_clear_window(0x000000FF);
    affiche_grille();
    MLV_wait_seconds( 10 );
        return 1;
}