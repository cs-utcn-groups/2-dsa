#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct node
{
    int data;
    struct node * next;
    struct node * prev;
} NodeT;
NodeT Sentinel,*sentinel=&Sentinel;
void initializeSentinel()
{
    sentinel->next=sentinel;
    sentinel->prev=sentinel;
}
void AF(int data)
{
    NodeT * newElem=(NodeT*)malloc(sizeof(NodeT));
    newElem->data=data;
    if(sentinel->next==sentinel)
    {
        newElem->next=sentinel;
        newElem->prev=sentinel;
        sentinel->next=newElem;
        sentinel->prev=newElem;
    }
    else{
        newElem->next=sentinel->next;
        sentinel->next->prev=newElem;
        sentinel->next=newElem;
        newElem->prev=sentinel;
    }
}
void AL(int data)
{
    NodeT * newElem=(NodeT*)malloc(sizeof(NodeT));
    newElem->data=data;
    if(sentinel->next==sentinel)
    {
        newElem->next=sentinel;
        newElem->prev=sentinel;
        sentinel->next=newElem;
        sentinel->prev=newElem;
    }
    else{
        newElem->prev=sentinel->prev;
        sentinel->prev->next=newElem;
        sentinel->prev=newElem;
        newElem->next=sentinel;
    }
}
void DF()
{
    NodeT * oldNode=(NodeT*)malloc(sizeof(NodeT));
    oldNode=sentinel->next->next;
    free(sentinel->next);
    sentinel->next=oldNode;
    oldNode->prev=sentinel;
}
void DL()
{

    NodeT * oldNode=sentinel->prev->prev;
    if(sentinel->prev!=sentinel);
    {
    free(sentinel->prev);
    sentinel->prev=oldNode;
    oldNode->next=sentinel;
    }
}
void PRINT_ALL(FILE *f)
{

    if(sentinel->next==sentinel)
    {
        fprintf(f,"List is empty\n");
    }
    else
    {
        NodeT * currentNode= sentinel->next;
        while(currentNode!=sentinel)
        {
            fprintf(f,"%d ",currentNode->data);
            currentNode=currentNode->next;
        }
        fprintf(f,"\n");
    }
}
void PRINT_CONSOLE()
{

    if(sentinel->next==sentinel)
    {
        printf("List is empty\n");
    }
    else
    {
        NodeT * currentNode= sentinel->next;
        while(currentNode!=sentinel)
        {
            printf("%d ",currentNode->data);
            currentNode=currentNode->next;
        }
        printf("\n");
    }
}
void DOOM_THE_LIST()
{
    NodeT *currentNode=sentinel->next;
    while(currentNode!=sentinel)
    {
        sentinel->next=currentNode->next;
        free(currentNode);
        currentNode=sentinel->next;
    }
   initializeSentinel();
}
void DE(int data)
{
    NodeT* currentNode=sentinel->next;
    NodeT * previousNode=sentinel->next;
    while(currentNode!=sentinel)
    {
        if(currentNode->data==data)
        {
            if(currentNode == sentinel->next)
            {
                sentinel->next=currentNode->next;
            }
            else if(currentNode== sentinel->prev)
            {
                sentinel->prev=previousNode;
            }
            else
            {
                previousNode->next = currentNode->next;
                currentNode->prev=currentNode;
            }
            previousNode=currentNode;
            currentNode=currentNode->next;
            free(previousNode);
            previousNode=currentNode;
        }
        else
        {
            previousNode=currentNode;
            currentNode=currentNode->next;
        }
    }
}
void PRIINT_F(int number,FILE *f)
{
     int i=0;
    NodeT * currentNode=sentinel->next;
    while( currentNode != sentinel && i<number)
    {
        fprintf (f,"%d ",currentNode->data);
        currentNode=currentNode->next;
        i++;
    }
    fprintf(f,"\n");
}
void PRINT_L(int nr, FILE *f)
{
    int total=0;
    NodeT * currentNode=sentinel->next;
    while (currentNode!= sentinel)
    {
        total++;
        currentNode=currentNode->next;
    }
    int ct=0;
    currentNode=sentinel->next;
    while(currentNode != sentinel)
    {
        if(total-ct<=nr)
        {
            fprintf(f,"%d ",currentNode->data);
        }
        currentNode=currentNode->next;
        ct++;
    }
    fprintf(f,"\n");
}
void instructiuni(FILE *f,FILE *g)
{
    char *strbuf=(char*)malloc(sizeof(char)*20);
    char *instruc=(char*)malloc(sizeof(char)*10);
    int execut;
    while(fgets(strbuf,20,f))
    {
         sscanf(strbuf,"%s %d",instruc,&execut);
         if(strcmp(instruc,"AF")==0)
         {
             AF(execut);
         }
         else if(strcmp(instruc,"AL")==0)
         {
             AL(execut);
         }
         else if(strcmp(instruc,"DF")==0)
         {
             DF();
         }
         else if(strcmp(instruc,"DL")==0)
         {
             DL();
         }
         else if(strcmp(instruc,"DOOM_THE_LIST")==0)
         {
             DOOM_THE_LIST();
         }
         else if(strcmp(instruc,"DE")==0)
         {
             DE(execut);
         }
         else if(strcmp(instruc,"PRINT_ALL")==0)
         {
             PRINT_ALL(g);
         }
         else if(strcmp(instruc,"PRINT_F")==0)
         {
             PRIINT_F(execut,g);
         }
         else if(strcmp(instruc,"PRINT_L")==0)
         {
             PRINT_L(execut,g);
         }

    }
}
int main()
{
    FILE *i=fopen("input.dat.txt","rw+");
    FILE *o=fopen("output.dat.txt","rw+");
    initializeSentinel();
    instructiuni(i,o);

    return 0;
}
