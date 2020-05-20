#include <stdio.h>
#include "graphRepr.h"
#include "graphalgo.h"
#include "edge.h"
#define INFINITY 99999

void BF(Edge *ed,int n,int nrEdges,int start)
{
    printf("\nBF started\n");
    int *distance=(int*)malloc(sizeof(int)*MAX);
    for(int i=0;i<n;i++)
    {
        distance[i]=INFINITY;
    }
    distance[start]=0;
    for(int i=1;i<nrOfVertexes;i++)
    {
        for(int j=0;j<nrEdges;j++)
        {
            int source=ed[j].source;
            int dest=ed[j].destination;
            int we=ed[j].weight;
            if(distance[source]!=INFINITY && distance[dest]>distance[source]+we)
            {
                distance[dest]=distance[source]+we;
            }
        }
    }
    for(int i=1;i<n;i++)
    {
        printf(" %d ",distance[i]);
    }
}


int main() {
    FILE *f = fopen("input.txt", "r");
    readFromAdjMatrix(f);
    printAdjMatrix();
    kruskal();
    int nrOfEdges=getEdgesNo();
    Edge *ed=(Edge*)malloc(sizeof(Edge)*MAX);
    BF(ed,nrOfVertexes,nrOfEdges,0);
    return 0;
}
