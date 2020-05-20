#include "head.h"

int seconds=0,rubles=0;

void Initialize_Q()
{
    first_t=NULL;
    last_t=NULL;
    first_cust=NULL;
    last_cust=NULL;
}

void Add_Time(int seconds)
{
    if(first_t==NULL)
    {
        first_t=(TimeT*)malloc(sizeof(TimeT));
        first_t->sec=seconds;
        first_t->next=last_t;
        last_t=first_t;
    }
    else
    {
        TimeT *newel=(TimeT*)malloc(sizeof(TimeT));
        newel->sec=seconds;
        last_t->next=newel;
        newel->next=NULL;
        last_t=newel;
    }
}

void Add_Customer(int rubles,int seconds)
{
    if(first_cust==NULL)
    {
        first_cust=(CustomerT*)malloc(sizeof(CustomerT));
        first_cust->rubles=rubles;
        first_cust->seconds=seconds;
        first_cust->next=last_cust;
        last_cust=first_cust;
    }
    else
    {
        CustomerT *newel=(CustomerT*)malloc(sizeof(CustomerT));
        newel->rubles=rubles;
        newel->seconds=seconds;
        newel->next=NULL;
        last_cust->next=newel;
        last_cust=newel;
    }
}
int Nr_of_Rubles(int time)
{

    while(first_cust!=NULL && (first_cust->seconds)+seconds<=time)
    {
        seconds+=first_cust->seconds;
        rubles+=first_cust->rubles;
        first_cust=first_cust->next;
    }
    return rubles;
}
