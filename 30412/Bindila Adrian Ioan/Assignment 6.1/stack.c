//
// Created by bindi on 4/2/2020.
//
#include <stdlib.h>
#include "list.h"
#include "stack.h"

void push(int data) {
    list *newElement = createListElement(data);
    newElement->next = stack;
    stack = newElement;
}

void pop(void) {
    if (stack != NULL) {
        stack = stack->next;
    }
}

list *peekStack() {
    return stack;
}

int isEmptyStack() {
    return (stack == NULL);
}