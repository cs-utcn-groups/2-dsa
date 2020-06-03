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

StackNode *createNewStackNode(int value);

Stack *initializeStack();

void push(int value, Stack *stack);

StackNode *pop(Stack *stack);

bool isStackEmpty(Stack *stack);



#endif //EVERYTHING_GRAPHS_STACK_H
