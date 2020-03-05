//
// Created by ileana on 3/1/2020.
//

#include "sll.h"
#include "string.h"

void initialize(NodeT * first, NodeT * last)
{
    first = last = NULL;
}

void addElement(int key)
{
    NodeT  * newElement = (NodeT*)malloc(sizeof(NodeT));
    newElement->next=NULL;
    newElement->capacity=key;
    if(firstSentinel==NULL)
        firstSentinel=newElement;
    else
        lastSentinel->next=newElement;
    lastSentinel=newElement;
}

void addElementCountry(char name[])
{
    NodeT1  * newElement = (NodeT1*)malloc(sizeof(NodeT1));
    newElement->next=NULL;
    strcpy(newElement->country,name);
    if(firstCountry==NULL) {
        firstCountry = newElement;
    }
    else {
        lastCountry->next = newElement;
    }
    lastCountry=newElement;
}

void addWaves(int key, int i)
{
    NodeT  * newElement = (NodeT*)malloc(sizeof(NodeT));
    newElement->next=NULL;
    newElement->capacity=key;
    if(firstNodes[i]==NULL)
        firstNodes[i]=newElement;
    else
        lastNodes[i]->next=newElement;
    lastNodes[i]=newElement;
}

void deleteFirstSentinel()
{
    NodeT  * element;
    if(firstSentinel!=NULL)
    {
        element=firstSentinel;
        firstSentinel=firstSentinel->next;
        free(element);
        if(firstSentinel==NULL)
            lastSentinel=NULL;
    }
}

void deleteWave(int i)
{
    NodeT  * element;
    if(firstNodes[i]!=NULL)
    {
        element=firstNodes[i];
        firstNodes[i]=firstNodes[i]->next;
        free(element);
        if(firstNodes[i]==NULL)
            lastNodes[i]=NULL;
    }
}

void removeCountry(char name[])
{
    NodeT1 * currentElement, * previousElement;
    currentElement=firstCountry;
    previousElement=NULL;
    while(currentElement!=NULL)
    {
        if(strcmp(currentElement->country,name)==0) break;
        previousElement=currentElement;
        currentElement=currentElement->next;
    }
    if(currentElement!=NULL)
    {
        if(currentElement==firstCountry)
        {
            firstCountry=firstCountry->next;
            free(currentElement);
            if(firstCountry==NULL)
                lastCountry=NULL;
        }
        else
        {
            previousElement->next=currentElement->next;
            if(currentElement==lastCountry)
                lastCountry=previousElement;
            free(previousElement);
        }
    }
}

NodeT ** createArrayOfNodes(int n)
{
    NodeT ** array = (NodeT **)malloc(n*sizeof(NodeT*));
    return array;
}

void printSll(NodeT * first, NodeT *last)
{
    if(first!=NULL)
    {
        NodeT * currentElement=first;
        while(currentElement!=NULL)
        {
            printf("%d ",currentElement->capacity);
            currentElement=currentElement->next;
        }
        printf("\n");
    }
}
void printSll1(NodeT1 * first, NodeT1 *last)
{
    if(first!=NULL)
    {
        NodeT1 * currentElement=first;
        while(currentElement!=NULL)
        {
            printf("%s ",currentElement->country);
            currentElement=currentElement->next;
        }
        printf("\n");
    }
}