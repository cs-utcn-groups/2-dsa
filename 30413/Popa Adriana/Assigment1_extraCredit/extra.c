#include "extra.h"

void initializeSll()
{
    firstS = NULL;
    lastS = NULL;
    firstC = NULL;
    lastC = NULL;
}

void readSentinels(FILE *f,int *cts)
{
    int i,x,n;
    fscanf(f,"%d",&n);
    for(i=0; i<n; i++)
    {
        fscanf(f,"%d",&x);
        *cts=*cts+x;
        addElement(x);
    }
}

void addElement(int data)
{
    if(firstS == NULL)
    {
        firstS = (NodeT*)malloc(sizeof(NodeT));
        firstS->next = lastS;
        firstS->data = data;
        lastS = firstS;
    }
    else
    {
        NodeT * newE1 = (NodeT*)malloc(sizeof(NodeT));
        lastS->next = newE1;
        newE1->next = NULL;
        newE1->data = data;
        lastS = newE1;
    }
}

void printSllData()
{
    NodeT *currentNode = firstS;
    while(currentNode != NULL)
    {
        printf("%d ", currentNode->data);
        currentNode = currentNode->next;
    }
    printf("\n");
}

