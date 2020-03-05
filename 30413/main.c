#include <stdio.h>
#include <stdlib.h>
#include <string.h>
MAX_LENGTH=50;

typedef struct node
{
    int data;
    struct node *next;
} Node;
Node *first;
Node *last;

void read(FILE *f,FILE *g)
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

        if(strcmp(token,"AL")==0)
        {
            token=strtok(NULL," ");
            data=atoi(token);
            addLast(data);
        }
        if(strcmp(token,"DF")==0)
        {
            deleteFirst();
        }

        if(strcmp(token,"DL")==0)
        {
            deleteLast();
        }
        if(strcmp(token,"DOOM_THE_LIST")==0)
        {
            removeAll();
        }
        if(strcmp(token,"DE")==0)
        {
            token=strtok(NULL," ");
            data=atoi(token);
            deleteEl(data);
        }
        if(strcmp(token,"PRINT_ALL")==0)
        {
            printSLL();
        }
        if(strcmp(token,"PRINT_F")==0)
        {
            token=strtok(NULL," ");
            data=atoi(token);
            printFirst(data,g);
        }
        if(strcmp(token,"PRINT_L")==0)
        {
            token=strtok(NULL," ");
            data=atoi(token);
            printLast(data,g);
        }

    }
}

void initializeSLL()
{
    first=NULL;
    last=NULL;
}

void addFirst(int data)
{
    if(first==NULL)
    {
        first=(Node*)malloc(sizeof(Node));
        first->next=last;
        first->data=data;
        last=first;
    }
    else
    {
        Node *newElement=(Node*)malloc(sizeof(Node));
        newElement->data=data;
        newElement->next=first;
        first=newElement;
    }
}

void addLast(int data)
{
    Node *newElement=(Node*)malloc(sizeof(Node));
    last->next=newElement;
    newElement->next=NULL;
    newElement->data=data;
    last=newElement;
}

void deleteFirst()
{
    first=first->next;
}


void deleteLast()
{

    Node *currEl = first;
    Node *prevEl = first;
    if(first!=NULL)
    {

        while (currEl->next != NULL)
        {
            prevEl = currEl;
            currEl = currEl->next;
        }
        prevEl->next = NULL;
        last = prevEl;
    }
}


void removeAll()
{
    Node *currentEl=first;
    while(currentEl!=NULL)
    {
        first=first->next;
        free(currentEl);
        currentEl=first;
    }
    initializeSLL();
}

void deleteEl(int data)
{
    Node *currentEl=first;
    Node *prevEl=first;
    while(currentEl!=NULL)
    {
        if(currentEl->data==data)
        {
            if(currentEl==first)
            {
                first=first->next;
            }
            else if(currentEl==last)
            {
                last=prevEl;
                last->next=NULL;
            }
            else
            {
                prevEl->next=currentEl->next;
            }

            prevEl=currentEl;
            currentEl=currentEl->next;
            free(prevEl);
            prevEl=currentEl;

        }
        else
        {
            prevEl=currentEl;
            currentEl=currentEl->next;
        }
    }
}

void printSLL()
{
    Node *currentEl=first;
    if(first==NULL)
    {
        printf("List is empty!");
    }
    else
    {
        while(currentEl!=NULL)
        {
            printf("%d ",currentEl->data);
            currentEl=currentEl->next;
        }
    }
    printf("\n");
}

void printFirst(int data,FILE *g)
{
    int k=0;
    Node *currentEl=first;
    while(currentEl!=NULL && k<data)
    {
        k++;
        fprintf(g,"%d ",currentEl->data);
        currentEl=currentEl->next;

    }
    fprintf(g,"\n");
}

void printLast(int data,FILE *g)
{
    Node *currentEl=first;
    Node *prevEl=first;
    int nr=0;
    while(currentEl!=NULL)
    {
        currentEl=currentEl->next;
        nr++;
    }
    currentEl=first;
    int x=nr-data;
    while(currentEl!=NULL)
    {
        x--;
        if(x<0)
            fprintf(g,"%d ",currentEl->data);
        currentEl=currentEl->next;

    }
    fprintf(g,"\n");
}

int main()
{
    FILE *f=fopen("input.txt","r");
    FILE *g=fopen("output.txt","w");
    initializeSLL();
    read(f,g);
    printSLL();
    return 0;
}
