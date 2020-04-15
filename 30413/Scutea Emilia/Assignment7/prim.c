#include "header.h"
Edge getMinEdge(int * visited)
{
    Edge minEdge;
    minEdge.weight=INFTY;
    for(int i=0; i<nrOfVertixes; i++)
    {
        for(int j=0; j<nrOfVertixes; j++)
        {
            if(visited[i]==VISITED && visited[j]==UNVISITED && cost[i][j]>0)
            {
                if(cost[i][j]<minEdge.weight)
                {
                    minEdge.source=i;
                    minEdge.destination=j;
                    minEdge.weight=cost[i][j];
                }
            }
        }
    }
    return minEdge;
}

void Prim(int startNode)
{
    printf("Prim's Algorithm:\n");
    int nrVisitedVertixes=0,i,minCost=0;
    int * visited=(int*)malloc(sizeof(int)*nrOfVertixes);
    for(i=0; i<nrOfVertixes; i++)
        visited[i]=UNVISITED;
    Edge * edges=(Edge*)malloc(sizeof(Edge)*(nrOfVertixes-1));
    visited[startNode]=VISITED;
    while(nrVisitedVertixes<nrOfVertixes-1)
    {
        Edge minEdge=getMinEdge(visited);
        visited[minEdge.destination]=VISITED;
        edges[nrVisitedVertixes++]=minEdge;
        minCost+=minEdge.weight;
    }
    for(int i=0; i<nrVisitedVertixes; i++)
        printf("%c -> %c\t",edges[i].source+'A',edges[i].destination+'A');
    printf("\nCost of MST is %d.\n",minCost);
}

