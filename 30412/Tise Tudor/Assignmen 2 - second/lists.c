//
// Created by Tudor Tise on 10/03/2020.
//

#include "lists.h"

void setUpFile(){
    g = fopen("output.dat", "w");
}

void initializeList()
{
    firstC = NULL;
    firstT = NULL;
    lastC = NULL;
    lastT = NULL;
}

void appendToListSeconds(int numberToBeAdded)
{
    if(firstT == NULL)
    {
        firstT = (NodeTime*)malloc(sizeof(NodeTime));
        firstT->next = lastT;
        firstT->data = numberToBeAdded;
        lastT = firstT;
    }
    else
    {
        NodeTime * newElement = (NodeTime*)malloc(sizeof(NodeTime));
        lastT->next = newElement;
        newElement->next = NULL;
        newElement->data = numberToBeAdded;
        lastT = newElement;
    }
}

void printAllSeconds()
{
    if(firstT == NULL)
    {
        fprintf(g,"List is empty!\n");
    }
    else
    {
        NodeTime * currentElement = firstT;
        while(currentElement != NULL)
        {
            fprintf(g,"%d ", currentElement->data);
            currentElement = currentElement->next;
        }
        fprintf(g,"\n");
    }

}

void appendToListCustomer(char name[NAME_SIZE], int rubles, int seconds)
{
    if(firstC == NULL)
    {
        firstC = (NodeCustomer*)malloc(sizeof(NodeCustomer));
        firstC->next = lastC;
        strcpy(firstC->name,name);
        firstC->rubles = rubles;
        firstC->seconds = seconds;
        lastC = firstC;
    }
    else
    {
        NodeCustomer* newElement = (NodeCustomer*)malloc(sizeof(NodeCustomer));
        lastC->next = newElement;
        newElement->next = NULL;
        strcpy(newElement->name,name);
        newElement->rubles = rubles;
        newElement->seconds = seconds;
        lastC = newElement;
    }
}

void printAllCustomers()
{
    if(firstT == NULL)
    {
        fprintf(g,"List is empty!\n");
    }
    else
    {
        NodeCustomer * currentElement = firstC;
        while(currentElement != NULL)
        {
            fprintf(g,"%s %d %d \n", currentElement->name,currentElement->rubles,currentElement->seconds);
            currentElement = currentElement->next;
        }
        fprintf(g,"\n");
    }

}

