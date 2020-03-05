#include "head.h"

void AddFirst(int x)
{
    if (first == NULL)
    {
        first = (NodeT *) malloc (sizeof(NodeT));
        first->next = last;
        first->data = x;
        last = first;
    }
    else
    {
        NodeT * newElement = (NodeT *) malloc (sizeof(NodeT));
        newElement->next = first;
        newElement->data = x;
        first = newElement;
    }
}

void AddLast(int x) {
    if (first == NULL)
    {
        first = (NodeT *) malloc(sizeof(NodeT));
        first->next = last;
        first->data = x;
        last = first;
    }
    else
    {
        NodeT * newElement = (NodeT *) malloc(sizeof(NodeT));
        last->next = newElement;
        newElement->next = NULL;
        newElement->data = x;
        last = newElement;
    }
}

void DeleteFirst()
{
    first = first->next;
}

void DeleteLast()
{
    NodeT * currentElement = first;
    NodeT * previousElement= first;
    while(currentElement!=NULL)
    {
        if(currentElement==last)
        {
            last=previousElement;
            last->next = NULL;
        }
        else{
            previousElement = currentElement;
            currentElement = currentElement->next;
        }
    }
}

void Delete(int x) {
    NodeT * currentElement = first;
    NodeT * previousElement= first;
    while(currentElement != NULL)
    {
        if(currentElement->data == x)
        {
            if(currentElement == first)
            {
                first = first->next;
            }
            else
            if(currentElement == last)
            {
                last = previousElement;
                last->next = NULL;
            }
            else
            {
                previousElement->next = currentElement->next;
            }
            previousElement = currentElement;
            currentElement = currentElement->next;
            free(previousElement);
            previousElement = currentElement;
        }
        else
        {
            previousElement = currentElement;
            currentElement = currentElement->next;
        }
    }
}

void PrintFirstXElements(int x)
{
    int i=1;
    if(first == NULL)
    {
        fprintf(fptrout, "List is empty!\n");
    }
    else
    {
        NodeT *currentElement = first;
        while(i<=x)
        {
            fprintf(fptrout, "%d ", currentElement->data);
            currentElement = currentElement->next;
            i++;
        }
    }
    fprintf(fptrout, "\n");
}

void PrintLastXElements(int x)
{
    if(first == NULL)
    {
        fprintf(fptrout, "List is empty!\n");
    }
    else
    {
        NodeT * currentElement = first;
        int nr = 0;
        while(currentElement!=NULL)
        {
            nr++;
            currentElement = currentElement->next;
        }

        currentElement = first;
        int i =0;
        while(currentElement!=NULL)
        {
            if(i<nr-x)
            {
                i++;
                currentElement = currentElement->next;
            }
            else
            {
                fprintf(fptrout, "%d ", currentElement->data);
                currentElement = currentElement->next;
            }
        }
        fprintf(fptrout, "\n");
    }
}

void DeleteAll()
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
        fprintf(fptrout, "List is empty!\n");
    }
    else
    {
        NodeT * currentElement = first;
        while(currentElement != NULL)
        {
            fprintf(fptrout, "%d ", currentElement->data);
            currentElement = currentElement->next;
        }
        fprintf(fptrout, "\n");
    }
}


//
// Created by Anca on 3/1/2020.
//