#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node * next;
} NodeT;

NodeT *first,*last;

void initialize()
{
    first = NULL;
    last = NULL;
}

void AF(int data)
{
    if(first == NULL)
    {
        first = (NodeT*)malloc(sizeof(NodeT));
        first->next = last;
        first->data = data;
        last = first;
        //last->next = NULL;
    }
    else
    {
        NodeT * newE1 = (NodeT*)malloc(sizeof(NodeT));
        newE1->next = first;
        newE1->data = data;
        first = newE1;
    }
}

void AL(int data)
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

void DF()
{
    NodeT*currentNode = first;
    first = first->next;
    free(currentNode);
}

void DL()
{
    NodeT*currentNode = first;
    while(currentNode->next != last)
        currentNode = currentNode->next;
    free(last);
    last = currentNode;
    last->next = NULL;
}

void DOOM_THE_LIST()
{
    NodeT *currentNode = first;
    while(currentNode->next != NULL)
    {
        currentNode = currentNode->next;
        free(first);
        first = currentNode;
    }
    free(first);
}

void PRINT_ALL()
{
    NodeT*currentNode = first;
    while(currentNode != NULL)
    {
        printf("%d",currentNode->data);
        currentNode = currentNode->next;
    }
    printf("\n");
}

void PRINT_F(int data)
{
    int nr=0;
    NodeT *currentNode = first;
    while(currentNode->next != NULL && nr<data)
    {
        printf("%d",currentNode->data);
        currentNode = currentNode->next;
        nr++;
    }
    printf("\n");
}

void PRINT_L(int data)
{
    int nr=0;
    NodeT *currentNode = first;
    while(currentNode->next != NULL)
    {
        currentNode = currentNode->next;
        nr++;
    }
    nr++;
    currentNode = first;
    while(currentNode->next != NULL)
    {
        if(nr<=data)
            printf("%d",currentNode->data);
        currentNode = currentNode->next;
        nr--;
    }
}

int main()
{
    initialize();
    for(int i=0; i<10; i++)
    {
        AL(i);
    }
    PRINT_ALL();
    AF(7);
    PRINT_ALL();
    DF();
    PRINT_ALL();
    DL();
    PRINT_ALL();
    PRINT_F(3);
    PRINT_L(3);
    DOOM_THE_LIST();
    return 0;
}
