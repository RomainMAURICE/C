#include "jeux.h"
#include "../game_design/affichage.h"

#include <MLV/MLV_all.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h> 

/* normal round */
void game(Board game_board, Board initial_board){
	add_new_val(game_board, initial_board);
	MLV_actualise_window();
}

/* add new val on board */ /* !!!!!!! */
void add_new_val(Board game_board, Board initial_board){	
	
	/* initialisation variable */
	Position resp;
	Position board;
	int val;
	
	/* emplacement de la valeur qu'on veut rentrer */
	MLV_wait_mouse(NULL, NULL);
	board = mouse_position_to_board(); 
	
	/*
	if(check_click_in_board(board)==0){
		return;
	}*/
	
	/* emplacement de la valeur */
	MLV_wait_mouse(NULL, NULL);
	resp = mouse_position_to_board();
	val = val_of_case(resp.column, resp.line);
	
	/* if on peut modifier cette valeur */
	if(initial_board[board.column-1][board.line-1] == 0){
		/* if la valeur respecte les règle du sudoku */
		if(check_value(game_board, board.column -1, board.line - 1, val)){
			/* if la grille est vide a cette emplacement */
			if(game_board[board.column-1][board.line-1] == 0){
				draw_new_number(board.column, board.line, val);
				game_board[board.column-1][board.line-1] = val;
			}/* fin if la grille est vide a cette emplacement */
			/* esle il y a déjà une valeur à cette emplacement */
			else{			
				rase_a_number(board.line, board.column);
				draw_new_number(board.column, board.line, val);
				game_board[board.column-1][board.line-1] = val;
			}/* fin esle il y a déjà une valeur à cette emplacement */
		}/* fin if la valeur respecte les règle du sudoku */
	}/* fin if on peut modifier cette valeur */
	/* else on sort de la fonction */
	else{
		return;
	}/* fin else on sort de la fonction */
	return;
}

/* user click to position in board */
Position mouse_position_to_board(){
	
	int x, y;
	Position current;
	MLV_get_mouse_position( &x, &y );

	x = (x - SQUARES_SIZE) % WINDOW_WIDTH / 75 + 1;
	y = (y - SQUARES_SIZE) % WINDOW_HEIGHT / 75 + 1;
	
	current.line = x;
	current.column = y;
	
	return current;	
}

/* position in board to pixel */
/*
void board_to_pixel(Position current){

	int x, y;
	x = current.line * SQUARES_SIZE;
	y = current.column * SQUARES_SIZE;
	
	current.line = x;
	current.column = y;
}*/

/* get value of choice board */
int val_of_case(int l, int c){

	if( l == 1 && c == 14)
		return 1;
	
	if( l == 1 && c == 15)
		return 2;
		
	if( l == 1 && c == 16)
		return 3;
		
	if( l == 2 && c == 14)
		return 4;
		
	if( l == 2 && c == 15)
		return 5;
		
	if( l == 2 && c == 16)
		return 6;
		
	if( l == 3 && c == 14)
		return 7;
		
	if( l == 3 && c == 15)
		return 8;
		
	if( l == 3 && c == 16)
		return 9;
		
	return 0;


}

/* check the user val is valid (from tp 6) */
int check_value(Board game_board, int ligne, int colone, int solution){
    int i = 0;
    
    /* Vérifie que la valeur est seulement une fois dans la ligne ou la colone */
    for(i = 0; i < 9; i++){
        if(game_board[i][colone] == solution)
            return 0;
        
        if(game_board[ligne][i] == solution)
            return 0;
            
    }
      
    int ligne_start = (ligne/3)*3;
    int colone_start = (colone/3)*3;
    
    /* Vérifie que la valeur est seulement une fois dans la zone sous-grille de la grille */
    for(i = 0; i < 3; i++){
    
        if(game_board[ligne_start + i][colone_start] == solution)
            return 0;
            
        if(game_board[ligne_start + i][colone_start + 1] == solution)
            return 0;

        if(game_board[ligne_start + i][colone_start + 2] == solution)
            return 0;
    }

    return 1;
}

/* check if the board is full */
int grid_is_valid(Board game_board){
    int c, l;

    for(c = 0; c < 9; c++){
        for(l = 0; l < 9; l++){
            if(game_board[c][l]==0){
                return 0;
            }
        }
    }

    return 1; 
}

/*
int check_click_in_board(Position current){

	printf("in line : %d , column : %d \n",current.line, current.column);

	if(current.line <= 1 && current.line <= 9){
		if(current.column <= 1 && current.column <= 9){
			return 1;
		}
	}
	return 0;
}*/










