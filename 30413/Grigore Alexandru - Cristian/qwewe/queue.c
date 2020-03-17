#include "head.h"

void initializeQwewe()
{
    firstS=NULL;
    lastS=NULL;
    firstC=NULL;
    lastC=NULL;
}

void AddSeconds(int key)
{
    if(firstS==NULL)
    {
        firstS=(SecondsT*)malloc(sizeof(SecondsT));
        firstS->data=key;
        firstS->next=NULL;
        lastS=firstS;
    }
    else
    {
        SecondsT *newS=(SecondsT*)malloc(sizeof(SecondsT));
        newS->next=NULL;
        newS->data=key;
        lastS->next=newS;
        lastS=newS;
    }
}

void AddCustomers(int rou,int ss)
{
    if(firstC==NULL)
    {
        firstC=malloc(sizeof(CustomersT));
        firstC->next=NULL;
        firstC->roubles=rou;
        firstC->seconds=ss;
        lastC=firstC;
    }
    else
    {
        CustomersT *newC=(CustomersT*)malloc(sizeof(CustomersT));
        newC->roubles=rou;
        newC->seconds=ss;
        newC->next=NULL;
        lastC->next=newC;
        lastC=newC;
    }
}

int compute(int time)
{
    static int seconds=0,rubles=0;
    while(firstC!=NULL && firstC->seconds+seconds<=time)
    {
        seconds+=firstC->seconds;
        rubles+=firstC->roubles;
        CustomersT *newElement=firstC;
        firstC=firstC->next;
        free(newElement);
    }
    return rubles;
}


