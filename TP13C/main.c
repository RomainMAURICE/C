#include "jeu.h"
#include <stdio.h>
#include <MLV/MLV_all.h>
#include <unistd.h>



int bit_value_ULI(unsigned long int n, int position){
    return (n&((unsigned long int)1<<position)) ? 1:0;

}

void print_ULI(unsigned long int n) {
    unsigned int CHAR_BIT = sizeof(n) * 8;
    unsigned int i;
    for (i = CHAR_BIT - 1; i < CHAR_BIT; i--) {
        printf("%c", (n & ((unsigned long int)1 << i)) ? '1' : '0');
        if ((i % 8 == 0) && (i != 0)) {
            printf("\n");
        }
    }
    printf("\n");
}


int isFull(unsigned long int n) {
    unsigned int CHAR_BIT = sizeof(n) * 8;
    unsigned int i;
    int full=0;
    for (i = CHAR_BIT - 1; i < CHAR_BIT; i--) {
        if(n & ((unsigned long int)1 << i)){
            full++;
        }    
    }
    return full>NB_CASES;
}

void set_positive_bit_ULI(unsigned long int* n, int position){
    *n = (*n)|((unsigned long int)1 << position);
}

void set_negative_bit_ULI(unsigned long int* n, int position){
    *n = (*n)&~(1 << position);
}

int main(int argc, char const *argv[])
{
    unsigned long int plateau;

    int click=0;
    
    int quit=-1;
    MLV_Keyboard_button key_quit = MLV_KEYBOARD_UNKNOWN;

    MLV_create_window("Dames", "dames", NB_COL * CELL_SIZE, NB_LIG * CELL_SIZE);

    couleurPlateau();


    while (quit == -1) {

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

            if (x >= 0 && y >= 0 && x < NB_COL && y < NB_LIG) { //si on clique dans la fenêtre

                int position = numCase(x,y);

                if(bit_value_ULI(plateau, position)){
                    printf("la case est déjà prise \n");
                }
                else{
                    printf("dame posée \n");
                    MLV_draw_filled_rectangle(x * CELL_SIZE, y * CELL_SIZE, CELL_SIZE, CELL_SIZE, MLV_COLOR_RED);
                    set_positive_bit_ULI(&plateau, position);
                    click++;

                    int tmpHaut = position;
                    int tmpYHaut = y;
                    while(tmpHaut<=NB_CASES){//passage à 1 en haut de la dame
                        tmpHaut = tmpHaut+8;
                        tmpYHaut--;
                        set_positive_bit_ULI(&plateau, tmpHaut);
                        //MLV_draw_filled_rectangle(x * CELL_SIZE, tmpYHaut * CELL_SIZE, CELL_SIZE, CELL_SIZE, MLV_COLOR_RED);
                    }

                    int tmpBas = position;
                    int tmpYBas = y;
                    while(tmpBas>=0){//passage à 1 en bas de la dame
                        tmpBas = tmpBas-8;
                        tmpYBas++;
                        set_positive_bit_ULI(&plateau, tmpBas);
                        //MLV_draw_filled_rectangle(x * CELL_SIZE, tmpYBas * CELL_SIZE, CELL_SIZE, CELL_SIZE, MLV_COLOR_RED);
                    }

                    int tmpGauche = position;
                    int tmpXGauche = x;
                    while(tmpGauche/8==position/8){//passage à 1 à gauche de la dame
                        set_positive_bit_ULI(&plateau, tmpGauche);
                        //MLV_draw_filled_rectangle(tmpXGauche * CELL_SIZE, y * CELL_SIZE, CELL_SIZE, CELL_SIZE, MLV_COLOR_RED);
                        tmpGauche++;
                        tmpXGauche--;
                    }

                    int tmpDroite = position;
                    int tmpXDroite = x;
                    while(tmpDroite/8==position/8 && tmpDroite>=0){//passage à 1 à droite de la dame
                        set_positive_bit_ULI(&plateau, tmpDroite);
                        //MLV_draw_filled_rectangle(tmpXDroite * CELL_SIZE, y * CELL_SIZE, CELL_SIZE, CELL_SIZE, MLV_COLOR_RED);
                        tmpDroite--;
                        tmpXDroite++;      
                    }
//-------------------------------------------------------diagonales-----------------------------------------------------------------------
                    int tmpDiagHautDroite = position;
                    int tmpXDiagHautDroite = x;
                    int tmpYDiagHautDroite = y;
                    while (tmpDiagHautDroite <= NB_CASES && tmpXDiagHautDroite < NB_COL - 1 && tmpYDiagHautDroite > 0) {
                        tmpDiagHautDroite = tmpDiagHautDroite + 7;
                        tmpXDiagHautDroite++;
                        tmpYDiagHautDroite--;
                        set_positive_bit_ULI(&plateau, tmpDiagHautDroite);
                    }

                    int tmpDiagHautGauche = position;
                    int tmpXDiagHautGauche = x;
                    int tmpYDiagHautGauche = y;
                    while (tmpDiagHautGauche <= NB_CASES && tmpXDiagHautGauche > 0 && tmpYDiagHautGauche > 0) {
                        tmpDiagHautGauche = tmpDiagHautGauche + 9;
                        tmpXDiagHautGauche--;
                        tmpYDiagHautGauche--;
                        set_positive_bit_ULI(&plateau, tmpDiagHautGauche);
                    }

                    int tmpDiagBasGauche = position;
                    int tmpXDiagBasGauche = x;
                    int tmpYDiagBasGauche = y;
                    while (tmpDiagBasGauche >= 0 && tmpXDiagBasGauche > 0 && tmpYDiagBasGauche < NB_LIG - 1) {
                        tmpDiagBasGauche = tmpDiagBasGauche - 7;
                        tmpXDiagBasGauche--;
                        tmpYDiagBasGauche++;
                        set_positive_bit_ULI(&plateau, tmpDiagBasGauche);
                    }

                    int tmpDiagBasDroite = position;
                    int tmpXDiagBasDroite = x;
                    int tmpYDiagBasDroite = y;
                    while (tmpDiagBasDroite >= 0 && tmpXDiagBasDroite < NB_COL - 1 && tmpYDiagBasDroite < NB_LIG - 1) {
                        tmpDiagBasDroite = tmpDiagBasDroite - 9;
                        tmpXDiagBasDroite++;
                        tmpYDiagBasDroite++;
                        set_positive_bit_ULI(&plateau, tmpDiagBasDroite);
                    }


                    print_ULI(plateau);


                }
            }
        }

        if((event == MLV_KEY && key_quit == MLV_KEYBOARD_q)||(isFull(plateau))) {
           
            if(click==8){
                printf("Bravo, vous avez réussi à placer les 8 dames !\n");
            }
            else{
                printf("Perdu ! Vous n'avez réussi qu'à poser ");
                printf("%d", click);
                printf(" dames !\n");
            }
            
            quit = 1;
            
        }
    }    

    return 0;
}
