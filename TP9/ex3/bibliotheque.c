#include "bibliotheque.h"
#include <stdio.h>
#include <stdlib.h>

void freeMalloc(int nbParam, char** tab){
    int i;
    for(i=0; i<nbParam; i++){
        free(tab[i]);
    }
    free(tab);
}

void printTab(int nbParam, char** tab){
    int i;
    for(i=0; i<nbParam; i++){
        printf("%s ", tab[i]);
        printf("\n");
    }
}