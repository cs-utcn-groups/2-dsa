#include "stack.h"

void push ( int content )
{
    NodeT *p = createNode(content);
    p->next = stack;
    stack = p;
}

void pop()
{
    if(stack != NULL) stack = stack->next;
}

NodeT *peekStack()
{
    return stack;
}

int isEmptyStack()
{
    return stack == NULL;
}