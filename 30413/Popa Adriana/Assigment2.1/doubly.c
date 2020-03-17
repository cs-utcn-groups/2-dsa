#include "doubly.h"

void initializeList()
{
    first=NULL;
    last=NULL;
}

void readInput()
{
    FILE *f=fopen("input.dat","r");
    FILE *g=fopen("output.dat","w");
    char *instr=(char*)malloc(sizeof(char)*100);
    char *p=(char*)malloc(sizeof(char)*100);
    int x;
    while(fgets(instr,100,f)!=NULL)
    {
        p=strtok(instr," ");
        if(verify(p,"AF")==1)
        {
            p=strtok(NULL," ");
            x=atoi(p);
            addFirst(x);
        }
        else if(verify(p,"AL")==1)
        {
            p=strtok(NULL," ");
            x=atoi(p);
            addLast(x);
        }
        else  if(verify(p,"DF")==1)
        {
            deleteFirst();
        }
        else if(verify(p,"DL")==1)
        {
            deleteLast();
        }
        else  if(verify(p,"DE")==1)
        {
            p=strtok(NULL," ");
            x=atoi(p);
            deleteElement(x);
        }
        else if(verify(p,"DOOM_THE_LIST")==1)
        {
            doom();
        }
        else if(verify(p,"PRINT_ALL")==1)
        {
            printList(g);
        }
        else if(verify(p,"PRINT_F")==1)
        {
            p=strtok(NULL," ");
            x=atoi(p);
            printFirst(x,g);
        }
        else if(verify(p,"PRINT_L")==1)
        {
            p=strtok(NULL," ");
            x=atoi(p);
            printLast(x,g);
        }
    }
    fclose(f);
    fclose(g);
}

int verify(char *a,char *b)
{
    int i;
    for(i=0; i<strlen(b)&&i<strlen(a); i++)
    {
        if(a[i]!=b[i])
        {
            return 0;
        }
    }
    return 1;
}

void addLast(int data)
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
        NodeT * newE1 = (NodeT*)malloc(sizeof(NodeT));
        last->next = newE1;
        newE1->next = NULL;
        newE1->data = data;
        newE1->previous = last;
        last = newE1;
    }
}

void printList(FILE *g)
{
    NodeT *currentNode = first;
    while(currentNode != NULL)
    {
        fprintf(g,"%d ", currentNode->data);
        currentNode = currentNode->next;
    }
    fputs("\n",g);
}

void deleteElement(int data)
{
    NodeT *current=(NodeT*)malloc(sizeof(NodeT));
    current=first;
    while(current != NULL)
    {
        if(current->data==data)
        {
            if(current==first)
            {
                first=first->next;
                first->previous=NULL;
            }
            else if(current==last)
            {
                last=last->previous;
                last->next=NULL;
            }
            else
            {
                current->previous->next=current->next;
            }
            NodeT *saveEl = current->next;
            free(current);
            current=saveEl;
        }
        else
        {
            current=current->next;
        }
    }
}

void doom()
{
    NodeT *current=first;
    while(current != NULL)
    {
        first=first->next;
        free(current);
        current=first;
    }
}

void addFirst(int data)
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
        NodeT *newEl=(NodeT*)malloc(sizeof(NodeT));
        newEl->data=data;
        newEl->next=first;
        newEl->previous=NULL;
        first->previous=newEl;
        first=newEl;
    }

}

void deleteFirst()
{
    NodeT *newEl=(NodeT*)malloc(sizeof(NodeT));
    newEl=first->next;
    newEl->previous=NULL;
    first=newEl;
}

void deleteLast()
{
    NodeT *newEl=(NodeT*)malloc(sizeof(NodeT));
    newEl=last->previous;
    newEl->next=NULL;
    last=newEl;
}

void printLast(int x,FILE *g)
{
    NodeT *current=last;
    int i;
    for(i=0; i<x && current!=NULL; i++)
    {
        fprintf(g,"%d ", current->data);
        current=current->previous;
    }
    fputs("\n",g);
}

void printFirst(int x,FILE *g)
{
    NodeT *current=first;
    int i;
    for(i=0; i<x && current!=NULL; i++)
    {
        fprintf(g,"%d ", current->data);
        current=current->next;
    }
    fputs("\n",g);
}
