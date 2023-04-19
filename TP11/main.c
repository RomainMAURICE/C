#include "jeu.h"
#include <stdlib.h>
#include <stdio.h>
#include <MLV/MLV_all.h>

int main(int argc, char **argv) {
    //initialise quit et key_quit
    int quit=-1;
    MLV_Keyboard_button key_quit = MLV_KEYBOARD_UNKNOWN;

    //variable correpondants a la case vides, vont être ammené a changer
    int case_vide_x = 3;
    int case_vide_y = 3;

    //création de la fenêtre
    MLV_create_window("Taquin", "Taquin", NB_COL * CELL_SIZE, NB_LIG * CELL_SIZE);

    //création du plateau et du fond
    Plateau *plateau = (Plateau*) calloc(NB_COL * NB_LIG, sizeof(Carre));
    InitialiseationPlateau(plateau);
    MLV_Image* fond = MLV_load_image("fond.png");

    while (quit == -1) {

        afficher_grille(fond, plateau);
        MLV_actualise_window();

        //on récupere le prochain évenement
	    MLV_Mouse_button mouse_button;
        MLV_Event event = MLV_get_event(				
                &key_quit,
				NULL,
				NULL,
				NULL,
				NULL,
				NULL,
				NULL,
				&mouse_button,
				NULL);

        if (event == MLV_MOUSE_BUTTON || event == MLV_MOUSE_BUTTON) {

            int mouse_x, mouse_y;
            MLV_wait_mouse(&mouse_x, &mouse_y);
            int x = mouse_x / CELL_SIZE;        //on récupere sur quelle case on a cliquer
            int y = mouse_y / CELL_SIZE;

            if (x >= 0 && y >= 0 && x < NB_COL && y < NB_LIG) { //si on clique quand la fenêtre

                //si on clique sur une case valide (haut bas gauche droite) dans la fenêtre
                if ((x == case_vide_x - 1 && y == case_vide_y) || (x == case_vide_x + 1 && y == case_vide_y) || (x == case_vide_x && y == case_vide_y - 1) || (x == case_vide_x && y == case_vide_y + 1)) {
                    echange(plateau, x, y, case_vide_x, case_vide_y);
                    case_vide_x = x;
                    case_vide_y = y;
                }
            }
        }
        if(event == MLV_KEY && key_quit == MLV_KEYBOARD_q) { //si on appuie sur q ferme le jeu (buggé, marche que si on ne clique jamais)
           
            quit = 1;
            
        }

        
    }
    MLV_wait_seconds(2);
    MLV_free_window();
    return 0;
}