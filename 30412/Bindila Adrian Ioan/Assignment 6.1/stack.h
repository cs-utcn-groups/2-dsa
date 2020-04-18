//
// Created by bindi on 4/2/2020.
//

#ifndef ASSIGNMENT_5_1_STACK_H
#define ASSIGNMENT_5_1_STACK_H

#include "list.h"

list *stack;

void push(int data);

void pop(void);

list *peekStack();

int isEmptyStack();

#endif //ASSIGNMENT_5_1_STACK_H
