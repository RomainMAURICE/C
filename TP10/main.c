#include <stdio.h>
#include <stdlib.h>

void swap_mem(void* z1, void* z2, size_t size){
    char* x = (char*) z1;
    char* y = (char*) z2;
    char tmp;

    int i;
    for(i=0;i<size;i++){
        tmp=x[i];
        x[i]=y[i];
        y[i]=tmp;
    }
}

int str_cmp(char *p, char *q){//est ce que 2 chaines sont égales
    while (*p++==*q++);
    return *q-*p;
}

typedef struct cell{
    char* first_name;
    char* last_name;
    int age ;
    struct cell* next ;
}Cell, *List;


/*Cell* allocate_cell(char* first, char* last, int age){
    Cell* cell = malloc(sizeof(Cell));
    cell->first_name = malloc(sizeof(char)*(strlen(first) + 1));
    cell->last_name = malloc(sizeof(char)*(strlen(last) + 1));
    call->age = malloc(sizeof(int));
}

int age_order(Cell* p1, Cell* p2){

}

int name_order(Cell* p1, Cell* p2){

}

void ordered_insertion(List* l, Cell* new, int order_func(Cell*, Cell*)){

}

void print_list(List l){
    while(l!=NULL){
        printf("%s ", l->first_name);
        printf("%s ", l->last_name);
        printf("%d\n", l->age);
        l=l->next;
    }
}

void free_list(List l){
    while(l!=NULL){
        free(l->first_name);
        free(l->last_name);
        free(l);
        l=l->next;
    }
}*/


int main(int argc, char const *argv[])
{
    FILE *f = fopen("liste_nom.txt", "r");
    if (f == NULL ){ fprintf(f,"can't open file %s", argv[1]); exit(1);}

    Cell c;
    
    char line[50];
    while (fgets(line, 50, f) != NULL) {
        printf("%s", line);

        int prenomParse=strtok(line, " ");
        int nomParse=strtok(NULL, " ");
        int ageParse=strtok(NULL, " ");

        printf("%s\n", prenomParse);
        printf("%s\n", nomParse);
        printf("%s\n", ageParse);
    }

    // Fermeture du fichier
    fclose(f);

    return 0;
}
