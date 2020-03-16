//
// Created by TheRa on 3/3/2020.
//

#include "queue.h"
#include <stdio.h>
#include <stdlib.h>

void initialize()
{
    first = (NodeT *)malloc(sizeof(NodeT));
    last = (NodeT *)malloc(sizeof(NodeT));
}

void add(char name[25], int money, int time, int *timePassed, int *moneyCollected)
{
    p=(NodeT *)malloc(sizeof(NodeT));
    p->money=money;
    p->time=time;
    if(first==NULL)
    {
        p->next=NULL;
        first=p;
        last=p;
    }
    else
    {
        p->next=first;
        first=p;
    }
    *timePassed+=time;
    *moneyCollected+=money;
}
