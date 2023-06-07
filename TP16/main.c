#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>


int pille[100];
int top = -1;

void push(int values) {
    top++;
    pille[top] = values;
}

int pop() {
    int result = pille[top];
    top--;
    return result;
}

int evaluate_rpn(const char *calcul) {
    char *values;
    int x;
    int y;
    values = strtok((char *)calcul, " ");
    
    while (values != NULL) {
        if (isdigit(values[0])) {
            push(atoi(values));
        } else if (strlen(values) == 1 && !isdigit(values[0])) {
            char operator = values[0];
            y = pop();
            x = pop();
            
            switch (operator) {
                case '+':
                    push(x + y);
                    break;
                case '-':
                    push(x - y);
                    break;
                case '*':
                    push(x * y);
                    break;
                case '/':
                    push(x / y);
                    break;
                case '%':
                    push(x % y);
                    break;
                case '^':
                    int i;
                    int power = x;
                    for(i=0; i<y-1; i++){
                        x=x*power;
                        printf("%d\n", x);
                    }
                    push(x);
                    break;                    
                case 'q':
                    printf("fin du programme\n");
                    exit(1);
                case 'p':
                    printf("%d\n", pille[0]);
                    break;
                case 'c':
                    int j;
                    for (int j = 0; j <= top; j++) {
                        pille[j] = 0;
                    }
                    break;                              
                default:
                    printf("Erreur : valeur invalide.\n");
                    exit(1);
            }
        }
        
        values = strtok(NULL, " ");
    }
    
    return pop();
}

int main() {
    char calcul[100];

    while (1)
    {
        printf("Entrez un calcul en polonais inversée : ");
        fgets(calcul, 100, stdin);
        
        if (calcul[strlen(calcul) - 1] == '\n') {
            calcul[strlen(calcul) - 1] = '\0';
        }
        
        printf("Résultat : %d\n", evaluate_rpn(calcul));
    }    

    
    return 0;
}