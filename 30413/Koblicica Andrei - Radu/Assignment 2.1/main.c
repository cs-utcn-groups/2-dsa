#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_ROW_LENGTH 15
#define MAX_INSTRUCTIONS 30

typedef struct node_type
{
    int data;
    struct node_type *next;
    struct node_type *previous;
} NodeType;
typedef struct
{
    NodeType *first,*last;
}sentinelType;

sentinelType *sentinel;

void initializeSentinel()
{
    sentinel=(sentinelType*)malloc(sizeof(sentinelType));
    sentinel->first=NULL;
    sentinel->last=NULL;
}
void AF(int n)
{
    if(sentinel->first == NULL)
    {

        sentinel->first = (NodeType*)malloc(sizeof(NodeType));
        sentinel->first->next = sentinel->last;
        sentinel->first->previous=NULL;
        sentinel->first->data = n;
        sentinel->last = sentinel->first;
    }
    else
    {
        NodeType *newElement=(NodeType*)malloc(sizeof(NodeType));
        newElement->data=n;
        newElement->next=sentinel->first;
        sentinel->first->previous=newElement;
        newElement->previous=NULL;
        sentinel->first=newElement;
    }
}
void AL(int n)
{

    if(sentinel->first == NULL)
    {

        sentinel->first = (NodeType*)malloc(sizeof(NodeType));
        sentinel->first->next = sentinel->last;
        sentinel->first->previous=NULL;
        sentinel->first->data = n;
        sentinel->last = sentinel->first;
    }

    else
    {
        NodeType * newElement = (NodeType*)malloc(sizeof(NodeType));
        sentinel->last->next = newElement;
        newElement->next = NULL;
        newElement->previous=sentinel->last;
        newElement->data = n;
        sentinel->last = newElement;
    }
}

void DF()
{
    if(sentinel->first!=NULL)
    {
        NodeType *currentElement=sentinel->first;
        sentinel->first=sentinel->first->next;
        sentinel->first->previous=NULL;
        free(currentElement);
    }
}
void DL()
{
    if(sentinel->last!=NULL)
    {
        NodeType *currentElement=sentinel->last;
        sentinel->last=sentinel->last->previous;
        sentinel->last->next=NULL;
        free(currentElement);
        currentElement=NULL;
    }
}
void DOOM_THE_LIST()
{
    NodeType *currentElement=sentinel->first;
    while(currentElement!=NULL)
    {
        sentinel->first=sentinel->first->next;
        free(currentElement);
        currentElement=sentinel->first;
    }
    initializeSentinel();
}
void DE(int n)
{
    NodeType * currentElement = sentinel->first;
    NodeType * previousElement = sentinel->first;
    while(currentElement!=NULL)
    {
        if(currentElement->data == n)
        {

            if(currentElement == sentinel->first)
            {
                DF();
                currentElement=sentinel->first;

            }
            else if(currentElement == sentinel->last)
            {
                DL();
                currentElement=NULL;
            }
            else
            {
                currentElement->previous->next=currentElement->next;
                currentElement->next->previous=currentElement->previous;
                free(currentElement);
                currentElement=previousElement->next;
            }

        }
        else
        {
            previousElement=currentElement;
            currentElement=currentElement->next;
        }

    }
}
void PRINT_ALL(FILE *g)
{
    if(sentinel->first!=NULL)
    {
        NodeType *currentElement=sentinel->first;
        while(currentElement!=NULL)
        {

            fprintf(g,"%d ",currentElement->data);
            currentElement=currentElement->next;
        }
    }
    fprintf(g,"\n");
}
void PRINT_F(int n,FILE *g)
{
    NodeType * currentElement = sentinel->first;
    for(int i=0; i<n&&currentElement!=NULL; i++)
    {
        fprintf(g,"%d ",currentElement->data);
        currentElement=currentElement->next;
    }
    fprintf(g,"\n");
}
void PRINT_L(int n,FILE *g)
{
    int nrOfElements=0;
    NodeType * currentElement = sentinel->first;
    sentinel->last->next=NULL;
    while(currentElement!=NULL)
    {
        nrOfElements++;
        currentElement=currentElement->next;
    }
    if(n>=nrOfElements)
    {
        PRINT_ALL(g);
    }
    else
    {
        currentElement = sentinel->first;
        for(int i=0; i<(nrOfElements-n); i++)
        {
            currentElement=currentElement->next;
        }
        while(currentElement!=NULL)
        {
            fprintf(g,"%d ",currentElement->data);
            currentElement=currentElement->next;
        }
        fprintf(g,"\n");
    }
}
void executeInstructions(char *p, int n,FILE *g)
{
    if(strcmp(p,"AF")==0)
    {
        AF(n);
    }
    else if(strcmp(p,"AL")==0)
    {
        AL(n);
    }
    else if(strcmp(p,"DF")==0)
    {
        DF();
    }
    else if(strcmp(p,"DL")==0)
    {
        DL();
    }
    else if(strcmp(p,"DOOM_THE_LIST")==0)
    {
        DOOM_THE_LIST();
    }
    else if(strcmp(p,"DE")==0)
    {
        DE(n);
    }
    else if(strcmp(p,"PRINT_ALL")==0)
    {
        PRINT_ALL(g);
    }
    else if(strcmp(p,"PRINT_F")==0)
    {
        PRINT_F(n,g);
    }
    else if(strcmp(p,"PRINT_L")==0)
    {
        PRINT_L(n,g);
    }
    else
        fprintf(g,"Wrong input");
}
void readAndExecute(FILE *f,FILE *g)
{
    char *strbuf=(char*)malloc(sizeof(char)*MAX_ROW_LENGTH);
    while(fgets(strbuf,MAX_INSTRUCTIONS,f))
    {
        char *p;
        p=strtok(strbuf," \n");
        char *str=(char*)malloc(sizeof(char)*MAX_ROW_LENGTH);
        strcpy(str,p);
        p=strtok(NULL,"\n");
        int n;
        if(p)
        {
            n=atoi(p);
        }

        executeInstructions(str,n,g);
    }

}

int main()
{
    FILE *f=fopen("input.dat","r");
    FILE *g=fopen("output.dat","w");
    initializeSentinel();
    readAndExecute(f,g);
    return 0;
}
