
#include<stdio.h>
#include <stdlib.h>
#include "sll.h"

void initializeList()
{
    first = NULL;
    last = NULL;
}

void AF(int data)
{
    if(first == NULL)
    {
        first = (NodeT*)malloc(sizeof(NodeT));
        first->next = last;
        first->data = data;
        last = first;
    }
    else
    {
        NodeT * newElement = (NodeT*)malloc(sizeof(NodeT));
        newElement->data=data;
        newElement->next=first;
        first=newElement;
    }
}


void AL(int data)
{
    if (first == NULL) {
        first = (NodeT *) malloc(sizeof(NodeT));
        first->next = last;
        first->data = data;
        last = first;
    } else {
        NodeT *newElement = (NodeT *) malloc(sizeof(NodeT));
        last->next = newElement;
        newElement->next = NULL;
        newElement->data = data;
        last = newElement;
    }
}

void DF()
{
    if (first != NULL) {
        first = first->next;
    }
}

void DL()
{
    NodeT *previousElement = first;
    {
        if (last != NULL) {
            last = previousElement;
            last->next = NULL;
        }
    }
}

void PRINT_ALL()
{
    int ct=0;
    if(first == NULL)
    {
        printf("List is empty!\n");
    }
    else
    {
        NodeT * currentElement = first;
        while(currentElement != NULL)
        {
            ct++;
            printf("%d ", currentElement->data);
            currentElement = currentElement->next;
        }
        printf("\n");
    }
}

void DE (int data)
{
        NodeT * currentElement = first;
        NodeT * previousElement= first;
        while(currentElement != NULL)
        {
            if(currentElement->data == data)
            {
                if(currentElement == first)
                {
                    first = first->next;
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

void PRINT_L(int data,int ct)
{
    int ct1=0;
    if(first == NULL)
        {
            printf("List is empty!\n");
        }
        else
        {
            NodeT * currentElement = first;
            while(currentElement != NULL)
            {
                ct1++;
                if(ct1 > ct - data + 1)
                    printf("%d ",currentElement->data);
                currentElement = currentElement->next;
            }
            printf("\n");
        }
    }
void PRINT_F(int data){

    if(first == NULL)
        printf("List is empty!\n");
    else
    {
        NodeT * currentElement = first;
        while((currentElement != NULL) && (data!=0))
        {
            data--;
            printf("%d ", currentElement->data);
            currentElement = currentElement->next;
        }
    printf("\n");
    }
}

void DOOM_LIST()
{
    NodeT * currentElement = first;
    while(currentElement != NULL)
    {
        first = first->next;
        free(currentElement);
        currentElement = first;
    }

}

int getListLength()
{
        int ct=0;
        NodeT * currentElement=first;
        while(currentElement != NULL)
        {
            ct++;
            currentElement = currentElement->next;
        }
        return ct;
};
