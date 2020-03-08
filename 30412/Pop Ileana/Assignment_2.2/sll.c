//
// Created by ileana on 3/7/2020.
//

#include "header.h"


void initializeSll()
{
    first=NULL;
    last=NULL;
}

void addLast(int rubles, int seconds)
{
    NodeT * newElement=(NodeT*)malloc(sizeof(NodeT));
    newElement->x=rubles;
    newElement->y=seconds;
    newElement->next=NULL;
    if(first==NULL)
        first=newElement;
    else
        last->next=newElement;
    last=newElement;
}

void deleteFirst()
{
    NodeT * element;
    if(first!=NULL)
    {
        element=first;
        first=first->next;
        free(element);
        if(first==NULL)
            last=NULL;
    }
}
void printSllData(FILE *fptr)
{
    if(first!=NULL)
    {
        NodeT *currentElement = first;
        while (currentElement != NULL) {
            fprintf(fptr, "%d ", currentElement->x);
            currentElement = currentElement->next;
        }
        fprintf(fptr, "\n");
    }
}
