#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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


Cell* allocate_cell(char* first, char* last, int age){
    Cell* cell = (Cell*) malloc(sizeof(Cell));
    cell->first_name = malloc(sizeof(char)*(strlen(first) + 1));
    cell->last_name = malloc(sizeof(char)*(strlen(last) + 1));
    strcpy(cell->first_name, first);
    strcpy(cell->last_name, last);
    cell->age=age;
    return cell;
}


int age_order(Cell* p1, Cell* p2){
    if(p1->age > p2->age){
        return 1;
    }
    else if(p1->age < p2->age){
        return -1;
    }
    return 0;
}

int name_order(Cell* p1, Cell* p2){
    int cmp=strcmp(p1->last_name, p2->last_name);
    if(cmp==0){
        cmp=strcmp(p1->first_name, p2->first_name);
    }
    return cmp;
}


void ordered_insertion(List* l, Cell* new, int order_func(Cell*, Cell*)){
    Cell* cell = *l;
    Cell* pre = NULL;
    while(cell!=NULL && order_func(cell, new)<0){
        pre = cell;
        cell = cell->next;
    }
    if(pre!=NULL){
        new->next=cell;
        pre->next=new;
    }
    else{
        new->next=*l;
        *l=new;
    }
}


void print_list(List l){
    Cell* cell = l;
    while(cell!=NULL){
        printf("%s ", cell->first_name);
        printf("%s ", cell->last_name);
        printf("%d\n", cell->age);
        cell=cell->next;
    }
}

void free_list(List l){
    Cell* cell = l;
    Cell* tmp;
    while(cell!=NULL){
        tmp=cell;
        cell=cell->next;
        free(tmp->first_name);
        free(tmp->last_name);
        free(tmp);
    }
}


int main(int argc, char const *argv[])
{
    FILE *f = fopen(argv[1]/*"liste_nom.txt"*/, "r");
    if (f == NULL ){ fprintf(f,"can't open file %s", argv[1]/*"liste_nom.txt"*/); exit(1);}

    List list = NULL;
    char* prenom;
    char* nom;
    int age;
    while(fscanf(f,"%s %s %d", prenom, nom, &age)==3){
        ordered_insertion(&list, allocate_cell(prenom, nom, age), name_order);
        /*ordered_insertion(&list, allocate_cell(prenom, nom, age), age_order);*/
    }

    print_list(list);

    free_list(list);

    fclose(f);

    return 0;
}
