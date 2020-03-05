//
// Created by Tudor Tise on 02/03/2020.
//

#include "listManagement.h"

void setUpFile(){
    g = fopen("output.dat", "w");
}

void initializeList()
{
    first = NULL;
    last = NULL;
}

int getNoOfItems(){
    NodeT * currentElement = first;
    int i = 0;
    while(currentElement != NULL)
    {
        currentElement = currentElement->next;
        i++;
    }
    return i;
}

void addLast(int data)
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
        last->next = newElement;
        newElement->next = NULL;
        newElement->data = data;
        last = newElement;
    }
}

void addFirst(int data)
{
    if(first == NULL)
    {
        first = (NodeT*)malloc(sizeof(NodeT));
        first->next = last;
        first->data = data;
        last = first;
    }
    else {
        NodeT *newElement = (NodeT *) malloc(sizeof(NodeT));
        newElement->data = data;
        newElement->next = first;
        first = newElement;
    }
}

void removeLast(){
    if(first == NULL)
    {
        fprintf(g,"List is empty!\n");
    }
    else {
        NodeT * currentElement = first->next;
        while (currentElement->next != NULL){
            first = currentElement;
            currentElement = currentElement->next;
        }
        free(first->next);
        first->next = NULL;
    }
}

void removeFirst(){
    if(first == NULL)
    {
        fprintf(g,"List is empty!\n");
    }
    else {
        NodeT * currentElement = first;
        first = first->next;
        free(currentElement);
    }
}

void printFirst(int data){
    if(first == NULL)
    {
        fprintf(g,"List is empty!\n");
    }
    else if (data > getNoOfItems()){
        printAll();
    } else
    {
        NodeT * currentElement = first;
        for (int i = 0; i<data; i++)
        {
            fprintf(g,"%d ", currentElement->data);
            currentElement = currentElement->next;
        }
        fprintf(g,"\n");
    }
}

void printLast(int data){
    if(first == NULL)
    {
        fprintf(g,"List is empty!\n");
    }
    else if (data > getNoOfItems()){
        printAll();
    } else
    {
        NodeT * currentElement = first;
        int i = 0;
        while (currentElement != NULL){
            if (i >= (getNoOfItems() - data)){
                fprintf(g,"%d ", currentElement->data);
            }
            currentElement = currentElement->next;
            i++;
        }
        fprintf(g,"\n");
    }
}


void printAll()
{
    if(first == NULL)
    {
        fprintf(g,"List is empty!\n");
    }
    else
    {
        NodeT * currentElement = first;
        while(currentElement != NULL)
        {
            fprintf(g,"%d ", currentElement->data);
            currentElement = currentElement->next;
        }
        fprintf(g,"\n");
    }

}

void removeAll()
{
    NodeT * currentElement ;
    while(first != NULL)
    {
        currentElement = first;
        first = first->next;
        free(currentElement);
    }
}

void removeElement(int data)
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