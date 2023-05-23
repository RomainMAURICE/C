#include <stdlib.h>
#include <stdio.h>
#include <MLV/MLV_all.h>
#include "jeu.h"


void couleurPlateau(){
    int a,b;
    int white=1;
    for(a=0; a<NB_COL; a++){

        if(white) white=0;
        else white=1;

        for(b=0; b<NB_LIG; b++){
            if(white){
                MLV_draw_filled_rectangle(a * CELL_SIZE, b * CELL_SIZE, CELL_SIZE, CELL_SIZE, MLV_COLOR_GREY);
                white=0;
            }else {
                MLV_draw_filled_rectangle(a * CELL_SIZE, b * CELL_SIZE, CELL_SIZE, CELL_SIZE, MLV_COLOR_BLACK);
                white=1;
            }
        }
    }
}

int numCase(int x, int y){
    return 63 - (y * NB_COL + x);
}

void propagation(unsigned long int plateau, int position, int x, int y){

}