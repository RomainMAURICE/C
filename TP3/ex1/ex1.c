#include <stdio.h>

int main (int argc, char* argv[]){
    if (argc > 1){
        int a = atoi(argv[1]);
        int n = atoi(argv[2]);

        carre(a,n);
    }

    return 0;
}

void carre(a,n){

    int resultat=a;
    int i;

    // for (i = 1; i < n; i++)
    // {
    //     resultat=resultat*a;
    //     printf("%d",resultat);
    //     printf("\n");
    // }

    resultat=resultat*a;
}