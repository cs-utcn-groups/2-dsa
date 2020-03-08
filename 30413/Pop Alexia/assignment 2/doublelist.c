#include <stdio.h>
#include <stdlib.h>
#include "head.h"

void initialize()
{
    first = NULL;
    last = NULL;
};
void addElementf(int data)
{
    if (first == NULL)
    {
        first = (NodeT*)malloc(sizeof(NodeT));
        first->next = last;
        first->data = data;
        first->prev=NULL;
        last = first;
    }
    else
    {
        NodeT* newElement = (NodeT*)malloc(sizeof(NodeT));
        last->next = newElement;
        newElement->next = NULL;
        newElement->data = data;
        newElement->prev=last;
        last = newElement;
    }

};
void addElementi(int data)
{
    if (first == NULL)
    {
        first = (NodeT*)malloc(sizeof(NodeT));
        first->next = last;
        first->data = data;
        first->prev=NULL;
        last = first;
    }
    else
    {
        NodeT* newElement = (NodeT*)malloc(sizeof(NodeT));
        newElement->next = first;
        newElement->data = data;
        first->prev=newElement;
        first = newElement;
        newElement->prev=NULL;
    }


};
void eraseElement(int data)
{
    NodeT* currentElement = first;
    while (currentElement != NULL)
    {
        if (currentElement->data == data)
        {
            if (currentElement == first)
            {
                first = first->next;
                first->prev=NULL;
            }
            else if (currentElement == last)
            {
                last = currentElement->prev;
                last->next = NULL;
            }
            else
            { currentElement->prev->next=currentElement->next;
            }
            free(currentElement);

        }
        else
        {
             currentElement=currentElement->next;

        }
    }
};
void erasei()
{
    if (first == NULL)
    {
        return;
    }
    NodeT* currentElement;
    currentElement = first->next;
    free(first);
    first = currentElement;
    first->prev=NULL;
};
void erasef()
{
    if (first == NULL)
    {
        return;
    }
    NodeT* currentElement = last->prev;
    free(last);
    last=currentElement;
    last->next=NULL;
};
void print()
{
    FILE* g = fopen("output.txt", "a");
    if (first == NULL)
    {
        printf("List is empty!\n");
    }
    else
    {
        NodeT* currentElement = first;
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
    NodeT* currentElement = first;
    while (currentElement != NULL)
    {
        first = first->next;
        currentElement->next = NULL;
        free(currentElement);
        currentElement = first;

    }
};

void printIx(int x)
{
    FILE* g = fopen("output.txt", "a");
    int i = 0;
    NodeT* currentElement = first;
    for (i = 0; i < x; i++)
    {
        fprintf(g, "%d ", currentElement->data);
        currentElement = currentElement->next;
    }
    fprintf(g, "\n");
};
void printFx(int x)
{
    FILE* g = fopen("output.txt", "a");
    int i = 0;
    NodeT* currentElement = last;
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

