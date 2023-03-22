#include <stdio.h>
#include "sudoku.h"
#include <MLV/MLV_all.h>

/* void initialize_empty_board(Board grid){
 }*/


/*
void print_board(Board grid){
    int i;
    int j;
    printf("-------------------------------------\n");
    for ( i = 0; i < 9; i++)
    {
        for ( j = 0; j < 9; j++)
        {
            printf("| %d ", grid[i][j]);
        }
        printf("|");
        printf("\n");
        printf("-------------------------------------\n");
    }
    
}
*/


int test_box(Board grid, int l, int c, int var){
    int i;
    int min_l, max_l, min_c, max_c;
    int j;

    if (l/3 < 1)
    {
        min_l = 0;
        max_l = 2;
    }
    else if (l/3 < 2)
    {
        min_l = 3;
        max_l = 5;
    }
    else
    {
        min_l = 6;
        max_l = 8;
    }

    if (c/3 < 1)
    {
        min_c = 0;
        max_c = 2;
    }
    else if (c/3 < 2)
    {
        min_c = 3;
        max_c = 5;
    }
    else
    {
        min_c = 6;
        max_c = 8;
    }
    
    for (i = min_l; i < max_l; i++)
    {
        for (j = min_c; j < max_c; j++)
        {
            if (grid[i][j] == var)
            {
                return 0;
            }
            
        }
        
    }
    
    return 1;
}

int test_line(Board grid, int l, int c, int var){
    int i;
    for ( i = 0; i < 9; i++)
    {
        if (grid[l][i] == var)
        {
            return 0;
        }
    }
    return 1;
}

int test_colonne(Board grid, int l, int c, int var){
    int i;
    for ( i = 0; i < 9; i++)
    {
        if (grid[i][c] == var)
        {
            return 0;
        }
    }
    return 1;
}

/*
void print_perm(int *tab)
{
    int i;
    printf("[ ");
    for (i = 0; i < SIZE; i++)
        printf(" %d ", tab[i]);
    printf(" ]\n");
}

void permutation(int tab[], int current){

    int i;
    if (current > 8)
    {
        print_perm(tab);
    }
    else
    {
        for (i = 0; i <8; i++)
        {
            if (tab[i] == 0)
            {
                tab[i] == current;
                permutation(tab, current + 1)
                tab[i] = 0;
            }
            
        }
        
    }
    
}*/


/*
int sudoku_solver(Board grid, int line, int column){
    int i;
    if (line > 8)
    {
        print_board(grid);
        return 1;
    }
    if (grid[line][column] != 0)
    {
        if (column == 8)
        {
            return sudoku_solver(grid, line + 1, 0);
        }
        else
        {
            return sudoku_solver(grid, line, column + 1);
        }
    }

    for (i = 1; i < 10; i++)
    {
        
        if (test_box(grid, line, column, i) && test_colonne(grid, line, column, i) && test_line(grid, line, column, i))
        {
            grid[line][column] = i;
            if (column == 8 && sudoku_solver(grid, line + 1, 0))
            {
                return 1;
            }
            else if (sudoku_solver(grid, line, column + 1))
            {
                return 1;
            }
        }
    }
    grid[line][column] = 0;
    print_board(grid);
    return 0;
}
*/