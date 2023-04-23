#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef struct node {
    char *word;
    struct node *next;
}Node, *List;

void initListe(){
    
}

int main(int argc, char const *argv[])
{
    FILE *f = fopen("Germinal.txt","r");
    if (f == NULL ){ fprintf(f,"can't open file %s", "Germinal.txt"); exit(1);}
    
    //Node *node = (Node*) malloc(sizeof(node));

    char mot[100];
    int nbrMot=0;
    List list;

    while (fscanf(f, "%s", mot)==1){
        List *list = (List*) malloc(sizeof(list));
        Node *node = (Node*) malloc(sizeof(node));
        node->word = mot;
        node->next = NULL;



        printf("%s ", mot);
        nbrMot++;
    }
    printf("%d", nbrMot);


    return 0;
}
