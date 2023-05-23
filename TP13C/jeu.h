#include <MLV/MLV_all.h>

#define NB_COL 8
#define NB_LIG 8
#define NB_CASES 63
#define CELL_SIZE 100

void couleurPlateau();

int numCase(int x, int y);

void propagation(unsigned long int plateau, int position, int x, int y);