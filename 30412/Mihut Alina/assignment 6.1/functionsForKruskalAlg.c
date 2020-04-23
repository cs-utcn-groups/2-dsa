//
// Created by Alina Mihut on 4/13/20.
//
#include "functionsForKruskalAlg.h"

void sortEdges()
{
    int i,j;
    edgeT aux;

    for(i=1;i<eList->n;i++)
        for(j=0;j<eList->n-1;j++)
            if(eList->data[j].weight>eList->data[j+1].weight)
            {
                aux=eList->data[j];
                eList->data[j]=eList->data[j+1];
                eList->data[j+1]=aux;
            }
}

int findVertexInConnectedComponent(int *component, int vertexNo)
{
    return(component[vertexNo]);
}

void UNION(int *belongs, int a,int b)
{
    int i;
    for(i=0;i<nrOfVertexes;i++)
        if(belongs[i]==a)
            belongs[i]=b;
}

void printSpanningTree()
{
    int cost=0;

    for(int i=0;i<spanningTree->n;i++)
    {
        printf("\n %d   %d   %d",spanningTree->data[i].source, spanningTree->data[i].destination, spanningTree->data[i].weight);
        cost=cost+spanningTree->data[i].weight;
    }

    printf("\n Cost of the spanning tree=%d \n",cost);
}
