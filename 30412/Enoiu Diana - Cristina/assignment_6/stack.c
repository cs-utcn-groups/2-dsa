//
// Created by Diana on 04/05/2020.
//

#include "stack.h"

void push (int key) {
    NodeT* newH = createNode(key);
    newH->next = stack;
    stack = newH;
}

void pop() {
    if (stack != NULL) {
        stack = stack->next;
    }
}

NodeT * peekStack() {
    return stack;
}

int isEmptyStack() {
    return stack == NULL;
}