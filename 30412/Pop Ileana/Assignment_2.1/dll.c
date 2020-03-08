//
// Created by ileana on 3/6/2020.
//

#include "dll.h"


void initializeDll()
{
    L=(List_header*)malloc(sizeof(List_header));

    L->first=(NodeT*)malloc(sizeof(NodeT));
    L->first=NULL;

    L->last=(NodeT*)malloc(sizeof(NodeT));
    L->last=NULL;
}

void addFirst(int givenKey)
{
    NodeT * newElement = (NodeT*)malloc(sizeof(NodeT));
    newElement->key=givenKey;
    if(L->first==NULL)
    {
        L->first=L->last=newElement;
        newElement->next=newElement->previous=NULL;
    }
    else
    {
        newElement->next=L->first;
        newElement->previous=NULL;
        L->first->previous=newElement;
        L->first=newElement;
    }
}

void addLast(int givenKey)
{
    NodeT * newElement = (NodeT*)malloc(sizeof(NodeT));
    newElement->key=givenKey;
    if(L->first==NULL)
    {
        L->first=L->last=newElement;
        newElement->next=newElement->previous=NULL;
    }
    else
    {
        newElement->next=NULL;
        newElement->previous=L->last;
        L->last->next=newElement;
        L->last=newElement;
    }
}

void deleteFirst()
{
    if(L->first!=NULL) {
        NodeT *element;
        element = L->first;
        L->first = L->first->next;
        if (L->first == NULL)
            L->last = NULL;
        else
            L->first->previous = NULL;
        free(element);
    }
}

void deleteLast()
{
    if(L->first!=NULL) {
        NodeT *element;
        element = L->last;
        L->last = L->last->previous;
        if (L->last == NULL)
            L->first = NULL;
        else
            L->last->next = NULL;
        free(element);
    }
}



void removeElement(int givenKey)
{
    NodeT * currentElement;
    currentElement=L->first;
    while(currentElement!=NULL)
    {
        if(currentElement->key==givenKey)
            break;
        currentElement=currentElement->next;
    }
    if(currentElement!=NULL)
    {
        if(currentElement==L->first)
        {
            L->first=L->first->next;
            if(L->first==NULL)
                L->last=NULL;
            else
                L->first->previous=NULL;
            free(currentElement);
        }
        else
        {
            if(currentElement==L->last)
            {
                L->last=L->last->previous;
                if(L->last==NULL)
                    L->first=NULL;
                else
                    L->last->next=NULL;
                free(currentElement);
            }
            else {
                currentElement->next->previous = currentElement->previous;
                currentElement->previous->next = currentElement->next;
                free(currentElement);
            }
        }
    }
}
void removeAll()
{
    NodeT * element;
    while(L->first!=NULL)
    {
        element=L->first;
        L->first=L->first->next;
        free(element);
    }
    L->last=NULL;
}

void printDllData(FILE *fptr)
{
    if(L->first!=NULL)
    {
        NodeT * element=L->first;
        while(element!=NULL)
        {
            fprintf(fptr,"%d ",element->key);
            element=element->next;
        }
        fprintf(fptr,"\n");
    }
}
void printFirstValues(int n,FILE *fptr)
{
    if(L->first!=NULL) {
        NodeT *element = L->first;
        for (int i = 0; i < n && element != NULL; i++) {
            fprintf(fptr, "%d ", element->key);
            element = element->next;
        }
        fprintf(fptr, "\n");
    }
}
void printLastValues(int n, FILE *fptr,NodeT * element)
{
    if(n==1 || element==L->first)
        fprintf(fptr, "%d ", element->key);
    else {
        printLastValues(n - 1, fptr, element->previous);
        fprintf(fptr, "%d ", element->key);
    }
}