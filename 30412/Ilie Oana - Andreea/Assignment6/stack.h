//
// Created by andre on 06.05.2020.
//

#ifndef ASSIGNMENT6_STACK_H
#define ASSIGNMENT6_STACK_H

#include "node.h"

void push(int content);

void pop();

NodeT *peekStack();

int isEmptyStack();

NodeT *stack;

#endif //ASSIGNMENT6_STACK_H
