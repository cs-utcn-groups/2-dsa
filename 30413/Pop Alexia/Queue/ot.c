#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "heade.h"

void initializeList ()
{
    first=NULL;
    last=NULL;
};
void addelementf(int rubles,int time)
{
    if (first == NULL)
    {
        first = (Q*)malloc(sizeof(Q));
        first->next = last;
        first->prev=NULL;
        first->rubles=rubles;
        first->time=time;
        last = first;
    }
    else
    {
        Q* newElement = (Q*)malloc(sizeof(Q));
        last->next = newElement;
        newElement->prev=last;
        newElement->next = NULL;
        newElement->rubles =rubles;
        newElement->time=time;
        last = newElement;
    }

};
int sum(int x)
{
    int sumr=0;
    int sumt=0;
    Q*currentElement=first;
    while(currentElement!=NULL)
    {
        sumr=sumr+currentElement->rubles;
        currentElement->sumr=sumr;
        sumt=sumt+currentElement->time;
        currentElement->sumt=sumt;
        currentElement=currentElement->next;

    }
    currentElement=first;
    if(x>=last->sumt)
        return last->sumr;
    while(currentElement->sumt<x&&currentElement!=NULL)
    {
        currentElement=currentElement->next;

    }
    if(currentElement->sumt==x)
        return currentElement->sumr;
    return currentElement->prev->sumr;
};
void print(FILE *g,int vec[200],int i)
{
    g=fopen("output.txt","w+");
    for(int j=0; j<i-1; j++)
    {
        fprintf(g,"After %d:%d\n",vec[j],sum(vec[j]));
    }
};


