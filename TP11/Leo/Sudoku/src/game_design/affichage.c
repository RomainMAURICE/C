#include "affichage.h"
#include "in_out.h"
#include "../game_play/jeux.h"

#include <MLV/MLV_all.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void create_board(Board game_board){
	draw_game_board(); 
	initialize_game_board(game_board);
	draw_choice_board();
	initialize_choice_board();
	MLV_actualise_window();
}

/* draw only the game board */
void draw_game_board(){
	
	int c, l, x, y = SQUARES_SIZE;
	
	/* draw colum */
	for( c = 1; c <= NB_SQUARES; c++){
	
		/* draw line */
		for( l = 1; l <= NB_SQUARES; l++ ){
			x =  SQUARES_SIZE * l;
			MLV_draw_rectangle(x , y , SQUARES_SIZE, SQUARES_SIZE, MLV_COLOR_BLUE);
		}/* end draw line */
		
		y += SQUARES_SIZE;
	}/* end draw colum */

}

/* drow only the number choice board */
void draw_choice_board(){

	int c, l, x, y = SQUARES_SIZE;
	
	/* draw colum */
	for( c = 1; c <= 3; c++){
		/* draw line */
		for( l = 1; l <= 3; l++ ){
			x =  WINDOW_WIDTH - (SQUARES_SIZE * (l + 3));
			MLV_draw_rectangle(x , y , SQUARES_SIZE, SQUARES_SIZE, MLV_COLOR_BLUE);
		}/* end draw line */
		
		y += SQUARES_SIZE;
	}
}

/* drow a new number after the user add a number */
void draw_new_number(int column, int line, int val){

	int x, y;
	char str[3];
	
	x = line * SQUARES_SIZE + SQUARES_SIZE / 2;
	y = column * SQUARES_SIZE + SQUARES_SIZE / 2;

	sprintf(str, "%d", val);
	MLV_draw_text(x, y - 25, str, MLV_COLOR_GREEN);
}

/* rase a number */
void rase_a_number(int x, int y){
	x = x * SQUARES_SIZE + 20;
	y = y  * SQUARES_SIZE + 20;
				
	MLV_draw_filled_rectangle(x, y, SQUARES_SIZE - 30, SQUARES_SIZE - 30, MLV_COLOR_BLACK );
}
/* add the number on the game board */
void initialize_game_board(Board game_board){

	int c, l, x, y = SQUARES_SIZE + (SQUARES_SIZE/2) - 20;
	char str[3];
	
	/* draw colum */
	for( c = 1; c <= NB_SQUARES; c++){
	
		/* draw line */
		for( l=1; l <= NB_SQUARES; l++ ){
			
			if (game_board[c-1][l-1] == 0)
				continue;
			else{
				x =  SQUARES_SIZE * l + (SQUARES_SIZE/2) - 10;
				sprintf(str, "%d", game_board[c-1][l-1]);
				MLV_draw_text(x, y, str, MLV_COLOR_RED);
			}
		}/* end draw line */
		
		y += SQUARES_SIZE;
	}/* end draw colum */
}

/* add the number on the choice board */
void initialize_choice_board(){
	
	int c, l, x, y = SQUARES_SIZE + (SQUARES_SIZE/2) - 25;
	int val[3][3] = {{3, 2, 1},
		 	{6, 5, 4},
		 	{9, 8, 7}};
	char str[10];
	
	/* draw colum */
	for( c = 1; c <= 3; c++){
		/* draw line */
		for( l = 1; l <= 3; l++ ){
			x =  WINDOW_WIDTH - (SQUARES_SIZE * (l + 2) + (SQUARES_SIZE/2) + 10);
			sprintf(str, "%d", val[c-1][l-1]);
			MLV_draw_text(x, y, str, MLV_COLOR_WHITE);
		}/* end draw line */
		
		y += SQUARES_SIZE;
	}/* end draw colum */
}

/* victory message */
void victory(){
	char *str = " VOUS AVEZ GAGNEZ !";
	MLV_draw_text( 800, 800, str, MLV_COLOR_RED);
	printf("! BRAVO C'EST GAGNER !\n");
	MLV_actualise_window();
}

/* DEBUG */
/* print the board on a terminal (from tp 6) */
void print_board(Board game_board){
    int i, e;

    for(i=0; i<9; i++){
        printf("-------------------------------------\n");
        for(e=0; e<9; e++){
            if(game_board[i][e]==0 && e==0){
                printf("|   |");
            }
            else if(game_board[i][e]==0){
                printf("   |");
            }
            else if(e == 0){
                printf("| %d |",game_board[i][e]);
            }
            else{
                printf(" %d |",game_board[i][e]);
            }
        }
        printf("\n");
    }
    printf("-------------------------------------\n");
}














