#ifndef ADJACENCY_STACK_H

#include "node.h"

NodeT *stack;

void push(int content);

void pop();

NodeT *peekStack();

int isEmptyStack();

#define ADJACENCY_STACK_H

#endif