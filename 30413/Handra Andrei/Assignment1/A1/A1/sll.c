#include "head.h"


void InitializeSLL()
{
    first=NULL;
    last=NULL;

}

void print_all(FILE *g)
{
    if(first==NULL)
    {
        fprintf(g,"List is empty");

    }
    else
    {
        NodeT *currentel=first;
        while(currentel!=NULL)
        {
            fprintf(g,"%d ",currentel->data);
            currentel=currentel->next;

        }
        fprintf(g,"\n");
    }
}
void print_f(int n,FILE *g)
{
     if(first==NULL)
    {
        fprintf(g,"List is empty");

    }
    else
    {
        NodeT *currentel=first;
        for(int i=0;i<n && currentel!=NULL;i++)
        {
            fprintf(g,"%d ",currentel->data);
            currentel=currentel->next;

        }
        fprintf(g,"\n");
    }
}
void print_l(int n,FILE *g)
{
    int NrElements=0;
    NodeT *current=first;
    last->next=NULL;
    while(current!=NULL)
    {
        NrElements++;
        current=current->next;
    }
    if(n>=NrElements)
    {
        print_all(g);
    }
    else
    {
        current=first;
        for(int i=0;i<(NrElements-n);i++)
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
void doom_list()
{
    NodeT *currentel=first;
    while(currentel!=NULL)
    {
        first=first->next;
        free(currentel);
        currentel=first;
    }
}
void add_first(int key)
{
    if(first==NULL)
    {
        first=(NodeT*)malloc(sizeof(NodeT));
        first->data=key;
        first->next=last;
        last=first;
    }
    else
    {
        NodeT *newel=(NodeT*)malloc(sizeof(NodeT));
        newel->data=key;
        newel->next=first;
        first=newel;

    }
}
void add_last(int key)
{
    if(first==NULL)
    {
        first=(NodeT*)malloc(sizeof(NodeT));
        first->data=key;
        first->next=last;
        last=first;
    }
    else
    {
        NodeT *newel=(NodeT*)malloc(sizeof(NodeT));
        last->next=newel;
        newel->data=key;
        newel->next=NULL;
        last=newel;
    }
}

void Delete_first()
{
    if(first==NULL)
    {
        return;
    }
    first = first->next;
}
void Delete_Last()
{
    if(first==NULL)
    {
        return;
    }

    if(first!=NULL)
    {
        NodeT *current = (NodeT *) malloc (sizeof(NodeT));
        current=first;
        while(current->next!=last)
        {
            current=current->next;
        }
        free(last);
        last=current;
        last->next=NULL;
    }

}
void DE(int x)
{
    NodeT *previous=first;
    NodeT *current=first;
    while(current!=NULL)
    {
        if(current->data==x)
        {
            if(current==first)
            {
                first=first->next;
            }
            else if(current==last)
            {
                last=previous;
                last->next=NULL;
            }
            else
            {
                previous->next=current->next;
            }
            previous=current;
            current=current->next;
            free(previous);
            previous = current;
        }
        else
        {
            previous = current;
            current = current->next;
        }
    }
}
