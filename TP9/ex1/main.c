#include <stdio.h>
#include <stdlib.h>

int main (int argc, char* argv[]){
    int i;
    int size=atoi(argv[1]);

    int* t;
    t=(int*)malloc(size * sizeof(int));

    for(i=0; i<size; i++){
        t[i]=i+1;
        printf("%d ", t[i]);
    }

    free(t);

    return 0;

}