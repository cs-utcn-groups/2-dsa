#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct node{
    int data;
    struct node * next;

}ListNode;

ListNode *first, *last;

const int MAXLENGHT=300;
void initial()
{
    first=NULL;
    last=NULL;
}



void AF (int x)
{
    if(first == NULL)
    {   first=(ListNode *) malloc (sizeof(ListNode));
        first->data=x;
        first->next=last;
        last=first;
    }
    else
    {
        ListNode *NewElement=(ListNode *) malloc (sizeof(ListNode));
        NewElement->data=x;
        NewElement->next=first;
        first=NewElement;
    }
}
void AL (int x)
{
    if(first==NULL)
    {
        first=(ListNode *) malloc (sizeof(ListNode));
        first->data=x;
        first->next=last;
        last=first;
    }
    else
    {
        ListNode *NewElement= (ListNode *) malloc (sizeof (ListNode));
        NewElement->data=x;
        last->next=NewElement;
        NewElement->next=NULL;
        last=NewElement;
    }
}
void DF (FILE *g)
{
    if(first!=NULL)
    {
        ListNode * copy;
        copy=first->next;
        free(first);
        first=copy;

    }
    else fprintf(g,"Impossible to perform the function. Reason: List is empty \n");
}
void DL (FILE*g)
{   if(first!=NULL)
    {
        ListNode *Element = (ListNode *) malloc (sizeof(ListNode));
        Element=first;
        while(Element->next!=last)
        {
            Element=Element->next;
        }
        free(last);
        last=Element;
        last->next=NULL;
    }
    else fprintf(g,"Impossible to perform the function. Reason: List is empty \n");

}
void DOOM_THE_LIST()
{
    ListNode *copy = first;
    while (copy!=NULL)
    {
        first = first->next;
        free(copy);
        copy=first;
    }
    last=first;

}
void DE (int x,FILE *g)
{
    if(first!=NULL)
    {
        ListNode *PreviousElement = (ListNode *) malloc (sizeof(ListNode));
        ListNode *CurrentElement = (ListNode *) malloc (sizeof(ListNode));
        PreviousElement=first;
        CurrentElement=first;
        while(PreviousElement!=last&&CurrentElement->data!=x)
        {
            PreviousElement=CurrentElement;
            CurrentElement=CurrentElement->next;
        }

        if(PreviousElement!=last)
        {
            if(CurrentElement==first)
                DF(g);
            else if(CurrentElement==last)
                DL(g);
            else {PreviousElement->next=CurrentElement->next;
                free(CurrentElement);
            }

        }
    }

}

void PRINT_ALL(FILE *g)
{   if (first==NULL)
        printf("The list is empty");
    else
    {
        ListNode *CurrentElement;
        CurrentElement=first;
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
    int i=0;
    ListNode *Element;
    Element=first;
    while(Element!=NULL && i<x)
    {
        fprintf(g,"%d ",Element->data);
        Element=Element->next;
        i++;
    }
    fprintf(g,"\n");
}
void PRINT_L (int x,FILE *g)
{   //Tricky because we have to search in the list 2 times;
    int i=0,j;
    ListNode *Element= (ListNode *) malloc(sizeof(ListNode));
    Element=first;
    while(Element!=NULL)
    {
        Element=Element->next;
        i++;
    }
    if(i<=x)  PRINT_ALL(g);
    else
    {
        j=0;
        Element=first;
        while(j<i-x)
        {
            Element=Element->next;
            j++;

        }

        while(j<i)
        {
            fprintf(g,"%d ",Element->data);
            Element=Element->next;
            j++;
        }
    }fprintf(g,"\n");
}
void readInstructions(FILE *f,FILE *g)
{   int i,nr;
    char *s=(char *) malloc(sizeof(char)*MAXLENGHT);
    char *p;
    while(fgets(s,MAXLENGHT,f)!=NULL)
    {
        p=strtok(s," \n");

        if(!strcmp(p,"AF"))
        {
            p=strtok(NULL," \n");
            nr=0;
            for(i=0;i<strlen(p);i++)
                nr=nr*10+p[i]-'0';

            AF(nr);

        }
        else if(!strcmp(p,"AL"))
        {
            p=strtok(NULL," \n");
            nr=0;
            for(i=0;i<strlen(p);i++)
                nr=nr*10+p[i]-'0';
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
            nr=0;
            for(i=0;i<strlen(p);i++)
                nr=nr*10+p[i]-'0';
            DE(nr,g);

        }
        else if(!strcmp(p,"PRINT_ALL"))
        {
            PRINT_ALL(g);
        }
        else if(!strcmp(p,"PRINT_F"))
        {
            p=strtok(NULL," \n");
            nr=0;
            for(i=0;i<strlen(p);i++)
                nr=nr*10+p[i]-'0';
            PRINT_F(nr,g);
        }
        else if(!strcmp(p,"PRINT_L"))
        {
            p=strtok(NULL," \n");
            nr=0;
            for(i=0;i<strlen(p);i++)
                nr=nr*10+p[i]-'0';
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
