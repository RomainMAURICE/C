#include <MLV/MLV_all.h>

#include "src/game_design/affichage.h"
#include "src/game_play/jeux.h"
#include "src/game_design/in_out.h"


int main(int argc, char* argv[]){

	/* Game board initialisation */
	Board game_board;
	Board initial_board;
	fread_board(argv[1], game_board);
	fread_board(argv[1], initial_board);
    
    
    MLV_create_window_with_default_font("SUDOKU TP7", NULL, WINDOW_WIDTH, WINDOW_HEIGHT, "asset/Moon_Dance/MoonDance-Regular.ttf", 30);
	create_board(game_board);
	
	while(1){
	game(game_board, initial_board);
	if (grid_is_valid(game_board) == 1)
		break;
	}
	
	victory();
	MLV_wait_mouse(NULL, NULL);
	MLV_free_window();
    return 0;
}
