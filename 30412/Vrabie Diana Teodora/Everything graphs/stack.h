//
// Created by diana on 10/05/2020.
//

#ifndef EVERYTHING_GRAPHS_STACK_H
#define EVERYTHING_GRAPHS_STACK_H

#include <stdbool.h>
#include <stdlib.h>

typedef struct _stackNode {
    int value;
    struct _stackNode *next;
} StackNode;

typedef struct _stack {
    StackNode *first;
} Stack;

Stack *initializeStack();

void push(StackNode *node, Stack *stack);

StackNode *pop(Stack *stack);

bool isEmpty(Stack *stack);



#endif //EVERYTHING_GRAPHS_STACK_H
