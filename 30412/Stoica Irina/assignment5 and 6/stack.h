//
// Created by Irina on 18/05/2020.
//

#ifndef ASSIGNMENT5_STACK_H
#define ASSIGNMENT5_STACK_H

#include "node.h"

void push(int content);

void pop();

NodeT *peekStack();

int isEmptyStack();

NodeT *stack;

#endif //ASSIGNMENT5_STACK_H
