#include "head.h"

SentinelT *Sentinel;

void initializeDll()
{
    Sentinel=(SentinelT*)malloc(sizeof(SentinelT));
    Sentinel->first=NULL;
    Sentinel->last=NULL;
}

void AF(int key)
{
    if(Sentinel==NULL)
    {
        return;
    }
    if(Sentinel->first == NULL)
    {
        Sentinel->first = (NodeT*)malloc(sizeof(NodeT));
        Sentinel->first->data = key;
        Sentinel->first->next = NULL;
        Sentinel->first->prev = NULL;
        Sentinel->last = Sentinel->first;
    }
    else
    {
        NodeT * newElement = (NodeT*)malloc(sizeof(NodeT));
        newElement->data = key;
        newElement->prev=NULL;
        newElement->next = Sentinel->first;
        Sentinel->first->prev=newElement;
        Sentinel->first = newElement;
    }
}

void AL(int key)
{
    if(Sentinel==NULL)
    {
        return;
    }
    if(Sentinel->first == NULL)
    {
        Sentinel->first = (NodeT*)malloc(sizeof(NodeT));
        Sentinel->first->data = key;
        Sentinel->first->next = NULL;
        Sentinel->first->prev = NULL;
        Sentinel->last = Sentinel->first;
    }
    else
    {
        NodeT * newElement = (NodeT*)malloc(sizeof(NodeT));
        Sentinel->last->next = newElement;
        newElement->data = key;
        newElement->next = NULL;
        newElement->prev = Sentinel->last;
        Sentinel->last = newElement;
    }
}

void DF()
{
    if(Sentinel==NULL || Sentinel->first==NULL)
    {
        return;
    }
    if(Sentinel->first->next==NULL)
    {
        free(Sentinel->first);
        Sentinel->first=Sentinel->last=NULL;
    }
    else
    {
        NodeT *newElement = Sentinel->first;
        Sentinel->first = Sentinel->first->next;
        free(newElement);
        Sentinel->first->prev=NULL;
    }
}

void DL()
{
    if(Sentinel==NULL || Sentinel->first==NULL)
    {
        return;
    }
    if(Sentinel->first->next==NULL)
    {
        free(Sentinel->first);
        Sentinel->first=Sentinel->last=NULL;
    }
    else
    {
        NodeT *newElement=Sentinel->last;
        Sentinel->last=newElement->prev;
        free(newElement);
        Sentinel->last->next=NULL;
    }
}

void DE(int key)
{
    if(Sentinel==NULL || Sentinel->first==NULL)
    {
        return;
    }
    if(Sentinel->first->next==NULL)
    {
        free(Sentinel->first);
        Sentinel->first=Sentinel->last=NULL;
    }
    else
    {
        NodeT *newElement=Sentinel->first;
        while(newElement->data==key)
        {
            DF();
            newElement=Sentinel->first;
        }
        newElement=newElement->next;
        if(Sentinel->first==NULL)
        {
            Sentinel->last=NULL;
        }
        while(newElement)
        {
            if(newElement->data==key)
            {
                NodeT *anotherElement=newElement;
                newElement->prev->next=newElement->next;
                newElement->next->prev=newElement->prev;
                newElement=newElement->next;
                if(anotherElement==Sentinel->last)
                {
                    Sentinel->last=anotherElement->prev;
                }
                free(anotherElement);
            }
            if(newElement)
            {
                newElement=newElement->next;
            }
        }
    }
}

void print_All(FILE *o)
{
    if(Sentinel==NULL || Sentinel->first==NULL)
    {
        fprintf(o,"List is empty!\n");
    }
    else
    {
        NodeT * currentElement = Sentinel->first;
        while(currentElement != NULL)
        {
            fprintf(o,"%d ", currentElement->data);
            currentElement = currentElement->next;
        }
        fprintf(o,"\n");
    }

}

void PRINT_F(int nr,FILE *o)
{
    if(Sentinel==NULL || Sentinel->first==NULL)
    {
        fprintf(o,"List is doomed.\n");
    }
    else
    {
        NodeT *currentNode=Sentinel->first;
        for(int i=0;i<nr && currentNode!=NULL;i++)
        {
            fprintf(o,"%d ",currentNode->data);
            currentNode=currentNode->next;
        }
        fprintf(o,"\n");
    }
}

void PRINT_L(int nr,FILE *o)
{
    if(Sentinel==NULL || Sentinel->first==NULL)
    {
        fprintf(o,"List is doomed.\n");
    }
    else
    {
        int nrOfElements=0;
         NodeT *currentNode=Sentinel->first;
         while(currentNode!=NULL)
         {
             nrOfElements++;
             currentNode=currentNode->next;
         }
         if(nrOfElements<=nr)
         {
             print_All(o);
         }
         else
         {
             currentNode=Sentinel->first;
             int i=0;
             while(i<nrOfElements-nr)
             {
                 currentNode=currentNode->next;
                 i++;
             }
             while(currentNode!=NULL)
             {
                 fprintf(o,"%d ",currentNode->data);
                 currentNode=currentNode->next;
             }
             fprintf(o,"\n");
         }
    }
}

void DOOM_THE_LIST()
{
    NodeT *currentElement =(NodeT*)malloc(sizeof(NodeT));
    currentElement=Sentinel->first;
    while(currentElement != NULL)
    {
        Sentinel->first = Sentinel->first->next;
        free(currentElement);
        currentElement = Sentinel->first;
    }
}

