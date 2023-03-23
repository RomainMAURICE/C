#include <stdio.h>
#include <stdlib.h>

int main (int argc, char* argv[]){
    int i;
    int j;
    int** t;
    int sizeY=atoi(argv[1]);
    int sizeX=atoi(argv[2]);

    t=(int**)malloc(sizeY * sizeof(int*));

    for(i=0; i<sizeY; i++){
        t[i]=(int*)malloc(sizeX * sizeof(int));
    }

    for(i=0; i<sizeY; i++){
        for(j=0; j<sizeX; j++){
            t[i][j]='a'+ (i+j) %26;

            printf("%c ", t[i][j]);
        }
        printf("\n");
    }

    for(i=0; i<sizeY; i++){
        free(t[i]);
    }
    free(t);

    return 0;

}