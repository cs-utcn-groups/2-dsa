#include <stdio.h>
#include <stdlib.h>
#include "head.h"


void initialize()
{
    S.first = NULL;
    S.last = NULL;
};

void addElementf(int data)
{
    if (S.first == NULL)
    {
        S.first = (NodeT*)malloc(sizeof(NodeT));
        S.first->next = S.last;
        S.first->data = data;
        S.first->prev=NULL;
        S.last = S.first;
    }
    else
    {
        NodeT* newElement = (NodeT*)malloc(sizeof(NodeT));
        S.last->next = newElement;
        newElement->next = NULL;
        newElement->data = data;
        newElement->prev=S.last;
        S.last = newElement;
    }

};

void addElementi(int data)
{
    if (S.first == NULL)
    {
        S.first = (NodeT*)malloc(sizeof(NodeT));
        S.first->next = S.last;
        S.first->data = data;
        S.first->prev=NULL;
        S.last = S.first;
    }
    else
    {
        NodeT* newElement = (NodeT*)malloc(sizeof(NodeT));
        newElement->next = S.first;
        newElement->data = data;
        S.first->prev=newElement;
        S.first = newElement;
        newElement->prev=NULL;
    }


};

void erasei()
{
    if (S.first == NULL)
    {
        return;
    }
    NodeT* currentElement;
    currentElement = S.first->next;
    free(S.first);
    S.first = currentElement;
    S.first->prev=NULL;
};
void erasef()
{
    if (S.first == NULL)
    {
        return;
    }
    NodeT* currentElement = S.last->prev;
    free(S.last);
    S.last=currentElement;
    S.last->next=NULL;
};
void eraseElement(int data)
{
   NodeT *Element= (NodeT *) malloc (sizeof(NodeT));
   Element=S.first;
   while(Element!=NULL&&Element->data!=data)
   {
    Element=Element->next;
   }
   if(Element==S.first)
   {
       erasei();
   }
   else if(Element==S.last)
   {
       erasef();
   }
   else if(Element != NULL)
   {
      NodeT *Copy= (NodeT *) malloc (sizeof(NodeT));
      Copy=Element->prev;
      Copy->next=Element->next;
      Element->prev=Copy;
      Copy=Element->next;
      Copy->prev=Element->prev;
      Element->next=Copy;
      free(Element);

   }
};

void print()
{
    FILE* g = fopen("output.txt", "a+");
    if (S.first == NULL)
    {
        fprintf(g,"List is empty!\n");
    }
    else
    {
        NodeT* currentElement = S.first;
        while (currentElement != NULL)
        {
            fprintf(g, "%d ", currentElement->data);
            currentElement = currentElement->next;
        }
        fprintf(g, "\n");

    }
};

void eraseAll()
{
    NodeT* currentElement = S.first;
    while (currentElement != NULL)
    {
        S.first = S.first->next;
        currentElement->next = NULL;
        free(currentElement);
        currentElement = S.first;

    }
};

void printIx(int x)
{
    FILE* g = fopen("output.txt", "a+");
    int i = 0;
    NodeT* currentElement = S.first;
    for (i = 0; i < x; i++)
    {
        fprintf(g, "%d ", currentElement->data);
        currentElement = currentElement->next;
    }
    fprintf(g, "\n");
};
void printFx(int x)
{
    FILE* g = fopen("output.txt", "a+");
    int i = 0;
    NodeT* currentElement = S.last;
    while(i<x-1){
        currentElement=currentElement->prev;
        i++;
    }
    while (currentElement != NULL)
    {
        fprintf(g, "%d ", currentElement->data);
        currentElement = currentElement->next;
    }
    fprintf(g, "\n");
};


