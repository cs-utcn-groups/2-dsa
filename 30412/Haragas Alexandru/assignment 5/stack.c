//
// Created by Alex on 04.04.2020.
//

#include "stack.h"


void initializeStack() {
    first = NULL;
}

void push(int x) {
    if (first == NULL) {
        first = (stack *) malloc(sizeof(stack));
        first->val = x;
        first->next = NULL;
    } else {
        stack *newElem = (stack *) malloc(sizeof(stack));
        newElem->val = x;
        newElem->next = first;
        first = newElem;
    }
}

int pop() {
    stack *copy = first;
    int v = copy->val;
    first = first->next;
    free(copy);
    return v;
}