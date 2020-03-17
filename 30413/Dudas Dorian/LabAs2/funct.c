#include "header.h" ///tackle the prev node!!!!!!!!!!!!!!!

void fAF(int x)
{
    if(Sentinel->first == NULL)
    {
        Sentinel->first = (NodeT*)malloc(sizeof(NodeT));
        Sentinel->first->next = NULL;
        Sentinel->first->prev = NULL;
        Sentinel->first->data = x;
        Sentinel->last = Sentinel->first;
    }
    else
    {
        NodeT * newElement = (NodeT*)malloc(sizeof(NodeT));
        newElement->next = Sentinel->first;
        newElement->prev = NULL;
        newElement->data = x;
        Sentinel->first = newElement;
        Sentinel->first->prev = NULL;
    }
}

void fAL(int x)
{
    if(Sentinel->first == NULL)
    {
        Sentinel->first = (NodeT*)malloc(sizeof(NodeT));
        Sentinel->first->next = NULL;
        Sentinel->first->prev = NULL;
        Sentinel->first->data = x;
        Sentinel->last = Sentinel->first;
    }
    else
    {
        NodeT * newElement = (NodeT*)malloc(sizeof(NodeT));
        Sentinel->last->next = newElement;
        newElement->data = x;
        newElement->next = NULL;
        newElement->prev = Sentinel->last;
        Sentinel->last = newElement;
    }
}

void fDF()
{
    if (Sentinel->first != NULL)
    {
        NodeT * currentElement = Sentinel->first;
        Sentinel->first = currentElement->next;
        free(currentElement);
        Sentinel->first->prev = NULL;
    }
}

void fDL()
{
    if (Sentinel->first != NULL)
    {
        NodeT * currentElement = Sentinel->last;
        Sentinel->last = currentElement->prev;
        free(currentElement);
        Sentinel->last->next = NULL;
    }
}

void fDOOM()
{
    NodeT * currentElement = Sentinel->first;
    while(currentElement != NULL)
    {
        Sentinel->first = Sentinel->first->next;
        free(currentElement);
        currentElement = Sentinel->first;
    }
}

void fDE(int x)
{
    NodeT * currentElement = Sentinel->first;
    NodeT * previousElement = Sentinel->first;

    while(currentElement != NULL)
    {
        if(currentElement->data == x)
        {
            if(currentElement == Sentinel->first)
            {
                fDF();
            }
            else if(currentElement == Sentinel->last)
            {
                fDL();
            }
            else
            {
                previousElement->next = currentElement->next;
                free(currentElement);
                currentElement = previousElement->next;
                currentElement->prev = previousElement;
            }
        }
        else
        {
            previousElement = currentElement;
            currentElement = currentElement->next;
            currentElement->prev = previousElement;
        }
    }
}

void fPA(FILE * f)
{
    if(Sentinel->first == NULL)
    {
        fprintf(f,"List is empty!\n");
    }
    else
    {
        NodeT * currentElement = Sentinel->first;
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
    if(Sentinel->first == NULL)
    {
        fprintf(f,"List is empty!\n");
    }
    else
    {
        NodeT * currentElement = Sentinel->first;
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
    if(Sentinel->first == NULL)
    {
        fprintf(f,"List is empty!\n");
    }
    else
    {
        NodeT * currentElement = Sentinel->first;
        NodeT * previousElement = Sentinel->first;
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
