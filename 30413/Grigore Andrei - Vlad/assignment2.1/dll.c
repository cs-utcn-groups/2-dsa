#include "head.h"

void initializeDll()
{
    san=(Sentinel*)malloc(sizeof(Sentinel));
    san->first=NULL;
    san->last=NULL;
}

void AF(int data)
{
    if(san==NULL)
    {
        return;
    }
    if(san->first==NULL)
    {
        san->first=(NodeT*)malloc(sizeof(NodeT));
        san->first->data=data;
        san->first->next=NULL;
        san->first->prev=NULL;
        san->last=san->first;
    }
    else
    {
        NodeT *newEl=(NodeT*)malloc(sizeof(NodeT));
        newEl->data=data;
        newEl->prev=NULL;
        newEl->next=san->first;
        san->first->prev=newEl;
        san->first=newEl;

    }

}

void AL(int data)
{
    if(san==NULL)
    {
        return;
    }
    if(san->first==NULL)
    {
        san->first=(NodeT*)malloc(sizeof(NodeT));
        san->first->next=NULL;
        san->first->prev=NULL;
        san->first->data=data;
        san->last=san->first;
    }
    else
    {
        NodeT *newEl=(NodeT*)malloc(sizeof(NodeT));
        san->last->next=newEl;
        newEl->data=data;
        newEl->next=NULL;
        newEl->prev=san->last;
        san->last=newEl;
    }

}
void DF()
{
    if(san==NULL||san->first==NULL)
    {
        return;
    }
    if(san->first->next==NULL)
    {
        free(san->first);
        san->first=san->last=NULL;
    }
    else
    {
        NodeT *Node=san->first;
        san->first=san->first->next;
        free(Node);
        san->first->prev=NULL;
    }
}
void DL()
{
    if(san==NULL || san->first==NULL)
    {
        return;
    }
    if(san->first->next==NULL)
    {
        free(san->first);
        san->first=san->last=NULL;
    }
    else
    {
        NodeT *Node=san->last;
        san->last=Node->prev;
        free(Node);
        san->last->next=NULL;
    }

}
void DE(int value)
{
    if(san==NULL || san->first==NULL)
    {
        return;
    }
    if(san->first->next==NULL)
    {
        free(san->first);
        san->first=san->last=NULL;
    }
    else
    {
        NodeT *p=san->first;
        while(p && p->data==value)
        {
            DF();
            p=san->first;
        }
        p=p->next;
        if(san->first==NULL)
        {
            san->last=NULL;
        }
        while(p)
        {
            if(p->data==value)
            {
                NodeT *q=p;
                p->prev->next=p->next;
                p->next->prev=p->prev;
                p=p->next;
                if(q==san->last)

                {
                    san->last=q->prev;
                }
                free(q);

            }
            if(p)
            {
                p=p->next;
            }
        }
    }


}
void PRINT_ALL(FILE *o)
{
    NodeT *p=san->first;
    while(p)
    {
        fprintf(o,"%d ",p->data);
        p=p->next;
    }
    fprintf(o,"\n");
}
void PRINT_L(int nr,FILE *o)
{
    if(san->first==NULL)
    {
        fprintf(o,"List is doomed.\n");
    }
    else
    {
        int nrOfElements=0;
         NodeT *currentNode=san->first;
         while(currentNode!=NULL)
         {
             nrOfElements++;
             currentNode=currentNode->next;
         }
         if(nrOfElements<=nr)
         {
             PRINT_ALL(o);
         }
         else
         {
             currentNode=san->first;
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
void PRINT_F(int value,FILE *o)
{
    NodeT *p=san->first;
    for(int i=0;i<value;i++)
    {
        fprintf(o,"%d ",p->data);
        p=p->next;
    }
    fprintf(o,"\n");

}
void DOOM_THE_LIST()
{
    NodeT *p=san->first;
    while(p)
    {
        san->first=san->first->next;
        free(p);
        p=san->first;
    }

}

