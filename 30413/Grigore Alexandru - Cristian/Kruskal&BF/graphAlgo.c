#include "graphalgo.h"
#include "graphRepr.h"
#include "edge.h"
#define INFINITY 99999

void sort()
{
    Edge aux;
    for(int i=1;i<eList->n;i++)
    {
        for(int j=0;j<eList->n-1;j++)
        {
            if(eList->data[j].weight>eList->data[j+1].weight)
            {
                aux=eList->data[j];
                eList->data[j]=eList->data[j+1];
                eList->data[j+1]=aux;
            }
        }
    }
}

int findVertex(int *belongs,int vertexNr)
{
    return belongs[vertexNr];
}

void Union(int *belongs,int a,int b)
{
    for(int i=0;i<nrOfVertexes;i++)
    {
        if(belongs[i]==b)
        {
            belongs[i]=a;
        }
    }
}

void printSpan()
{
    int cost=0;
    for(int i=0;i<spanningTree->n;i++)
    {
        printf("\n %d   %d   %d",spanningTree->data[i].source,spanningTree->data[i].destination,spanningTree->data[i].weight);
        cost+=spanningTree->data[i].weight;
    }
    printf("\nCost of tree: %d\n",cost);
}

void kruskal()
{
    printf("\nKruskal started\n");
    int *belongs=(int*)malloc(sizeof(int)*MAX);
    int i,j,c1,c2;
    eList=createEdge();
    spanningTree=createEdge();
    eList->n=0;
    for(i=1;i<nrOfVertexes;i++)
    {
        for(j=0;j<nrOfVertexes;j++)
        {
            if(adjMatrix[i][j]!=0)
            {
                eList->data[eList->n].source=i;
                eList->data[eList->n].destination=j;
                eList->data[eList->n].weight=adjMatrix[i][j];
                eList->n++;
            }
        }
    }
    sort();
    for(i=0;i<nrOfVertexes;i++)
    {
        belongs[i]=i;
    }
    spanningTree->n=0;
    for(i=0;i<eList->n;i++)
    {
        c1=findVertex(belongs,eList->data[i].source);
        c2=findVertex(belongs,eList->data[i].destination);
        if(c1!=c2)
        {
            spanningTree->data[spanningTree->n]=eList->data[i];
            spanningTree->n=spanningTree->n+1;
            Union(belongs,c1,c2);
        }
    }
    printSpan();
    printf("\nKruskal ended\n");
}

int getEdgesNo()
{
    int nrOfEdges=0;
    for(int i=0;i<nrOfVertexes;i++)
    {
        for(int j=0;j<nrOfVertexes;j++)
        {
            if(adjMatrix[i][j]!=0)
            {
                nrOfEdges++;
            }
        }
    }
    return nrOfEdges;
}

