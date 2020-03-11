#include "head.h"
MAX_LENGTH=100;

void readFile(FILE *f, FILE *g)
{
    int data;
    char *s=(char*)malloc(sizeof(char));
    char *token=(char*)malloc(sizeof(char));
    while(fgets(s,MAX_LENGTH,f))
    {
        s[strlen(s)-1]='\0';
        token=strtok(s," ");

        if(strcmp(token,"AF")==0)
        {
            token=strtok(NULL," ");
            data=atoi(token);
            addFirst(data);
        }

        else
        {
            if (strcmp(token,"AL")==0)
            {
                token=strtok(NULL," ");
                data=atoi(token);
                addLast(data);
            }
            else if (strcmp(token,"DF")==0)
            {
                deleteFirst();
            }

            else if (strcmp(token,"DL")==0)
            {
                deleteLast();
            }
            else if(strcmp(token,"DOOM_THE_LIST")==0)
            {
                removeAll();
            }
            else if(strcmp(token,"DE")==0)
            {
                token=strtok(NULL," ");
                data=atoi(token);
                deleteEl(data);
            }
            else if(strcmp(token,"PRINT_ALL")==0)
            {
                print_all(g);
            }
            else if(strcmp(token,"PRINT_F")==0)
            {
                token=strtok(NULL," ");
                data=atoi(token);
                print_first(data,g);
            }
            else if(strcmp(token,"PRINT_L")==0)
            {
                token=strtok(NULL," ");
                data=atoi(token);
                print_last(data,g);
            }
        }

    }
}

void initializeDLL()
{
    first=NULL;
    last=NULL;
}

void addFirst(int data)
{

    if(first==NULL)
    {
        first=(Node*)malloc(sizeof(Node));
        first->prev=NULL;
        first->next=NULL;
        first->value=data;
        last=first;
    }
    else
    {
        Node *newEl=(Node*)malloc(sizeof(Node));
        newEl->next=first;
        newEl->prev=NULL;
        newEl->value=data;
        first->prev=newEl;
        first=newEl;

    }
}

void addLast(int data)
{
    if(first==NULL)
    {
        first=(Node*)malloc(sizeof(Node));
        first->prev=NULL;
        first->next=NULL;
        first->value=data;
        last=first;
    }
    else
    {
        Node *newEl=(Node *)malloc(sizeof(Node));
        newEl->next=NULL;
        newEl->prev=last;
        newEl->value=data;
        last->next=newEl;
        last=newEl;
    }
}

void deleteFirst()
{
    Node *currentEl=first;
    first=first->next;
    free(currentEl);
    if(first==NULL)
        last=NULL;
    else
        first->prev=NULL;
}

void deleteLast()
{
    Node *currentEl=last;
    if(last==NULL)
    {
        first=NULL;
    }
    else
    {
        last=last->prev;
        last->next=NULL;
        free(currentEl);
    }
}

void removeAll()
{
    Node *currentEl;
    while(first!=NULL)
    {
        currentEl=first;
        first=first->next;
        free(currentEl);
    }
    last=NULL;
    initializeDLL();

}

void deleteEl(int data)
{
    Node *currentEl=(Node *)malloc(sizeof(Node));
    currentEl=first;

    while(currentEl!=NULL)
    {
        if(currentEl->value!=data)
        {
            //currentEl->prev=currentEl;
            currentEl=currentEl->next;
        }
        else
        {
            if(currentEl==first)
            {
                first=first->next;
                first->prev=NULL;
            }
            else if(currentEl==last)
            {
                 last=last->prev;
                last->next=NULL;
            }
            else
            {
                Node *Elem=currentEl->prev;
                Elem->next=currentEl->next;
                Elem=currentEl->next;
                Elem->prev=currentEl->prev;
            }

            Node *Elem=currentEl->next;
            free(currentEl);
            currentEl=Elem;

        }
    }
}

void print_first(int x,FILE *g)
{
    int k=0;
    Node *currentEl=first;
    while(currentEl!=NULL && k<x)
    {
        k++;
        fprintf(g,"%d ",currentEl->value);
        currentEl=currentEl->next;
    }
    fprintf(g,"\n");
}

void print_last(int x, FILE *g)
{
    int k=0;
    Node *currentEl=last;
    while(currentEl!=NULL && k<x)
    {
        k++;
        fprintf(g,"%d ",currentEl->value);
        currentEl=currentEl->prev;
    }
    fprintf(g,"\n");
}

void print_all(FILE *g)
{
    Node *currentEl=first;
    if(first==NULL)
    {
        fprintf(g,"The list is empty");
    }
    else
    {
        while(currentEl!=NULL)
        {
            fprintf(g,"%d ",currentEl->value);
            currentEl=currentEl->next;
        }
    }
    fprintf(g,"\n");

}
