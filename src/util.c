#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "../include/util.h"


void stack(struct t_stack_top *top, int y, int x){
    struct t_stack *element = malloc(sizeof(int)*2+sizeof(int*));
    element->x=x;
    element->y=y;
    element->next=top->stack;
    top->stack=element;
}
void unstack(struct t_stack_top *top){
    struct t_stack *element;
    element = top->stack;
    top->stack = top->stack->next;
    free(element);
}

int random_number(int min, int max){
    return (rand() % (max + 1 - min )) + min;
}