#include <stdio.h>
#include<stdlib.h>
#include<string.h>
#define DATA_PATH_IN "../input.dat"
#define DATA_PATH_OUT "../output.dat"
#define MAX_LINE 10
typedef struct node{
    int data;
    struct node *next;
    struct node *prev;
}NodeT;
NodeT *first,*last;
FILE *out;
void initializeList();
void printAll();
void addFirst(int x);
void addLast(int x);
void deleteFirst();
void deleteLast();
void deleteAll();
void printFirst(int x);
void printLast(int x);
void deleteX(int x);
int main() {
    out=fopen(DATA_PATH_OUT,"w");
    FILE *in;
    in=fopen(DATA_PATH_IN,"r");
    char* command;
    int x;
    command=(char*)malloc(MAX_LINE*sizeof(char));
    if(in==NULL)
    {
        perror("Error: ");
        exit(EXIT_FAILURE);
    }
    initializeList();
    while(fscanf(in,"%s",command)>0)
    {
        if(strcmp(command,"AF")==0)
        {
            fscanf(in,"%d",&x);
            addFirst(x);
        }else if(strcmp(command,"AL")==0)
        {
            fscanf(in,"%d",&x);
            addLast(x);
        }else if (strcmp(command,"DF")==0)
        {
            deleteFirst();
        }else if(strcmp(command,"DL")==0)
        {
            deleteLast();
        } else if(strcmp(command,"DOOM_THE_LIST")==0)
        {
            deleteAll();
        }else if(strcmp(command,"DE")==0)
        {
            fscanf(in,"%d",&x);
            deleteX(x);
        }else if(strcmp(command,"PRINT_ALL")==0)
        {
            printAll();
        }else if(strcmp(command,"PRINT_F")==0)
        {
            fscanf(in,"%d",&x);
            printFirst(x);
        }else if(strcmp(command,"PRINT_L")==0)
        {
            fscanf(in,"%d",&x);
            printLast(x);
        }

    }
    free(command);
    fclose(in);
    fclose(out);
    return 0;
}
void initializeList()
{
    first=NULL;
    last=NULL;
}
void printAll()
{
    NodeT *currentNode=first;
    if(first==NULL)
    {
        fprintf(out,"List is empty!\n");
    }
    else {
        while (currentNode != NULL) {
            fprintf(out, "%d ", currentNode->data);
            currentNode = currentNode->next;
        }
        fprintf(out,"\n");
    }
}
void addFirst(int x)
{
    if(first==NULL)
    {
        first=(NodeT*)malloc(sizeof(NodeT));
        first->data=x;
        first->next=last;
        first->prev=NULL;
        last=first;
    }
    else{
        NodeT *newNode;
        newNode=(NodeT*)malloc(sizeof(NodeT));
        newNode->next=first;
        newNode->prev=NULL;
        newNode->data=x;
        first->prev=newNode;
        first=newNode;

    }
}
void addLast(int x)
{

    if(first==NULL)
    {
        first=(NodeT*)malloc(sizeof(NodeT));
        first->data=x;
        first->next=last;
        first->prev=NULL;
        last=first;

    } else
    {
        NodeT *newNode;
        newNode=(NodeT*)malloc(sizeof(NodeT));
        last->next=newNode;
        newNode->data=x;
        newNode->next=NULL;
        newNode->prev=last;
        last=newNode;
    }
}
void deleteFirst()
{
    NodeT *currentNode=first;
    if(currentNode!=NULL)
    {
        first=first->next;
        if(first==NULL)
        {
            last=NULL;
        } else
            first->prev=NULL;
        free(currentNode);
    } else
    {
        last=NULL;
    }

}
void deleteLast()
{
    NodeT *currentNode=last;
    if(currentNode!=NULL) {
        last = last->prev;
        if (last == NULL)
            first = NULL;
        else
            last->next = NULL;
        free(currentNode);
    } else
        first=NULL;
}
void deleteAll()
{
    NodeT *currentNode=first;
    while(currentNode!=NULL)
    {
        first=first->next;
        free(currentNode);
        currentNode=first;
    }
}
void printFirst(int x)
{
    if(first==NULL)
    {
        fprintf(out,"List is empty!\n");
    } else{
        NodeT *currentNode=first;
        for(int i=0;i<x;i++)
        {
            fprintf(out,"%d ",currentNode->data);
            currentNode=currentNode->next;
        }
        fprintf(out,"\n");
    }
}
void printLast(int x)
{
    if(first==NULL)
    {
        fprintf(out,"List is empty!\n");
    } else{
        NodeT *currentNode=last;
        for(int j=0;j<x-1;j++)
        {
            currentNode=currentNode->prev;
        }
        while(currentNode!=NULL)
        {
            fprintf(out,"%d ",currentNode->data);
            currentNode=currentNode->next;
        }
        fprintf(out,"\n");

    }
}
void deleteX(int x)
{
    NodeT *currentNode=first;
    while(currentNode!=NULL)
    {
        if(currentNode->data==x)
            break;
        currentNode=currentNode->next;
    }
    if(currentNode!=NULL) {

        if (currentNode== first) {

            first = first->next;
            if(first!=NULL)
                first->prev=NULL;
            else
                last=NULL;
            free(currentNode);

        } else if (currentNode == last) {
            last = last->prev;
            if(last!=NULL)
                last->next = NULL;
            else
                first=NULL;
            free(currentNode);

        } else {
            currentNode->next->prev=currentNode->prev;
            currentNode->prev->next=currentNode->next;

            free(currentNode);
        }
    }
}
