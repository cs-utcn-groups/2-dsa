#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct node
{
    int data;
    struct node * next;
    struct node * prev;
} NodeT;
NodeT *first, *last;
void initializeList()
{

    first=NULL;
    last=NULL;
}

void PRINT_ALL()
{
    NodeT*currentNode = first;
    while(currentNode != NULL)
    {
        printf("%d ", currentNode->data);
        currentNode = currentNode->next;
    }
    printf("\n");
}

void DOOM_THE_LIST()
{
    NodeT * currentElement = first;
    while(currentElement != NULL)
    {
        first =first->next;
        free(currentElement);
        currentElement = first;
    }
    last=NULL;
    /// printf("List have been cleared\n");
}
void DL()
{
    NodeT *node=last;
    if(last==NULL)
    {
        /// printf("The list is empty\n");
        return;
    }
    if(first==last)
    {
        free(first);
        first=last=NULL;
    }

    last=last->prev;
    last->next=NULL;

    free(node);


}
void DF()
{
    NodeT*currentElement=first;
    if(first==NULL)
    {
        ///printf("List is already empty\n");
        return;
    }
    else
    {
        currentElement=first;
        if(first==last)
        {
            last=NULL;
        }
        first=first->next;
        first->prev=NULL;
    }
    free(currentElement);
}
void AddL(int data)
{

    NodeT*newElem1=(NodeT*)malloc(sizeof(NodeT));
    newElem1->data=data;
    newElem1->next=NULL;
    newElem1->prev=last;
    last->next=newElem1;
    last=newElem1;
    if(first==NULL)
    {

        last=first;
    }
}
void AF(int data)
{
    NodeT*newElem1=(NodeT*)malloc(sizeof(NodeT));
    newElem1->data=data;
    newElem1->prev=NULL;
    if(first==NULL)
    {
        first=newElem1;
        first->next=last;
        first->prev=NULL;
        last=first;
    }
    else
    {
        newElem1->next=first;
        newElem1->prev=NULL;
        first->prev=newElem1;
        first=newElem1;
    }
}
void DE(int x)
{
    NodeT*currentNode=first;


    while(currentNode!=NULL)
    {
        if(currentNode->data==x)
            break;
        currentNode->prev=currentNode;
        currentNode=currentNode->next;
    }

    if(currentNode!=NULL)
    {
        if(currentNode==first)
        {
            first=first->next;
            free(currentNode);
        }


        else
        {
            currentNode->prev->next = currentNode->next;

            free( currentNode );
        }

    }
}
void PRINT_F(int x)
{
    NodeT*currentNode=first;
    int i=0;
    while(currentNode != NULL && i<x)
    {
        printf("%d ", currentNode->data);
        currentNode = currentNode->next;
        i++;
    }
    printf("\n");
}
int countAll()
{
    int count=0;
    NodeT*currentNode=first;
    while(currentNode!=NULL)
    {
        count++;
        currentNode=currentNode->next;
    }
    return count;

}
void PRINT_L(int x)
{
    NodeT*currentNode=first;
    int nr=countAll();
    if(x>nr)
    {
        PRINT_ALL();
    }
    else
    {
        for(int i=0; i<nr-x; i++)
        {
            currentNode=currentNode->next;
        }
        while(currentNode!=NULL)
        {
            printf("%d ",currentNode->data);
            currentNode=currentNode->next;
        }
        printf("\n");
    }
}
void readAndExecute(char *strbuf)
{
    char *p=strtok(strbuf, " \n");
    char *instr=(char*)malloc(sizeof(char)*20);
    int x;

    strcpy(instr, p);
    p = strtok(NULL,"\n");

    if (p!=NULL)
    {
        x=atoi(p);
    }

    if(strcmp("AF",instr)==0)
    {
        AF(x);
    }
    else if(strcmp("AddL",instr)==0)
    {
        AddL(x);
    }
    else if(strcmp("DF",instr)==0)
    {
        DF();
    }
    else if(strcmp("DL",instr)==0)
    {
        DL();
    }
    else if (strcmp("DOOM_THE_LIST",instr)==0)
    {
        DOOM_THE_LIST();
    }
    else if (strcmp("DE",instr)==0)
    {
        DE(x);
    }
    else if (strcmp("PRINT_ALL",instr)==0)
    {
        PRINT_ALL();
    }
    else if (strcmp("PRINT_F",instr)==0)
    {
        PRINT_F(x);
    }
    else if (strcmp("PRINT_L", instr)==0)
    {
        PRINT_L(x);
    }
}
int main()
{
    FILE *f=fopen("input.txt","rw");
    initializeList();
    ///FILE *o=fopen("output.txt","rw");
    char *strBuf=(char*)malloc(sizeof(char)*100);

    while(fgets(strBuf,100,f)!=NULL)
    {
        readAndExecute(strBuf);
    }
    return 0;
}
