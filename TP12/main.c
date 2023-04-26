#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef struct node {
    char *word;
    struct node *next;
}Node, *List;

Node *insertFirst(Node *next, char *word){
    Node *node = malloc(sizeof(Node));
    node->word = malloc(strlen(word)+1);
    strcpy(node->word, word);
    node->next = next;
    return node;
}

int count(Node *node){
    int total=0;
    while(node){
        total++;
        node = node->next;
    }
    return total;
}

int search(Node *node, char *word){
    while(node){
        if(strcmp(node->word, word)==0){
            return 1;
        }
        node = node->next;
    }
    return 0;
}

void freeList(Node *node){
    while(node){
        Node *tmp = node;
        node = node->next;
        free(tmp->word);
        free(tmp);
    }
}


int main(int argc, char const *argv[])
{
    FILE *f = fopen("Germinal.txt","r");
    if (f == NULL ){ fprintf(f,"can't open file %s", "Germinal.txt"); exit(1);}
    
    char mot[100];
    int nbrTotalMots=0;
    Node *node = NULL;

    while (fscanf(f, "%s", mot)==1){
        if(!search(node, mot)){
            node = insertFirst(node, mot);
        }
        nbrTotalMots++;
    }

    int nbrMot=count(node);
    printf("Nombre de mots uniques : %d \n", nbrMot);
    printf("Nombre total de mots : %d \n", nbrTotalMots);

    freeList(node);

    /*time
    Nombre de mots uniques : 25353
    Nombre total de mots : 165960

    real    0m12.766s
    user    0m12.734s
    sys     0m0.016s
    */
    return 0;
}
