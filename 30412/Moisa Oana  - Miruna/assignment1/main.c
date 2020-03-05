#include <stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX_VALUE 10
#define DATA_PATH_IN "../input.dat"
#define DATA_PATH_OUT "../output.dat"
typedef struct node{
    int data;
    struct node *next;
}NodeT;
NodeT *first, *last;
void initializeSLL();
void printAll();
void addLast(int x);
void addFirst(int x);
void deleteAll();
void deleteFirst();
void deleteLast();
void deleteElement(int x);
void printFirst(int x);
void printLast(int x);
FILE *out;
int main() {

    out=fopen(DATA_PATH_OUT,"w");
    FILE *in;
    in=fopen(DATA_PATH_IN,"r");
    if(in==NULL)
    {
        perror("Error: ");
        exit(EXIT_FAILURE);
    }
    initializeSLL();
    char *command;
    command=(char*)malloc(MAX_VALUE*sizeof(char));
    int x;
    while( fscanf(in, "%s", command)>0) {

        if (strcmp(command, "AF") == 0) {
            fscanf(in, "%d", &x);
            addFirst(x);
        }
        if (strcmp(command, "AL") == 0) {
            fscanf(in, "%d", &x);
            addLast(x);
        }
        if (strcmp(command, "DF") == 0) {
            deleteFirst();
        }
        if (strcmp(command, "DL") == 0) {
            deleteLast();
        }
        if (strcmp(command, "DOOM_THE_LIST") == 0) {
            deleteAll();
        }
        if (strcmp(command, "DE") == 0) {
            fscanf(in, "%d", &x);
            deleteElement(x);
        }
        if (strcmp(command, "PRINT_ALL") == 0) {
            printAll();
        }
        if (strcmp(command, "PRINT_F") == 0) {
            fscanf(in, "%d", &x);
            printFirst(x);
        }
        if (strcmp(command, "PRINT_L") == 0) {
            fscanf(in, "%d", &x);
            printLast(x);
        }
    }
    free(command);
    fclose(in);
    fclose(out);
    return 0;
}
void initializeSLL()
{
    first=NULL;
    last=NULL;
}
void printAll()
{
    NodeT *currentNode;
    if(first==NULL)
    {
        fprintf(out, "The list is empty!\n");

    }
    else {
        currentNode = first;
        while (currentNode != NULL) {
            fprintf(out,"%d ", currentNode->data);
            currentNode = currentNode->next;
        }
        fprintf(out,"\n");
    }


}
void printFirst(int x)
{
    NodeT *currentNode;
    if(first==NULL)
    {
        fprintf(out,"The list is empty!\n");
    }
    else
    {
        currentNode=first;
        int i=0;
        while(currentNode!=NULL &&i<x)
        {
            fprintf(out,"%d ", currentNode->data);
            currentNode=currentNode->next;
            i++;
        }
        fprintf(out,"\n");
    }
}
void printLast(int x)
{
    NodeT *currentNode;
    if(first==NULL)
    {
        fprintf(out,"The list is empty!\n");
    }
    else
    {
        currentNode=first;
        int noNodes=0;
        while(currentNode!=NULL)
        {
            noNodes++;
            currentNode=currentNode->next;
        }
        currentNode=first;
        int i=0;
        while(currentNode!=NULL)
        {
            if(i<noNodes-x)
            {
                i++;
                currentNode=currentNode->next;
            }
            else
            {
                fprintf(out,"%d ",currentNode->data);
                currentNode=currentNode->next;
            }
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
        last=first;
    }
    else
    {
        NodeT *newNode;
        newNode=(NodeT*)malloc(sizeof(NodeT));
        newNode->data=x;
        newNode->next=first;
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
        last=first;
    }
    else
    {
        NodeT *newNode;
        newNode=(NodeT*)malloc(sizeof(NodeT));
        last->next=newNode;
        newNode->next=NULL;
        newNode->data=x;
        last=newNode;
    }
}
void deleteFirst()
{
    NodeT *currentNode=first;
    if(first!=NULL) {
        first = first->next;
        free(currentNode);
    }
    else
        last=NULL;


}
void deleteLast() {
    NodeT *currentNode = first;
    NodeT *penultimateNode = NULL;
    if (currentNode != NULL) {
        while (currentNode != last) {
            penultimateNode = currentNode;
            currentNode = currentNode->next;
        }
        if (currentNode == first) {
            first = last = NULL;
        } else {
            penultimateNode->next = NULL;
            last = penultimateNode;
        }
        free(currentNode);
    }

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
void deleteElement(int x)
{
    NodeT *currentElement=first;
    NodeT *previousElement=first;
    while(currentElement!=NULL) {
        if (currentElement->data == x) {
            if (currentElement == first) {
                first = first->next;
            } else if (currentElement == last) {
                last = previousElement;
                last->next = NULL;
            } else {
                previousElement->next = currentElement->next;
            }
            previousElement = currentElement;
            currentElement = currentElement->next;
            free(previousElement);
            previousElement = currentElement;
        } else
        {
            previousElement=currentElement;
            currentElement=currentElement->next;
        }
    }
}
