#include <stdio.h>
#include <MLV/MLV_all.h>
#include "sudoku.h"
#include "in_out.h"

int main(int argc, char* argv[]){
  Board B;

  fread_board(argv[1], B);

  print_board(B);
  int x;
  int y;
  int choice;
  while(!isFinished(B)){
    MLV_wait_mouse(&x, &y);
    click(B, x, y);
  }
  return 0;
}
