#include <string.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node *prev,*next;
} NodeT;

typedef struct sentinel
{
    NodeT *first,*last;
} SentinelT;

SentinelT *Sentinel;

void initializeSentinel()
{
    Sentinel = (SentinelT *)malloc(sizeof(SentinelT));
    Sentinel->first = NULL;
    Sentinel->last = NULL;
}

void AF(int x)
{
    NodeT *newNode = (NodeT *)malloc(sizeof(NodeT));
    newNode->data = x;
    newNode->next=NULL;
    newNode->prev=NULL;
    if (Sentinel->first == NULL)
    {
        Sentinel->first = newNode;
        Sentinel->last = newNode;
    }
    else
    {
        newNode->next = Sentinel->first;
        Sentinel->first->prev = newNode;
        Sentinel->first = newNode;
    }
}

void AL(int x)
{
    NodeT *newNode = (NodeT *) malloc(sizeof(NodeT));
    newNode->data = x;
    newNode->prev=NULL;
    newNode->next=NULL;
    if (Sentinel->last == NULL)
    {
        Sentinel->first = newNode;
        Sentinel->last = newNode;
    }
    else
    {
        Sentinel->last->next = newNode;
        newNode->prev = Sentinel->last;
        Sentinel->last = newNode;
    }
}

void DF()
{
    NodeT *temp;
    if (Sentinel->first != NULL)
    {
        if (Sentinel->first->next == NULL)
        {
            temp=Sentinel->first;
            Sentinel->last=NULL;
            Sentinel->first=NULL;
            free(temp);
        }
        else
        {
            temp = Sentinel->first;
            Sentinel->first = Sentinel->first->next;
            Sentinel->first->prev=NULL;
            free(temp);
        }
    }
}

void DL()
{
    NodeT *temp = Sentinel->first;
    if (Sentinel->first != NULL)
    {
        if (Sentinel->first->next == Sentinel->last)
        {
            Sentinel->first = NULL;
            Sentinel->last = NULL;
        }
        else
        {
            while (temp->next != Sentinel->last)
            {
                temp = temp->next;
            }
            temp->next = NULL;
            free(Sentinel->last);
            Sentinel->last = temp;
        }
    }
}

void DoomTheList()
{
    NodeT *currNode = Sentinel->first;
    while (currNode != NULL)
    {
        Sentinel->first = Sentinel->first->next;
        free(currNode);
        currNode = Sentinel->first;
    }
    Sentinel->first = NULL;
    Sentinel->last = NULL;
}

void DE(int x)
{
    NodeT *currNode = Sentinel->first;
    NodeT *prevNode = Sentinel->first;
    if (currNode->data == x)
    {
        if (currNode == Sentinel->first)
        {
            DF();
            currNode = Sentinel->first;
        }
        else
        {
            if (currNode == Sentinel->last)
            {
                DL();
                currNode = Sentinel->last;
            }
            else
            {
                prevNode->next = currNode->next;
                free(currNode);
                currNode = prevNode->next;
            }
        }
    }
    else
    {
        prevNode = currNode;
        currNode = currNode->next;
    }
}

void PrintAll(FILE *o)
{
    NodeT *temp = Sentinel->first;
    if (Sentinel->first == NULL)
    {
        fprintf(o,"List is empty.\n");
        return;
    }
    while (temp != NULL)
    {
        fprintf(o, "%d ", temp->data);
        temp = temp->next;
    }
    fprintf(o,"\n");
}

void PrintFirst(FILE *o, int x)
{
    NodeT *temp = Sentinel->first;
    if (temp == NULL)
    {
        fprintf(o, "List is empty.\n");
        return;
    }
    while (temp != NULL && x)
    {
        fprintf(o,"%d ", temp->data);
        x--;
        temp = temp->next;
    }
    fprintf(o,"\n");
}

void PrintLast(FILE *o, int x)
{
    NodeT *temp = Sentinel->first;
    if (Sentinel->first == NULL)
    {
        fprintf(o,"List is empty.\n");
        return;
    }
    int nrNodes = 0;
    while (temp != NULL)
    {
        nrNodes++;
        temp = temp->next;
    }
    temp = Sentinel->first;
    while (temp != NULL && nrNodes > x)
    {
        temp = temp->next;
        nrNodes--;
    }
    while (temp != NULL && nrNodes)
    {
        fprintf(o,"%d ", temp->data);
        temp = temp->next;
        nrNodes--;
    }
    fprintf(o,"\n");
}

void RecogniseFunction(FILE *o,int x,char *instruction){
    if(strcmp(instruction,"AF")==0)
        {
            AF(x);
        }
        else if(strcmp(instruction,"AL")==0)
        {
            AL(x);
        }
        else if(strcmp(instruction,"DF")==0)
        {
            DF();
        }
        else if(strcmp(instruction,"DL")==0)
        {
            DL();
        }
        else if(strcmp(instruction,"DOOM_THE_LIST")==0)
        {

            DoomTheList();
        }
        else if(strcmp(instruction,"DE")==0)
        {
            DE(x);
        }
        else if(strcmp(instruction,"PRINT_ALL")==0)
        {
            PrintAll(o);
        }
        else if(strcmp(instruction,"PRINT_F")==0)
        {
            PrintFirst(o,x);
        }
        else if(strcmp(instruction,"PRINT_L")==0)
        {
            PrintLast(o,x);
        }
}

int main()
{
    FILE *f = fopen("input.dat","r");
    FILE *o = fopen("output.dat","w");
    initializeSentinel();
    while(!feof(f))
    {
        char * instruction = (char *)malloc(50*sizeof(char));
        fscanf(f,"%s",instruction);
        int x;
        fscanf(f,"%d",&x);
        RecogniseFunction(o,x,instruction);
        free(instruction);
    }
    fclose(f);
    fclose(o);
    return 0;
}
