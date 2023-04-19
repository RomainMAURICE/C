#include <stdlib.h>
#include <stdio.h>
#include <MLV/MLV_all.h>
#include "jeu.h"


void InitialiseationPlateau(Plateau *P) {
    int i, j;
    for (i = 0; i < NB_LIG; i++) {
        for (j = 0; j < NB_COL; j++) {
            P->bloc[j][i].col = j;
            P->bloc[j][i].lig = i;
        }
    }
}

void afficher_grille(MLV_Image* fond, Plateau *P) {

    int i, j;
    for (i = 0; i < NB_COL; i++) {
        for (j = 0; j < NB_LIG; j++) {

            if (P->bloc[i][j].col == 3 && P->bloc[i][j].lig == 3) {
                MLV_draw_filled_rectangle(j * CELL_SIZE, i * CELL_SIZE, CELL_SIZE, CELL_SIZE, MLV_COLOR_BLACK);
            } else {
                MLV_draw_partial_image(fond, j*CELL_SIZE, i*CELL_SIZE , CELL_SIZE, CELL_SIZE, j * CELL_SIZE, i * CELL_SIZE);
            }

        }
    }
}

void echange(Plateau *P, int x1, int y1, int x2, int y2) {
    Carre tmp = P->bloc[y1][x1];
    P->bloc[y1][x1] = P->bloc[y2][x2];
    P->bloc[y2][x2] = tmp;
}