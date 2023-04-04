#include <stdio.h>
//#include "bibliotheque.h"

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

int str_cmp(char *p, char *q){
    while (*p++==*q++);
    return *q-*p;
}

typedef struct cell{
    char* first_name;
    char* last_name;
    int age ;
    struct cell* next ;
}Cell, *List;


Cell* allocate_cell(char* first, char* last, int age){

}

int age_order(Cell* p1, Cell* p2){

}

int name_order(Cell* p1, Cell* p2){

}

void ordered_insertion(List* l, Cell* new, int order_func(Cell*, Cell*)){

}

void print_list(List l){
    while(l!=NULL){
        printf("%f ", l->first_name);
        printf("%f ", l->last_name);
        printf("%f\n", l->age);
        l=l->next;
    }
}

void free_list(List l){

}


int main(int argc, char const *argv[])
{
    List l;
    Cell* c;
    Cell c2;
    l->age;
    c->age;
    c2.age;
    



    /*FILE *f = fopen(argv[1], "r");

    if (f == NULL ){ fprintf(f,"can't open file %s", argv[1]); exit(1);}

    int i;
    //for(i=0;!=EOF;i++);

    printf("%d", i);*/


    return 0;
}
