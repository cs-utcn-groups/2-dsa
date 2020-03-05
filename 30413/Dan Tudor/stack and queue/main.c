#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node * next;
} NodeT;

NodeT *first,*last;

void initialize()
{
    first = NULL;
    last = NULL;
}

void addQueue(int data)
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
        NodeT * newE1 = (NodeT*)malloc(sizeof(NodeT));
        last->next = newE1;
        newE1->next = NULL;
        newE1->data = data;
        last = newE1;
    }
}

void removeQueue(int data)
{
    NodeT*currentNode = first;
    first = first->next;
    free(currentNode);
}

void printQueue()
{
    while(first != NULL)
    {
        printf("%d",first->data);
        removeQueue(first->data);
    }
    printf("\n");
}

void addStack(int data)
{
    if(first == NULL)
    {
        first = (NodeT*)malloc(sizeof(NodeT));
        first->next = last;
        first->data = data;
        last = first;
        last->next = NULL;
    }
    else
    {
        NodeT * newE1 = (NodeT*)malloc(sizeof(NodeT));
        newE1->next = first;
        newE1->data = data;
        first = newE1;
    }
}

void removeStack(int data)
{
    NodeT*currentNode = first;
    first = first->next;
    free(currentNode);
}

void printStack()
{
    while(first != NULL)
    {
        printf("%d",first->data);
        removeStack(first->data);
    }
    printf("\n");
}

int main()
{
    initialize();
    for(int i=0;i<10;i++)
    {
        addQueue(i);
    }
    printQueue();

    for(int i=0;i<10;i++)
    {
        addStack(i);
    }
    printStack();
    return 0;
}
