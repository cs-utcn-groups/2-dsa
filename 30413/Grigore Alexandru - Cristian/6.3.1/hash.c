#include "hash.h"

int f(char *key)
{
    int sum=0;
    for(int i=0;i<strlen(key);i++)
    {
        sum+=key[i];
    }
    return (sum%B);
}

NodeT *findNode(char *key)
{
    NodeT *p=(NodeT*)malloc(sizeof(NodeT));
    int h=f(key);
    p=Table[h];
    while(p!=NULL)
    {
        if(strcmp(key,p->name)==0)
        {
            return p;
        }
        p=p->next;
    }
    return NULL;
}

NodeT *insertNode(char *key)
{
    NodeT *p=(NodeT*)malloc(sizeof(NodeT));
    int h=f(key);
    if(p)
    {
        strcpy(p->name,key);
        p->next=NULL;
        if(Table[h]==NULL)
        {
            Table[h]=p;
            p->next=NULL;
        }
    }
    else
    {
        NodeT *q=(NodeT*)malloc(sizeof(NodeT));
        q=findNode(p->name);
        if(q==0)
        {
            p->next=Table[h];
            Table[h]=p;
        }
    }
    return p;
}

void deleteNode(char *key)
{
    int h=f(key);
    if(Table[h])
    {
        NodeT *p;
        p=Table[h];
        while(p)
        {
            if(strcmp(p->name,key)==0)
            {
                NodeT *aux=p;
                p=p->next;
                free(aux);
                Table[h]=NULL;
            }
        }
    }
}

void printBucket()
{
    NodeT *p=(NodeT*)malloc(sizeof(NodeT));
    for(int i=0;i<B;i++)
    {
        if(Table[i]!=NULL)
        {
            printf("\nBucket for hash value %d\n",i);
            p=Table[i];
            while(p!=NULL)
            {
                printf("%s",p->name);
                p=p->next;
            }
        }
    }
}
