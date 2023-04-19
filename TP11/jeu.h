#include <MLV/MLV_all.h>

#define NB_COL 4
#define NB_LIG 4
#define CELL_SIZE 100

typedef struct carre{
    int lig;
    int col;
}Carre;

typedef struct plateau{
    Carre bloc[NB_COL][NB_LIG];
}Plateau;


//initialise le plateau
void InitialiseationPlateau(Plateau *P);

//affiche le plateau
void afficher_grille(MLV_Image* fond, Plateau *P);

//echange deux cases du plateau
void echange(Plateau *P, int x1, int y1, int x2, int y2);