#include <stdio.h>

int main(int argc, char* argv[]){

    int nombre1=0;
    int i;

    printf("entrez un nombre \n");
    scanf("%d", &nombre1);

    for(i=nombre1; i>0; i--){
        printf("%d",i);
        printf("\n");        
    }

    for(i=1; i<nombre1+1; i++){
        printf("%d",i);
        printf("\n");
    }

    return 0;
}