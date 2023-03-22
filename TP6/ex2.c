#include <stdio.h>
#include <string.h>
#define size 3

void affiche_tableau(int* tab){
    int i;
    for (i=0; i<size; i++){
        printf("%d", tab[i]);
    }
}

void permutation(int* buffer, int current, int max){

    affiche_tableau(buffer);
    printf("\n");
    int i;

    if(current>max){
    affiche_tableau(buffer);
    printf(" tableau complet");
    printf("\n");
    }

    for(i=0; i<max; i++){
        if(buffer[i] == 0){
            buffer[i]=current;
            permutation(buffer, current + 1, max);
            buffer[i]=0;
        }
    }
}

int main(int argc, char constargv[])
{
    int tab[3]={0,0,0};
    permutation(tab, 1, 3);
    return 0;
}   