#include <stdio.h>
#include "stack.h"

int main (int argc, char* argv[]){

    stack_init();
    stack_push(3);
    //printf("%d", stack_size());
    stack_display();

}