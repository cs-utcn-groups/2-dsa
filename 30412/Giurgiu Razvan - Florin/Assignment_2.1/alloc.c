//
// Created by TheRa on 2/26/2020.
//

#include "alloc.h"


void startSll()
{
    lists.first=(NodeT*)malloc(sizeof(NodeT));
    lists.last=(NodeT*)malloc(sizeof(NodeT));
    lists.first=NULL;
    lists.last=NULL;
}

void af(int data)
{
    p=(NodeT*)malloc(sizeof(NodeT));
    p->data=data;
    if(lists.first==NULL)
    {
        lists.first=p;
        lists.first->next=NULL;
        lists.first->prev=NULL;
        lists.last=lists.first;
    }
    else if(lists.first==lists.last)
    {
        p->next=lists.last;
        lists.last->prev=p;
        p->prev=NULL;
        lists.first=p;
    }
    else
    {
        p->next=lists.first;
        lists.first->prev=p;
        lists.first=p;
    }

}

void al(int data)
{
    p=(NodeT*)malloc(sizeof(NodeT));
    p->data=data;
    if(lists.last==NULL)
    {
        lists.last=p;
        lists.last->next=NULL;
        lists.last->prev=NULL;
        lists.first=lists.last;
    }
    else {
        lists.last->next = p;
        p->prev=lists.last;
        lists.last = p;
        lists.last->next = NULL;
    }

}

void df()
{
    if(lists.first == NULL) return;
    p=lists.first;
    lists.first=lists.first->next;
    lists.first->prev=NULL;
    p->next=NULL;
    p->prev=NULL;
    free(p);
}

void dl()
{
    p=lists.last;
    if(p!=NULL)
    {
        if(p==lists.first)
        {
            free(lists.first);
        }
        else
        {
            lists.last=lists.last->prev;
            lists.last->next=NULL;
            free(p);
        }
    }
}

void doom()
{
    NodeT * q;
    p=lists.first;
    while(p!=lists.last)
    {
        q=p;
        p=p->next;
        p->prev=NULL;
        free(q);

    }
    lists.last=lists.first=NULL;
}

void d_spec(int data)
{
    p=lists.first;
    NodeT *prev=NULL;
    if(lists.first==lists.last && lists.first->data==data)
        lists.first=lists.last=NULL;

    if(lists.first->data == data)
        lists.first=lists.first->next;
    else
    while(p!=NULL)
    {
        if(p->data==data)
        {
            prev->next=p->next;

        }
        prev=p;
        p=p->next;
    }
    free(p);

}

void print_f_x(FILE *f,int x)
{
    p=lists.first;
    int c=1;
    while(p!=NULL && c<=x)
    {
        fprintf(f,"%d ",p->data);
        p=p->next;
        c++;
    }
    fprintf(f,"\n");
}

void print_l_x(FILE *f,int data)
{
    p=lists.last;
    int c=0;
    while(p && c<data)
    {
        fprintf(f,"%d ",p->data);
        p=p->prev;
        c++;
    }
    fprintf(f,"\n");
}

void print_all(FILE *f)
{
    p=lists.first;
    while(p!=NULL)
    {
        fprintf(f,"%d ",p->data);
        p=p->next;
    }
    fprintf(f,"\n");
}


