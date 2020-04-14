#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int ** adjMat;
int ** newAdjMat;
int nrOfVertixes;
typedef struct list
{
    int node;
    int cost;
    struct list * next;
} List;
List * adjList[6];

void readAdjMat(FILE * f)
{
    int i,j;
    fscanf(f,"%d",&nrOfVertixes);
    adjMat=(int**)malloc(sizeof(int*)*nrOfVertixes);
    for(i=0; i<nrOfVertixes; i++)
        *(adjMat+i)=(int*)malloc(sizeof(int)*nrOfVertixes);
    for(i=0; i<nrOfVertixes; i++)
        for(j=0; j<nrOfVertixes; j++)
            fscanf(f,"%d",&adjMat[i][j]);
    fclose(f);
}
void printAdjMat()
{
    printf("The adjacency matrix is:\n   ");
    for(int i=0; i<nrOfVertixes; i++)
        printf("%c  ",i+'A');
    printf ("\n");
    for(int i=0; i<nrOfVertixes; i++)
    {
        printf("%c  ",i+'A');
        for(int j=0; j<nrOfVertixes; j++)
            printf("%d  ",adjMat[i][j]);
        printf("\n");
    }
}
void initializeList()
{
    for(int i=0; i<nrOfVertixes; i++)
        adjList[i]=NULL;
}

void addNode(int index,int node,int content)
{
    List * newElement=(List*)malloc(sizeof(List));
    if(newElement==NULL)
        return;
    newElement->node=node;
    newElement->cost=content;
    newElement->next=NULL;
    if(adjList[index]==NULL)
        adjList[index]=newElement;
    else
    {
        List * previous=adjList[index];
        while(previous)
        {
            if(previous->next==NULL)
            {
                previous->next=newElement;
                break;
            }
            previous=previous->next;
        }
    }
}
void adjListFromAdjMat()
{
    for(int i=0; i<nrOfVertixes; i++)
        for(int j=0; j<nrOfVertixes; j++)
            addNode(i,j,adjMat[i][j]);
}
void printAdjList()
{
    printf("\nThe adjacency list from adjacency matrix is:\n");
    List * element;
    for(int i=0; i<nrOfVertixes; i++)
        if(adjList[i]!=NULL)
        {
            printf("Neighbours of node %c: ",i+'A');
            element=adjList[i];
            int ok=0;
            while(element!=NULL)
            {
                if(element->cost>0)
                {
                    printf("%c with cost %d;",element->node+'A',element->cost);
                    ok=1;
                }
                element=element->next;
            }
            if(ok==0)
                printf("No neighbours.");
            printf("\n");
        }
}

void adjMatFromAdjList()
{
    List * element;
    int i;
    newAdjMat=(int**)malloc(sizeof(int*)*nrOfVertixes);
    for(i=0; i<nrOfVertixes; i++)
        *(newAdjMat+i)=(int*)malloc(sizeof(int)*nrOfVertixes);
    for(i=0;i<nrOfVertixes;i++)
        if(adjList[i]!=NULL)
        {
            element=adjList[i];
            while(element!=NULL)
            {
                if(element->cost>0)
                {
                    newAdjMat[i][element->node]=element->cost;
                }
                else newAdjMat[i][element->node]=0;
                element=element->next;
            }
        }
}

void printNewAdjMat()
{
    printf("\nThe adjacency matrix from adjacency list is:\n");
    for(int i=0; i<nrOfVertixes; i++)
        printf("%c  ",i+'A');
    printf ("\n");
    for(int i=0; i<nrOfVertixes; i++)
    {
        printf("%c  ",i+'A');
        for(int j=0; j<nrOfVertixes; j++)
            printf("%d  ",newAdjMat[i][j]);
        printf("\n");
    }
}
int main()
{
    FILE * f=fopen("input.dat","r");
    readAdjMat(f);
    printAdjMat();
    adjListFromAdjMat();
    printAdjList();
    adjMatFromAdjList();
    printNewAdjMat();
}
