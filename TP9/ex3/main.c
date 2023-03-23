#include "bibliotheque.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main (int argc, char* argv[]){

    int i;

    char** t;
    t=(char**)malloc(argc * sizeof(char*));

    for(i=0; i<argc; i++){
        t[i]=(char*)malloc((strlen(argv[i])+1) * sizeof(char));
        strcpy(t[i], argv[i]);
    }
    
    printTab(argc, t);

    freeMalloc(argc, t);

    return 0;
}