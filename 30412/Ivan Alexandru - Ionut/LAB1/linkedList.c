#include <stdio.h>
#include <stdlib.h>
#include "linkedList.h"

void initList()
{
    first = NULL;
    last = NULL;
}

void AF(int data)
{
    if(first == NULL)
    {
        first = (NodeT*)malloc(sizeof(NodeT));
        first->data = data;
        first->next = NULL;
    }
    else if(last == NULL)
    {
        last = (NodeT*)malloc(sizeof(NodeT));
        last->data = first->data;
        last->next = NULL;
        first->data = data;
        first->next = last;
    }
    else
    {
        NodeT* newElement = (NodeT*)malloc(sizeof(NodeT));
        newElement->data = data;
        newElement->next = first;
        first = newElement;
    }
}

void AL(int data)
{
    if(first == NULL)
    {
        first = (NodeT*)malloc(sizeof(NodeT));
        first->data = data;
        first->next = NULL;
    }
    else if(last == NULL)
    {
        last = (NodeT*)malloc(sizeof(NodeT));
        last->data = data;
        first->next = last;
        last->next = NULL;
    }
    else
    {
        NodeT* newElement = (NodeT*)malloc(sizeof(NodeT));
        newElement->data = data;
        last->next = newElement;
        newElement->next = NULL;
        last = newElement;
    }
}

void DF()
{
    NodeT* firstElement = first;
    first = first->next;
    free(firstElement);
}

void DL()
{
    if(first != NULL)
    {
        NodeT* currentElement = first;
        while(currentElement->next != last)
        {
            currentElement = currentElement->next;
        }

        last = currentElement;
        last->next = NULL;
        currentElement = currentElement->next;
        free(currentElement);
    }
}

void DOOM_THE_LIST()
{
    NodeT * currentElement = first;
    while(currentElement != NULL)
    {
        first = first->next;
        free(currentElement);
        currentElement = first;
    }
    first = NULL;
    last = NULL;
}

void DE(int data)
{
    NodeT * currentElement = first;
    NodeT * previousElement = first;
    while(currentElement != NULL)
    {
        if(currentElement->data == data)
        {
            if(currentElement == first)
            {
                first = first->next;
                free(currentElement);
                currentElement = first;
            }
            else if(currentElement == last)
            {
                previousElement->next = NULL;
                last = previousElement;
                free(currentElement);
                currentElement = previousElement->next;
            }
            else
            {
                previousElement->next = currentElement->next;
                free(currentElement);
                currentElement = previousElement->next;
            }
        }
        previousElement = currentElement;
        currentElement = currentElement->next;
    }
}

void PRINT_ALL()
{
    NodeT * currentElement = first;
    while(currentElement != NULL)
    {
        fprintf(g, "%d ", currentElement->data);
        currentElement = currentElement->next;
    }
    fprintf(g, "\n");
}

void PRINT_F(int x)
{
    NodeT* currentElement = first;
    while(currentElement != NULL && x > 0)
    {
        fprintf(g, "%d ", currentElement->data);
        x--;
        currentElement = currentElement->next;
    }
    fprintf(g, "\n");
}

void PRINT_L(int x)
{
    NodeT* firstElement = first, *lastElement = first;
    for(int i = 1; i <= x; i++)
    {
        if(lastElement != NULL)
            lastElement = lastElement->next;
    }
    while(lastElement != NULL)
    {
        lastElement = lastElement->next;
        firstElement = firstElement->next;
    }
    while(firstElement != NULL)
    {
        fprintf(g, "%d ", firstElement->data);
        firstElement = firstElement->next;
    }
    fprintf(g, "\n");
}

