//
// Created by Tudor Tise on 10/03/2020.
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

void addLast(int addedValue)
{
    if(first == NULL)
    {
        first = (NodeT*)malloc(sizeof(NodeT));
        first->next = last;
        first->data = addedValue;
        first->prev = NULL;
        last = first;
    }
    else
    {
        NodeT * newElement = (NodeT*)malloc(sizeof(NodeT));
        last->next = newElement;
        newElement->next = NULL;
        newElement->prev = last;
        newElement->data = addedValue;
        last = newElement;
    }
}

void addFirst(int addedValue)
{
    if(first == NULL)
    {
        first = (NodeT*)malloc(sizeof(NodeT));
        first->next = last;
        first->data = addedValue;
        first->prev = NULL;
        last = first;
    }
    else {
        NodeT *newElement = (NodeT *) malloc(sizeof(NodeT));
        newElement->data = addedValue;
        newElement->next = first;
        newElement->prev = NULL;
        first->prev = newElement;
        first = newElement;
    }
}

void removeLast(){
    if(first == NULL)
    {
        fprintf(g,"List is empty!\n");
    }
    else {
        NodeT * currentElement = last;
        last = last->prev;
        last->next = NULL;
        free(currentElement);
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
        first->prev = NULL;
        free(currentElement);
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

void printFirst(int noOfElementsToBePrinted){
    if(first == NULL)
    {
        fprintf(g,"List is empty!\n");
    }
    else if (noOfElementsToBePrinted > getNoOfItems()){
        printAll();
    } else
    {
        NodeT * currentElement = first;
        for (int i = 0; i<noOfElementsToBePrinted; i++)
        {
            fprintf(g,"%d ", currentElement->data);
            currentElement = currentElement->next;
        }
        fprintf(g,"\n");
    }
}

void printLast(int noOfElementsToBePrinted){
    if(first == NULL)
    {
        fprintf(g,"List is empty!\n");
    }
    else if (noOfElementsToBePrinted > getNoOfItems()){
        printAll();
    } else
    {
        NodeT * currentElement = first;
        int i = 0;
        while (currentElement != NULL){
            if (i >= (getNoOfItems() - noOfElementsToBePrinted)){
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

void removeElement(int itemToBeDeleted){

    NodeT * currentElement = first;
    while(currentElement != NULL)
    {
        if(currentElement->data == itemToBeDeleted)
        {
            if(currentElement == first)
            {
                removeFirst();
            }
            else if(currentElement == last)
            {
                removeLast();
            } else {
                currentElement->prev->next = currentElement->next;
                currentElement->next->prev = currentElement->prev;
                free(currentElement);
            }
        }
        else
        {
            currentElement = currentElement->next;
        }

    }
}
