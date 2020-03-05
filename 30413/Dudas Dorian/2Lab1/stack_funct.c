#include "head.h"

void pushStack(int data)
{
    if(first == NULL)
    {
        first = (NodeT*)malloc(sizeof(NodeT));
        first->next = last;
        first->data = data;
        last = first;
    }
    else
    {
        NodeT * newElement = (NodeT*)malloc(sizeof(NodeT));
        newElement->next = first;
        newElement->data = data;
        first = newElement;
    }
}

void popStack()
{
    first=first->next;
}

void topStack()
{
    printf("%d \n", first->data);
}

void deleteStack()
{
    NodeT * currentElement = first;
    while(currentElement != NULL)
    {
        first = first->next;
        free(currentElement);
        currentElement = first;
    }
}

void printSllData()
{
    if(first == NULL)
    {
        printf("List is empty!\n");
    }
    else
    {
        NodeT * currentElement = first;
        while(currentElement != NULL)
        {
            printf("%d ", currentElement->data);
            currentElement = currentElement->next;
        }
        printf("\n");
    }
}
