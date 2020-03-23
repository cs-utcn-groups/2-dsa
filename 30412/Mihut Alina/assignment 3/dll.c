//
// Created by Alina Mihut on 3/22/20.
//
#include "dll.h"


void initializeDLL()
{
    first=(NodeL*)malloc(sizeof(NodeL));
    last=(NodeL*)malloc(sizeof(NodeL));
    first=NULL;
    last=NULL;
}

void addNode (char data)
{
    if(first==NULL)
    {
        first=(NodeL*)malloc(sizeof(NodeL));
        last=(NodeL*)malloc(sizeof(NodeL));
        first->next=NULL;
        first->data=data;
        first->prev=NULL;
        first=last;
    }
    else
    {
        NodeL *p=(NodeL*) malloc(sizeof(NodeL));
        p->data=data;
        last->next=p;
        p->prev=last;
        p->next=NULL;
        last=p;

    }
}

void transverseList(NodeL *f)
{
    NodeL *currentElement=f;
    if (f==NULL)
        printf("List is empty \n");
    while (currentElement!=NULL)
    {
        printf(" %c ", currentElement->data);
        currentElement=currentElement->next;
    }
    printf("\n");

}