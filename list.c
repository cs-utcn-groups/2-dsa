#include "head.h"
const int MAX_LENGTH=200;
void initializeList()
{
    first = NULL;
    last = NULL;
}

void AF(int data)
{
    if(first==NULL)
    {
        first=(NodeT*)malloc(sizeof(NodeT));
        first->next=last;
        first->data=data;
        last=first;
    }
    else
    {
        NodeT * newElement=(NodeT*)malloc(sizeof(NodeT));
        newElement->data=data;
        newElement->next=first;
        first=newElement;
    }
}
void AL(int data)
{
    if(first==NULL)
    {
        first=(NodeT*)malloc(sizeof(NodeT));
        first->next=last;
        first->data=data;
        last=first;
    }
    else
    {
        NodeT * newElement=(NodeT*)malloc(sizeof(NodeT));
        last->next=newElement;
        newElement->next=NULL;
        newElement->data=data;
        last=newElement;
    }
}
void DE(int x)
{
    NodeT * currentElement=first;
    NodeT * previousElement=first;
    while(currentElement!=NULL)
    {
        if(currentElement->data==x)
        {
            if(currentElement==first)
            {
                first=first->next;
            }
            else if(currentElement==last)
            {
                last=previousElement;
                last->next=NULL;
            }
            else
            {
                previousElement->next=currentElement->next;
            }
            previousElement=currentElement;
            currentElement=currentElement->next;
            free(previousElement);
            previousElement=currentElement;
        }
        else
        {
            previousElement=currentElement;
            currentElement=currentElement->next;
        }

    }
}
void DF()
{
    NodeT * currentElement=(NodeT*)malloc(sizeof(NodeT));
    currentElement=first;
    first=first->next;
    free(currentElement);
}
void DL()
{
    if(first!=NULL)
    {
        NodeT * currentElement=(NodeT*)malloc(sizeof(NodeT));
        NodeT * previousElement=(NodeT*)malloc(sizeof(NodeT));
        currentElement=first;
        previousElement=first;
        while(currentElement!=last)
        {
            previousElement=currentElement;
            currentElement=currentElement->next;
        }
        last=previousElement;
        last->next=NULL;
    }
}
void DOOM_THE_LIST()
{
    NodeT * currentElement=first;
    while(currentElement!=NULL)
    {
        first=first->next;
        free(currentElement);
        currentElement=first;
    }
}
void PRINT_F(int x,FILE * g)
{
    NodeT * currentElement=(NodeT*)malloc(sizeof(NodeT));
    currentElement=first;
    int i=0;
    while(currentElement!=NULL && i!=x)
    {
        fprintf(g,"%d ",currentElement->data);
        currentElement=currentElement->next;
        i++;
    }
    fprintf(g,"\n");
}
void PRINT_L(int x,FILE * g)
{
    NodeT * currentElement=(NodeT*)malloc(sizeof(NodeT*));
    currentElement=first;
    int count=0;
    while(currentElement!=NULL)
    {
        count++;
        currentElement=currentElement->next;
    }
    currentElement=first;
    for(int i=0; i<count-x; i++)
    {
        currentElement=currentElement->next;
    }
    for(int i=count-x; i<count; i++)
    {
        fprintf(g,"%d ",currentElement->data);
        currentElement=currentElement->next;
    }
    fprintf(g,"\n");
}
void PRINT_ALL(FILE * g)
{
    if(first==NULL)
    {
        fprintf(g,"List is empty!\n");
    }
    else
    {
        NodeT * currentElement=first;
        while(currentElement!=NULL)
        {
            fprintf(g,"%d ", currentElement->data);
            currentElement=currentElement->next;
        }
        fprintf(g,"\n");
    }
}

void readFile(FILE * f,FILE * g)
{
    char * array=(char*)malloc(sizeof(char)*MAX_LENGTH);
    char * token=(char*)malloc(sizeof(char));
    while(fgets(array,MAX_LENGTH,f)!=NULL)
    {
        if(strcmp(array,"DL\n")==0)
        {
            DL();
        }
        else if(strcmp(array,"DF\n")==0)
        {
            DF();
        }
        else if(strcmp(array,"DOOM_THE_LIST\n")==0)
        {
            DOOM_THE_LIST();
        }
        else if(strcmp(array,"PRINT_ALL\n")==0)
        {
            PRINT_ALL(g);
        }
        else
        {
            token=strtok(array," ");
            if(strcmp(token,"AF")==0)
            {
                token=strtok(NULL,"\n");
                int nr=atoi(token);
                AF(nr);
            }
            else if(strcmp(token,"AL")==0)
            {
                token=strtok(NULL,"\n");
                int nr=atoi(token);
                AL(nr);
            }
            else if(strcmp(token,"DE")==0)
            {
                token=strtok(NULL,"\n");
                int nr=atoi(token);
                DE(nr);
            }
            else if(strcmp(token,"PRINT_F")==0)
            {
                token=strtok(NULL,"\n");
                int nr=atoi(token);
                PRINT_F(nr,g);
            }
            else if(strcmp(token,"PRINT_L")==0)
            {
                token=strtok(NULL,"\n");
                int nr=atoi(token);
                PRINT_L(nr,g);
            }
        }
    }
}
