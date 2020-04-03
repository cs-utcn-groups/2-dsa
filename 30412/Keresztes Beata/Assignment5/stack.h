//
// Created by q on 4/2/2020.
//

#ifndef ASSIGNMENT5_STACK_H
#define ASSIGNMENT5_STACK_H

#include "node.h"

typedef struct stack{
    NodeT * top, * bottom;
}StackT;
// create empty stack
StackT * createStack();
/*
 * stack operations
 * * push
 * * pop
 */
void push(StackT * stack, int data);
int pop(StackT * stack);
// free the stack
void freeStack(StackT * stack);
// check is stack is empty
int isEmptyStack(StackT * stack);
#endif //ASSIGNMENT5_STACK_H
