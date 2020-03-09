#include "head.h"
const int MAX_LENTGTH=200;
void initializeList()
{
    first=NULL;
    last=NULL;
}
void AF(int data)
{
    if(first==NULL)
    {
        first=(NodeT*)malloc(sizeof(NodeT));
        first->data=data;
        first->next=last;
        last=first;
    }
    else
    {
        NodeT * newElement=(NodeT*)malloc(sizeof(NodeT));
        newElement->data=data;
        newElement->next=first;
        first->previous=newElement;
        first=newElement;
    }
}
void AL(int data)
{
    if(first==NULL)
    {
        first=(NodeT*)malloc(sizeof(NodeT));
        first->data=data;
        first->next=last;
        first->previous=NULL;
        last=first;
    }
    else
    {
        NodeT * newElement=(NodeT*)malloc(sizeof(NodeT));
        last->next=newElement;
        newElement->data=data;
        newElement->next=NULL;
        newElement->previous=last;
        last=newElement;
    }
}
void DF()
{
    NodeT * currentElement=(NodeT*)malloc(sizeof(NodeT));
    currentElement=first;
    first=first->next;
    first->previous=NULL;
    free(currentElement);

}
void DL()
{
    if(first!=NULL)
    {
        NodeT * currentElement=(NodeT*)malloc(sizeof(NodeT));
        currentElement=first;
        while(currentElement!=last)
        {
            currentElement=currentElement->next;
        }
        last=currentElement->previous;
        last->next=NULL;
        free(currentElement);
    }
}
void DE(int x)
{
    NodeT * currentElement=(NodeT*)malloc(sizeof(NodeT));
    currentElement=first;
    while(currentElement!=NULL)
    {
        if(currentElement->data==x)
        {
            if(currentElement==first)
            {
                first=first->next;
                first->previous=NULL;

            }
            else if(currentElement==last)
            {
                last=last->previous;
                last->next=NULL;
            }
            else
            {
                NodeT * saveElement=currentElement->previous;
                saveElement->next=currentElement->next;
                saveElement=currentElement->next;
                saveElement->previous=currentElement->previous;

            }
            NodeT * saveElement=currentElement->next;
            free(currentElement);
            currentElement=saveElement;
        }
        else
        {
            currentElement=currentElement->next;
        }
    }
}
void PRINT_ALL(FILE * g)
{
    if(first==NULL)
    {
        fprintf(g,"List is empty.\n");
    }
    else
    {
        NodeT * currentElement=(NodeT*)malloc(sizeof(NodeT));
        currentElement=first;
        while(currentElement!=NULL)
        {
            fprintf(g,"%d ",currentElement->data);
            currentElement=currentElement->next;
        }
        fprintf(g,"\n");
    }

}
void PRINT_L(FILE * g,int x)
{
    NodeT * currentElement;
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
void PRINT_F(FILE * g,int x)
{
    NodeT * currentElement=(NodeT*)malloc(sizeof(NodeT));
    currentElement=first;
    int count=0;
    while(currentElement!=NULL && count!=x)
    {
        fprintf(g,"%d ",currentElement->data);
        currentElement=currentElement->next;
        count++;
    }
    fprintf(g,"\n");
}
void DOOM_THE_LIST()
{
    NodeT * currentElement;
    currentElement=first;
    while(currentElement!=NULL)
    {
        first=first->next;
        free(currentElement);
        currentElement=first;
    }
}
void readFile(FILE * f,FILE * g)
{
    char * array=(char*)malloc(sizeof(char)*MAX_LENTGTH);
    char * token=(char*)malloc(sizeof(char)*MAX_LENTGTH);
    while(fgets(array,MAX_LENTGTH,f)!=NULL)
    {

        if(strcmp(array,"DF\n")==0)
        {
            DF();
        }
        else if(strcmp(array,"DL\n")==0)
        {
            DL();
        }
        else if(strcmp(array,"PRINT_ALL\n")==0)
        {
            PRINT_ALL(g);
        }
        else if(strcmp(array,"DOOM_THE_LIST\n")==0)
        {
            DOOM_THE_LIST();
        }
        else
        {
            token=strtok(array," ");
            if(strcmp(array,"AF")==0)
            {
                token=strtok(NULL,"\n");
                int value=atoi(token);
                AF(value);
            }
            else if(strcmp(array,"AL")==0)
            {
                token=strtok(NULL,"\n");
                int value=atoi(token);
                AL(value);
            }
            else if(strcmp(array,"DE")==0)
            {
                token=strtok(NULL,"\n");
                int value=atoi(token);
                DE(value);
            }
            else if(strcmp(array,"PRINT_F")==0)
            {
                token=strtok(NULL,"\n");
                int value=atoi(token);
                PRINT_F(g,value);
            }
            else if(strcmp(array,"PRINT_L")==0)
            {
                token=strtok(NULL,"\n");
                int value=atoi(token);
                PRINT_L(g,value);
            }
        }
    }
}
