#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct node
{
    int data;
    struct node * next;
    struct node *previous;

} ListNode;
typedef struct
{
    ListNode *first, *last;
} Sentinel;

Sentinel T;

const int MAXLENGHT=300;
void initial()
{
    T.first=NULL;
    T.last=NULL;
}



void AF (int x)
{
    ListNode *Element= (ListNode *) malloc (sizeof (ListNode));
    Element->data=x;
    Element->next=T.first;
    Element->previous=NULL;
    if (T.first == NULL)
    {
        T.first = Element;
        T.last=T.first;
    }
    else
    {
        T.first->previous=Element;
        T.first= Element;
    }
}
void AL (int x)
{
    ListNode *Element= (ListNode *) malloc (sizeof (ListNode));
    Element->data=x;
    if(T.first==NULL)
    {
        Element->next=T.first;
        Element->previous=NULL;
        T.first = Element;
        T.last=T.first;
    }
    else
    {
        Element->next=NULL;
        Element->previous=T.last;
        T.last->next=Element;
        T.last=Element;

    }
}
void DF (FILE *g)
{
    ListNode *Element = (ListNode *) malloc (sizeof(ListNode));
    if(T.first!=NULL)
    {
        Element=T.first->next;
        Element->previous=NULL;

        free(T.first);
        T.first=Element;
    }
    else
    {
        fprintf(g,"Impossible to perform the function. Reason: List is empty \n");
    }
}
void DL (FILE*g)
{
    ListNode *Element = (ListNode *) malloc (sizeof(ListNode));
    if(T.first!=NULL)
    {
        Element=T.last->previous;
        Element->next=NULL;

        free(T.last);
        T.last=Element;
    }
    else
        fprintf(g,"Impossible to perform the function. Reason: List is empty \n");

}
void DOOM_THE_LIST()
{
    ListNode *copy = T.first;
    while (copy!=NULL)
    {
        T.first = T.first->next;
        free(copy);
        copy=T.first;
    }
    T.last=T.first;

}
void DE (int x,FILE *g)
{
    ListNode *Element = (ListNode *) malloc (sizeof(ListNode));
    ListNode *copy = (ListNode *) malloc (sizeof(ListNode));
    Element=T.first;
    while(Element!=NULL&&Element->data!=x)
    {
        Element=Element->next;
    }
    if(Element==NULL)
    {
        fprintf(g,"The element %d do not exist in the list \n",x);
    }
    else
    {
        if(Element==T.first)

        {
            DF(g);
        }

        else
        {
            if(Element==T.last)
            {
                DL(g);
            }

            else

            {
                copy=Element->previous;
                copy->next=Element->next;
                Element->previous=copy;
                copy=Element->next;
                copy->previous=Element->previous;
                Element->next=copy;
                free(Element);

            }

        }
    }

}

void PRINT_ALL(FILE *g)
{
    if (T.first==NULL)
        fprintf(g,"The list is empty \n");
    else
    {
        ListNode *CurrentElement;
        CurrentElement=T.first;
        while(CurrentElement != NULL)
        {
            fprintf(g,"%d ",CurrentElement->data);
            CurrentElement=CurrentElement->next;
        }
    }
    fprintf(g,"\n");
}
void PRINT_F (int x,FILE*g)
{
    ListNode *Element = (ListNode *) malloc (sizeof(ListNode));
    Element=T.first;
    int i=0;
    while(Element!=NULL&&i<x)
    {
        fprintf(g,"%d ",Element->data);
        Element=Element->next;
        i++;
    }
    fprintf(g," \n");
}
void PRINT_L (int x,FILE *g)
{
    ListNode *Element = (ListNode *) malloc (sizeof(ListNode));
    Element=T.last;
    while(x!=1)
    {
        Element=Element->previous;
        x--;
    }
    while(Element!=NULL)
    {
        fprintf(g,"%d ",Element->data);
        Element=Element->next;
    }
    fprintf(g," \n");
}
void readInstructions(FILE *f,FILE *g)
{
    int nr;
    char *s=(char *) malloc(sizeof(char)*MAXLENGHT);
    char *p;
    while(fgets(s,MAXLENGHT,f)!=NULL)
    {
        p=strtok(s," \n");

        if(!strcmp(p,"AF"))
        {
            p=strtok(NULL," \n");
            nr=atoi(p);
            AF(nr);

        }
        else if(!strcmp(p,"AL"))
        {
            p=strtok(NULL," \n");
            nr=atoi(p);
            AL(nr);

        }
        else if(!strcmp(p,"DF"))
        {
            DF(g);

        }
        else if(!strcmp(p,"DL"))
        {

            DL(g);

        }
        else if(!strcmp(p,"DOOM_THE_LIST"))
        {

            DOOM_THE_LIST();

        }
        else if(!strcmp(p,"DE"))
        {
            p=strtok(NULL," \n");
            nr=atoi(p);
            DE(nr,g);

        }
        else if(!strcmp(p,"PRINT_ALL"))
        {
            PRINT_ALL(g);
        }
        else if(!strcmp(p,"PRINT_F"))
        {
            p=strtok(NULL," \n");
            nr=atoi(p);
            PRINT_F(nr,g);
        }
        else if(!strcmp(p,"PRINT_L"))
        {
            p=strtok(NULL," \n");
            nr=atoi(p);
            PRINT_L(nr,g);
        }
    }

}



int main()
{
    FILE *f=fopen("input.dat","r+");
    FILE *g=fopen("output.dat","r+");
    initial();
    readInstructions(f,g);

    return 0;
}
