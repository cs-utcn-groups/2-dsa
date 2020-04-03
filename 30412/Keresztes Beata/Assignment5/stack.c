//
// Created by q on 4/2/2020.
//

#include "stack.h"

StackT * createStack() {
    // function to create a stack
    StackT * stack = (StackT *)malloc(sizeof(StackT));
    if(stack == NULL) {
        errMessage();
    }
    else {
        stack->top = stack->bottom = NULL;
    }
    return stack;
}

void push(StackT * stack, int data) {
    // add new element to the top of the stack
    NodeT * new = createNode(data);
    if(stack->top == NULL) {
        stack->bottom = new;
    }
    else {
        stack->top->next = new;
    }
    stack->top = new;
}

int pop(StackT * stack) {
    // remove element from the top of the stack and return its content
    if(stack->top) {
        // if stack is not empty
        int returnValue = stack->top->data;
        NodeT * temp = stack->bottom;
        NodeT * prev = NULL;
        while(temp != stack->top) {
            prev = temp;
            temp = temp->next;
        }
        if(stack->top == stack->bottom) {
            stack->bottom = NULL;
        }
        else {
            prev->next = NULL;
        }
        stack->top = prev;
        free(temp);
        return returnValue;
    }
}
void freeStack(StackT * stack) {
    // free the stack
    while(stack->top) {
        pop(stack);
    }
    free(stack);
}

int isEmptyStack(StackT * stack) {
    // check is stack is empty
    return (stack->top == NULL);
}