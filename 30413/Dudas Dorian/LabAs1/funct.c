#include "header.h"

void fAF(int x)
{
    if(first == NULL)
    {
        first = (NodeT*)malloc(sizeof(NodeT));
        first->next = last;
        first->data = x;
        last = first;
    }
    else
    {
        NodeT * newElement = (NodeT*)malloc(sizeof(NodeT));
        newElement->next = first;
        newElement->data = x;
        first = newElement;
    }
}

void fAL(int x)
{
    if(first == NULL)
    {
        first = (NodeT*)malloc(sizeof(NodeT));
        first->next = last;
        first->data = x;
        last = first;
    }
    else
    {
        NodeT * newElement = (NodeT*)malloc(sizeof(NodeT));
        last->next = newElement;
        newElement->data = x;
        newElement->next = NULL;
        last = newElement;
    }
}

void fDF()
{
    if (first != NULL)
    {
        first = first->next;
    }
}

void fDL()
{
    if (first != NULL)
    {
        NodeT * currentElement = first;
        while(currentElement->next != last)
        {
            currentElement = currentElement->next;
        }
        currentElement->next = NULL;
        last = currentElement;
    }
}

void fDOOM()
{
    NodeT * currentElement = first;
    while(currentElement != NULL)
    {
        first = first->next;
        free(currentElement);
        currentElement = first;
    }
}

void fDE(int x) //deletes the first instance if there is one
{
    NodeT * currentElement = first;
    NodeT * previousElement = first;

    while(currentElement != NULL)
    {
        if(currentElement->data == x)
        {
            if(currentElement == first)
            {
                first->next = first;
            }
            else if(currentElement == last)
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

void fPA(FILE * f)
{
    if(first == NULL)
    {
        fprintf(f,"List is empty!\n");
    }
    else
    {
        NodeT * currentElement = first;
        while(currentElement != NULL)
        {
            fprintf(f,"%d ", currentElement->data);
            currentElement = currentElement->next;
        }
        fprintf(f,"\n");
    }
}

void fPF(FILE * f, int x)
{
    if(first == NULL)
    {
        fprintf(f,"List is empty!\n");
    }
    else
    {
        NodeT * currentElement = first;
        while(x != 0 && currentElement != NULL)
        {
            fprintf(f,"%d ", currentElement->data);
            x--;
            currentElement = currentElement->next;
        }
        fprintf(f,"\n");
    }
}

void fPL(FILE * f, int x)
{
    if(first == NULL)
    {
        fprintf(f,"List is empty!\n");
    }
    else
    {
        NodeT * currentElement = first;
        NodeT * previousElement = first;
        int xDiff = 0;

        while(currentElement != NULL)
        {
            xDiff++;
            if(xDiff > x)
            {
                xDiff--;
                previousElement = previousElement->next;
            }
            currentElement = currentElement->next;
        }
        while(previousElement != NULL)
        {
            fprintf(f,"%d ", previousElement->data);
            previousElement = previousElement->next;
        }
        fprintf(f,"\n");
    }
}
