//
// Created by ileana on 3/1/2020.
//

#include "sll.h"

void initializeSll(){

    first=NULL;
    last=NULL;
}

void addFirst(int givenKey)
{
    NodeT * p= (NodeT *)malloc(sizeof(NodeT));
    p->key = givenKey;

    if(first == NULL)
    {
        first = p;
        last = p;
        p->next=NULL;
    }
    else
    {
        p->next=first;
        first=p;
    }
}

void addLast(int givenKey)
{
    NodeT * p= (NodeT *)malloc(sizeof(NodeT));
    p->key = givenKey;
    p->next = NULL;

    if(last != NULL)
        last->next = p;
    else
        first = p;
    last = p;
}

void deleteFirst()
{
    NodeT *p;
    if(first != NULL)
    {
        p=first;
        first=first->next;
        free(p);
        if(first==NULL)
            last=NULL;
    }
}

void deleteLast()
{
    NodeT * currentElement = first;
    NodeT * previousElement= first;
    if(currentElement!=NULL)
    {
        while(currentElement!=last) {
            previousElement = currentElement;
            currentElement = currentElement->next;
        }
        if(currentElement==first)
            first=last=NULL;
        else
        {
            previousElement->next=NULL;
            last=previousElement;
        }
        free(currentElement);
    }
}

void removeElement(int givenKey)
{
    NodeT * currentElement = first;
    NodeT * previousElement= first;
    while(currentElement!=NULL)
    {
        if(currentElement->key==givenKey)
            break;
        previousElement=currentElement;
        currentElement=currentElement->next;
    }
    if(currentElement!=NULL)
    {
        if(currentElement==first)
        {
            first=first->next;
            free(currentElement);
            if(first==NULL)
                last=NULL;
        }
        else
        {
            previousElement->next=currentElement->next;
            if(currentElement==last)
                last=previousElement;
            free(currentElement);
        }
    }
}

void removeAll()
{
    NodeT * currentElement=first;
    while(currentElement != NULL)
    {
        first=first->next;
        free(currentElement);
        currentElement=first;
    }
}

void printSllData(FILE *fptr)
{
    if(first!=NULL)
    {
        NodeT *currentElement = first;
        while (currentElement != NULL) {
            fprintf(fptr, "%d ", currentElement->key);
            currentElement = currentElement->next;
        }
        fprintf(fptr, "\n");
    }
}

void printFirstValues(int n, FILE *fptr)
{
    NodeT *currentElement=first;
    if(currentElement!=NULL)
    {
        for(int i=0;i<n && currentElement!=NULL;i++) {
            fprintf(fptr, "%d ", currentElement->key);
            currentElement = currentElement->next;
        }
        fprintf(fptr,"\n");
    }
}

void printLastValues(int n, FILE *fptr)
{
    int noOfNodes=0;
    NodeT * currentElement = first;
    while(currentElement!=NULL)
    {
        noOfNodes++;
        currentElement=currentElement->next;
    }
    if(noOfNodes<n)
        printSllData(fptr);
    else
    {
        currentElement=first;
        for(int i=0;i<noOfNodes-n;i++)
            currentElement=currentElement->next;
        for(int i=0;i<n;i++)
        {
            fprintf(fptr, "%d ", currentElement->key);
            currentElement = currentElement->next;
        }
        fprintf(fptr,"\n");
    }
}