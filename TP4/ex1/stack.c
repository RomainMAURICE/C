#include "stack.h"
#include <stdio.h>
#include <stdlib.h>

static Stack stack;

void stack_init(){
    stack.size = 0;
}

int stack_size(){
    return stack.size;
}

int stack_is_empty(){
    if(stack.size == 0){
        return 1;
    }
    else
    {
        return 0;
    }
}

int stack_top(){
    return stack.values[stack.size];
}

int stack_pop(){
    int pop = stack.values [stack.size];
    stack.size--;
    return pop;
}

void stack_push(int n){
    stack.values[stack.size] = n;
    stack.size++;
}

void stack_display(void){
    int i;
    for(i=0; i<stack.size ; i++){
        printf("%d", stack.values[i]);
        printf("\n");

    }
}

int stack_get_element(int index){

    return stack.values[index];
}