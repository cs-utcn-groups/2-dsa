#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_ROW_LENGTH 15
#define MAX_INSTRUCTIONS 30

typedef struct node_type
{
    int data;
    struct node_type *next;
} NodeT;

NodeT *first,*last;

void initializeList()
{
    first=NULL;
    last=NULL;
}
void AF(int n)
{
    if(first == NULL)
    {

        first = (NodeT*)malloc(sizeof(NodeT));
        first->next = last;
        first->data = n;
        last = first;
    }
    else
    {
        NodeT *newElement=(NodeT*)malloc(sizeof(NodeT));
        newElement->data=n;
        newElement->next=first;
        first=newElement;
    }
}
void AL(int n)
{

    if(first == NULL)
    {

        first = (NodeT*)malloc(sizeof(NodeT));
        first->next = last;
        first->data = n;
        last = first;
    }

    else
    {
        NodeT * newElement = (NodeT*)malloc(sizeof(NodeT));
        last->next = newElement;
        newElement->next = NULL;
        newElement->data = n;
        last = newElement;
    }
}

void DF()
{
    if(first!=NULL)
    {
        NodeT *currentElement=first;
        first=first->next;
        free(currentElement);
    }
}
void DL()
{
    if(last!=NULL)
    {
        NodeT *currentElement=first;
        NodeT *previousElement=first;
        while(currentElement!=NULL)
        {
            if(currentElement==last)
            {
                last=previousElement;
                currentElement=NULL;
                free(currentElement);
                previousElement->next=NULL;
            }
            else
            {
                previousElement=currentElement;
                currentElement=currentElement->next;
            }
        }
    }
}
void DOOM_THE_LIST()
{
    NodeT *currentElement=first;
    while(currentElement!=NULL)
    {
        first=first->next;
        free(currentElement);
        currentElement=first;
    }
    initializeList();
}
void DE(int n)
{
    NodeT * currentElement = first;
    NodeT * previousElement= first;
    while(currentElement != NULL)
    {
        if(currentElement->data == n)
        {
            if(currentElement == first)
            {
                first = first->next;
            }
            else if(currentElement == last)
            {
                last = previousElement;
                last->next = NULL;
            }
            else
            {
                previousElement->next = currentElement->next;
            }
            previousElement = currentElement;
            currentElement = currentElement->next;
            free(previousElement);
            previousElement = currentElement;
        }
        else
        {
            previousElement = currentElement;
            currentElement = currentElement->next;
        }

    }
}
void PRINT_ALL()
{
    if(first!=NULL)
    {
        NodeT *currentElement=first;
        while(currentElement!=NULL)
        {

            printf("%d ",currentElement->data);
            currentElement=currentElement->next;
        }
    }
    printf("\n");
}
void PRINT_F(int n)
{
    NodeT * currentElement = first;
    for(int i=0; i<n&&currentElement!=NULL; i++)
    {
        printf("%d ",currentElement->data);
        currentElement=currentElement->next;
    }
    printf("\n");
}
void PRINT_L(int n)
{
    int nrOfElements=0;
    NodeT * currentElement = first;
    last->next=NULL;
    while(currentElement!=NULL)
    {
        nrOfElements++;
        currentElement=currentElement->next;
    }
    if(n>=nrOfElements)
    {
        PRINT_ALL();
    }
    else
    {
        currentElement = first;
        for(int i=0; i<(nrOfElements-n); i++)
        {
            currentElement=currentElement->next;
        }
        while(currentElement!=NULL)
        {
            printf("%d ",currentElement->data);
            currentElement=currentElement->next;
        }
        printf("\n");
    }
}
void executeInstructions(char *p, int n)
{
    if(strcmp(p,"AF")==0)
    {
        AF(n);
    }
    if(strcmp(p,"AL")==0)
    {
        AL(n);
    }
    if(strcmp(p,"DF")==0)
    {
        DF();
    }
    if(strcmp(p,"DL")==0)
    {
        DL();
    }
    if(strcmp(p,"DOOM_THE_LIST")==0)
    {
        DOOM_THE_LIST();
    }
    if(strcmp(p,"DE")==0)
    {
        DE(n);
    }
    if(strcmp(p,"PRINT_ALL")==0)
    {
        PRINT_ALL();
    }
    if(strcmp(p,"PRINT_F")==0)
    {
        PRINT_F(n);
    }
    if(strcmp(p,"PRINT_L")==0)
    {
        PRINT_L(n);
    }
}

int main()
{
    FILE *f=fopen("input.dat","r");
    char *strbuf=(char*)malloc(sizeof(char)*MAX_ROW_LENGTH);
    initializeList();
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
        executeInstructions(str,n);

    }

    return 0;
}
