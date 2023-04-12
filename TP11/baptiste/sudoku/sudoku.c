#include <stdio.h>
#include <MLV/MLV_all.h>

#include "in_out.h"

void initialize_empty_board(Board grid){
    int i;
    int j;
    for(i = 0; i<9; i++){
        for(j = 0; j<9; j++){
            grid[i][j]=0;
        }
    }
}

void print_board(Board grid){
    MLV_create_window("Sudoku", "grille", 1550, HEIGHT);
    afficher_plateau(grid);
}

int isFinished(Board grid){
    int i;
    int j;
    for (i = 0; i < 9; i++){
        for (j = 0; j < 9; j++){
            if (grid[i][j] == 0)
                return 0;
        }
    }
    return 1;
}

int get_coord_case(int x, int isChoice){
    int size = SIZE_SQUARE;
    int nb_case = -1;
    if (!isChoice && x<50 + size*9 && x > 50)
        nb_case = (x-50)/size;
    else if (isChoice && x >= size * 10){
        nb_case = (x-size*10)/size;
    }
    else if (isChoice && x > size*4 && x < size*7)
        nb_case = (x-size*4)/size;
    return nb_case;
}


void click(Board grid, int x, int y){
    int i = get_coord_case(x, 0);
    int j = get_coord_case(y, 0);
    if (i != -1 && i < 9  && j != -1 && j < 9) {
        show_choice_grid(grid, i, j);
    }
    else { 
        MLV_wait_mouse(&x, &y);
        click(grid, x, y);
    }
}

int choice_grid(){
    int x;
    int y;
    MLV_wait_mouse(&x, &y);
    int i = get_coord_case(x, 1);
    int j = get_coord_case(y, 1);
    if (i != -1 && j != -1)
        return 3*j+i+1;
    return choice_grid();

}

int isAffectable(Board grid, int value, int x, int y){
    int i;
    int j;
    for (j = 0; j < 9; j++){
        if (grid[x][j] == value)
            return 0;
    }
    for (i = 0; i < 9; i++){
        if (grid[i][y] == value)
            return 0;
    }
    int square_x = x/3;
    int square_y = y/3;

    for (i = 0; i < 3; i++){
        for (j = 0; j < 3; j++){
            if (grid[i+3*square_x][j+3*square_y] == value)
                return 0;
        }
    }
    return 1;
}