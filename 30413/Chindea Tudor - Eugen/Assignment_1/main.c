#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct node
{
    int data;
    struct node * next;
} NodeT;
NodeT *first,*last;
void initializeSll()
{
    first=NULL;
    last=NULL;
}
void AL( int data)
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
        NodeT* newElem=(NodeT*)malloc(sizeof(NodeT));
        last->next=newElem;
        newElem->next=NULL;
        newElem->data=data;
        last=newElem;
    }
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
        NodeT* newElem=(NodeT*)malloc(sizeof(NodeT));
        newElem->next=first;
        newElem->data=data;
        first=newElem;
    }
}
void DF()
{
    NodeT * currentNode=first;
    first=first->next;
    free(currentNode);

}
void DL()
{
    NodeT * previousNode=first;
    while(previousNode->next != last)
    {
        previousNode=previousNode->next;
    }
    free(last);
    last=previousNode;
    last->next=NULL;

}
void PRINT_ALL(FILE *f)
{
    if(first==NULL)
    {
        fprintf(f,"List is empty\n");
    }
    else
    {
        NodeT * currentNode = first;
        while(currentNode != NULL)
        {
            fprintf(f,"%d ",currentNode->data);
            currentNode = currentNode->next;
        }
        fprintf(f,"\n");
    }
}
void DOOM_THE_LIST()
{
    NodeT *currentNode=first;
    while(currentNode != NULL)
    {
        first=first->next;
        free(currentNode);
        currentNode=first;
    }
}
void DE (int data)
{
    NodeT * currentElement = first;
    NodeT * previousElement= first;
    while(currentElement != NULL)
    {
        if(currentElement->data == data)
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
void PRINT_F (int number,FILE *f)
{
    int i=0;
    NodeT * currentNode=first;
    while( currentNode != NULL && i<number)
    {
        fprintf (f,"%d ",currentNode->data);
        currentNode=currentNode->next;
        i++;
    }
    fprintf(f,"\n");
}
void PRINT_L (int nr,FILE *f)
{
    int total=0;
    NodeT * currentNode=first;
    while (currentNode!= NULL)
    {
        total++;
        currentNode=currentNode->next;
    }
    int ct=0;
    currentNode=first;
    while(currentNode != NULL)
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
void  instructiuni (FILE *f,FILE *g)
{
    char **instrList=(char**)malloc(sizeof(char*)*10);
    for(int i=0; i<10; i++)
    {
        instrList[i]=(char*)malloc(sizeof(char)*10);
    }
    strcpy(instrList[0],"AF");
    strcpy(instrList[1],"AL");
    strcpy(instrList[2],"DF");
    strcpy(instrList[3],"DL");
    strcpy(instrList[4],"DOOM_THE_LIST");
    strcpy(instrList[5],"DE");
    strcpy(instrList[6],"PRINT_ALL");
    strcpy(instrList[7],"PRINT_F");
    strcpy(instrList[8],"PRINT_L");
    char *strbuf=(char*)malloc(sizeof(char)*20);
    char *instruc=(char*)malloc(sizeof(char)*10);
    int nr,execut,instrNr;
    while(fgets(strbuf,20,f))
    {
        sscanf(strbuf,"%s %d",instruc,&execut);
         for(int i=0; i<9; i++)
         {
             if(strcmp(instruc,instrList[i])==0)
             {
                 instrNr=i;

             }
         }
         switch(instrNr)
         {
         case 0:
             AF(execut);
             break;
         case 1:
             AL(execut);
             break;
         case 2:
             DF();
             break;
         case 3:
             //DL();
             break;
         case 4:
             DOOM_THE_LIST();
             break;
         case 5:
             DE(execut);
             break;
         case 6:
             PRINT_ALL(g);
             break;
         case 7:
             PRINT_F(execut,g);
             break;
         case 8:
             PRINT_L(execut,g);
             break;
         }
    }
}
int main()
{
    FILE *i=fopen("input.dat.txt","rw+");
    FILE *o=fopen("output.dat.txt","rw+");
    initializeSll();
    instructiuni(i,o);

    return 0;
}
