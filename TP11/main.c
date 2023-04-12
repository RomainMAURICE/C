#include <MLV/MLV_all.h>
#define NB_COL 4
#define NB_LIG 4


typedef struct carre{
    int lig;
    int col;
}Carre;

typedef struct plateau{
    Carre bloc[NB_COL][NB_LIG];
}Plateau;

void InitialisationPlateau(Plateau* P){
    int i,j;

    for(i=0;i<NB_LIG;i++){
        for(j=0;j<NB_COL;j++){
            ((P->bloc)[i][j]).lig=i;
            ((P->bloc)[i][j]).lig=j;
        }
    }
}

int main(int argc, char const *argv[])
{
    Plateau plateau;
    
    MLV_create_window( "Taquin", "oui", 640, 480 );

    MLV_actualise_window();
    MLV_wait_seconds( 10 );
    MLV_free_window();

    return 0;
}


//drawPartialImage()MLV