#include <stdio.h>
#include <MLV/MLV_all.h>
#include "sudoku.h"
#include "in_out.h"

int main(int argc, char* argv[]){
  Board B;

  fread_board(argv[1], B);
  sudoku_solver(B, 0, 0);
  print_board(B);

  return 0;
}
