#include <stdio.h>

int main(int argc, char* argv[]){

    int nombre1=0;
    int nombre2=0;
    int resultat=0;

    printf("entrez un nombre \n");
    scanf("%d", &nombre1);

    printf("entrez un deuxième nombre \n");
    scanf("%d", &nombre2);

    resultat=nombre1+nombre2;

    printf("%d",resultat);
    printf("\n");

    return 0;
}