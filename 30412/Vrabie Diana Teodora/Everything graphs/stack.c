//
// Created by diana on 10/05/2020.
//

#include "stack.h"

StackNode *createNewStackNode(int value) {
    StackNode *node = (StackNode *) malloc(sizeof(StackNode));
    node->value = value;
    node->next = NULL;
    return node;
}

Stack *initializeStack() {
    Stack *newStack = (Stack *) malloc(sizeof(Stack));
    newStack->first = NULL;
    return newStack;
}

void push(StackNode *node, Stack *stack) {
    // empty stack, add first node
    if (stack->first == NULL) {
        stack->first = node;
        return;
    }
    // push node to front of stack
    node->next = stack->first;
    stack->first = node;
}

StackNode *pop(Stack *stack) {
    // stack is empty
    if (stack->first == NULL) {
        return NULL;
    }
    StackNode *node = stack->first;
    stack->first = stack->first->next;
    return node;
}

bool isEmpty(Stack *stack) {
    if (stack->first == NULL)
        return true;
    return false;
}

