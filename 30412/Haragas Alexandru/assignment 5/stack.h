//
// Created by Alex on 04.04.2020.
//

#ifndef ASSIGNMENT_5_STACK_H

#include <stdlib.h>

typedef struct elem {
    int val;
    struct elem *next;
} stack;

stack *first;

void initializeStack();

void push(int x);

int pop();

#define ASSIGNMENT_5_STACK_H

#endif //ASSIGNMENT_5_STACK_H
