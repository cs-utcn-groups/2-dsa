#include "head.h"

void Initialize_Dll()
{
    sentinel=(sentinell*)malloc(sizeof(sentinell));
    sentinel->first=NULL;
    sentinel->last=NULL;
}

void Add_first(int x)
{
    if(sentinel->first==NULL)
    {
       sentinel->first=(NodeT*)malloc(sizeof(NodeT));
        sentinel->first->data=x;
        sentinel->first->next=sentinel->last;
        sentinel->first->previous=NULL;
        sentinel->last=sentinel->first;
    }
    else
    {
        NodeT *newel=(NodeT*)malloc(sizeof(NodeT));
        newel->data=x;
        newel->next=sentinel->first;
        newel->previous=NULL;
        sentinel->first->previous=newel;
        sentinel->first=newel;
    }
}

void Add_last(int x)
{
    if(sentinel->first==NULL)
    {
        sentinel->first=(NodeT*)malloc(sizeof(NodeT));
        sentinel->first->data=x;
        sentinel->first->next=sentinel->last;
        sentinel->first->previous=NULL;
        sentinel->last=sentinel->first;
    }
    else
    {
        NodeT *newel=(NodeT*)malloc(sizeof(NodeT));
        sentinel->last->next=newel;
        newel->data=x;
        newel->next=NULL;
        newel->previous=sentinel->last;
        sentinel->last=newel;
    }
}

void Delete_first()
{
    if(sentinel->first==NULL)
        return;
    sentinel->first=sentinel->first->next;
    sentinel->first->previous=NULL;
}

void Delete_last()
{//
    if(sentinel->last==NULL)
        return;
    NodeT *current=(NodeT*)malloc(sizeof(NodeT));
    current=sentinel->last->previous;
    current->next=NULL;
    free(sentinel->last);
    sentinel->last=current;
}
void Delete_all()
{
    NodeT *current=(NodeT *)malloc(sizeof(NodeT));
    current=sentinel->first;
    while(current!=NULL)
    {
        sentinel->first=sentinel->first->next;
        free(current);
        current=sentinel->first;
    }
    sentinel->last=NULL;

}

void Delete_el(int x)
{//
    NodeT *current=(NodeT*)malloc(sizeof(NodeT));
    NodeT *prev=(NodeT*)malloc(sizeof(NodeT));
    current=sentinel->first;
    while(current!=NULL && current->data!=x)
    {
        current=current->next;
    }
    if(current==NULL)
        return;
    else
    {
        if(current==sentinel->first)
        {
            Delete_first();
        }
        else
        {
            if(current==sentinel->last)
            {
                Delete_last();
            }
            else
            {
                prev=current->previous;
                prev->next=current->next;
                current->previous=prev;
                prev=current->next;
                prev->previous=current->previous;
                current->next=prev;
                free(current);
            }
        }
    }
}

void Print_all(FILE *g)
{
    NodeT *current=(NodeT*)malloc(sizeof(NodeT));
    current=sentinel->first;
    while(current!=NULL)
    {
        fprintf(g,"%d ",current->data);
        current=current->next;
    }
    fprintf(g,"\n");
}
void Print_f(int x,FILE *g)
{
    NodeT *current=(NodeT*)malloc(sizeof(NodeT));
    current=sentinel->first;
    for(int i=0; i<x && current!=NULL;i++)
    {
        fprintf(g,"%d ",current->data);
        current=current->next;
    }
    fprintf(g,"\n");

}
void Print_l(int x,FILE *g)
{
    NodeT *current=sentinel->first;
    int nr=0;
    sentinel->last->next=NULL;
    while(current!=NULL)
    {
        nr++;
        current=current->next;
    }
    if(x>=nr)
    {
        Print_all(g);
    }
    else
        {
            current=sentinel->first;
            for(int i=0;i<(nr-x);i++)
            {
                current=current->next;
            }
            while(current!=NULL)
            {
                fprintf(g,"%d ",current->data);
                current=current->next;
            }
            fprintf(g,"\n");
        }
}

