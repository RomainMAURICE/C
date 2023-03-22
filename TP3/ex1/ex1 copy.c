#include <stdio.h>

    void carre(){

        int a=0;
        int n=0;
        int resultat=0;

        printf("entrez un nombre \n");
        scanf("%d", &a);

        printf("entrez son carré \n");
        scanf("%d", &n);

        resultat=a;

        int i;
        for (i = 1; i < n; i++)
        {
            resultat=resultat*a;
            printf("%d",resultat);
            printf("\n");
        }
    }

int main (int argc, char* argv[]){
    carre();
    return 0;
}