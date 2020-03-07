#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node
{
    int data;
    struct node *next;
} NodeT;

NodeT *first, *last;

void initialize()
{
    first = NULL;
    last = NULL;
}

void AF(int x)
{
    NodeT *newNode = (NodeT *)malloc(sizeof(NodeT));
    newNode->data = x;
    if (first == NULL)  ///the case when the list is empty
    {
        first = newNode;
        last = first;
        newNode->next = NULL;
    }
    else
    {
        newNode->next = first;
        first = newNode;
    }
}

void AL(int x)
{
    NodeT *newNode = (NodeT *)malloc(sizeof(NodeT));
    newNode->data = x;
    newNode->next = NULL;
    if (last == NULL)
    {
        last = newNode;
        newNode->next = NULL;
    }
    else
    {
        last->next = newNode;
        last = newNode;
    }
}

void DL()
{
    if (first != NULL)
    {
        if (first == last)
        {
            free(first);
            initialize();
        }
        else
        {
            NodeT *t = first;
            while (t->next != last)
            {
                t = t->next;
            }
            t->next = NULL;
            free(last);
            last = t;
        }
    }
}

void DF()
{
    if (first != NULL)
    {
        NodeT *t = first;
        first = t->next;
        if (first == NULL)
        {
            last = first;
        }
        free(t);
    }
}

void DoomTheList()
{
    NodeT *t = first;
    while (t != NULL)
    {
        first = first->next;
        free(t);
        t = first;
    }
    last = NULL;
}

void DE(int x)
{
    NodeT *currNode = first;
    NodeT *prevNode = first;

    while (currNode != NULL)
    {
        if (currNode->data == x)
        {
            if (currNode == first)
            {
                DF();
                currNode = first;
            }
            else
            {
                if (currNode == last)
                {
                    DL();
                    currNode = last;
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
}
void PrintAll (FILE *o)
{
    NodeT *temp=first;
    if (first==NULL)
    {
        fprintf(o,"List is empty.\n");
        return;
    }
    while (temp!=NULL)
    {
        fprintf(o,"%d ",temp->data);
        temp=temp->next;
    }
    fprintf(o,"\n");
}
void printFirst(FILE *o, int x)
{
    NodeT *temp= first;
    if (first==NULL)
    {
        fprintf(o,"List is empty.\n");
        return;
    }
    while(temp !=NULL && x)
    {
        fprintf(o,"%d ",temp->data);
        x--;
        temp=temp->next;
    }
    fprintf(o,"\n");
}
void printLast(FILE *o, int x)
{
    NodeT *temp=first;
    if (first==NULL)
    {
        fprintf(o,"List is empty.\n");
        return;
    }
    int nrNodes=0;
    while (temp!=NULL)
    {
        nrNodes++;
        temp=temp->next;
    }
    temp=first;
    while(temp!=NULL && nrNodes>x)
    {
        temp=temp->next;
        nrNodes--;
    }
    while (temp!=NULL && nrNodes)
    {
        fprintf(o,"%d ",temp->data);
        temp=temp->next;
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
            printFirst(o,x);
        }
        else if(strcmp(instruction,"PRINT_L")==0)
        {
            printLast(o,x);
        }
}

int main()
{
    FILE *f = fopen("input.dat","r");
    FILE *o = fopen("output.dat","w");
    initialize();
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
