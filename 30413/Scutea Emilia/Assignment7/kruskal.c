#include "header.h"
Edge * getArrayOfEdges()
{
    int i,j,k=0;
    nrOfEdges=nrOfVertixes*(nrOfVertixes-1)/2;
    Edge * edge =(Edge*)malloc(sizeof(Edge)*nrOfEdges);
    for(i=0; i<nrOfVertixes; i++)
        for(j=0; j<nrOfVertixes; j++)
            if(i<j && cost[i][j]>0)
            {
                edge[k].source=i;
                edge[k].destination=j;
                edge[k].weight=cost[i][j];
                k++;
            }
    nrOfEdges=k;
    return edge;
}
void ascendingOrderEdges()
{
    int done=0;
    Edge * aux=(Edge*)malloc(sizeof(Edge));
    while(done!=1)
    {
        done=1;
        for(int i=0; i<nrOfEdges-1; i++)
            if(edges[i].weight>edges[i+1].weight)
            {
                *aux=edges[i];
                edges[i]=edges[i+1];
                edges[i+1]=*aux;
                done=0;
            }
    }
}
Edge getMinimumEdge(int * visited)
{
    Edge minEdge;
    minEdge.weight=INFTY;
    for(int i=0;i<nrOfEdges;i++)
    {
        if(edges[i].weight<minEdge.weight && visited[edges[i].destination]!=visited[edges[i].source])
        {
            minEdge=edges[i];
            edges[i].weight=0;
            i=nrOfEdges;
        }
    }
    return minEdge;

}
void Kruskal(int startNode)
{
    printf("Kruskal's Algorithm:\n");
    int * visited=(int*)malloc(sizeof(int)*nrOfVertixes);
    int nrVisitedVertixes=0,i,minCost=0;
    for(i=0; i<nrOfVertixes; i++)
        visited[i]=UNVISITED;
    visited[startNode]=VISITED;
    Edge * edgesArray=(Edge*)malloc(sizeof(Edge)*(nrOfVertixes-1));

    while(nrVisitedVertixes<nrOfVertixes-1)
    {
        Edge minEdge=getMinimumEdge(visited);
        visited[minEdge.source]=VISITED;
        visited[minEdge.destination]=VISITED;
        edgesArray[nrVisitedVertixes++]=minEdge;
        minCost=minCost+minEdge.weight;
    }

    for(int i=0; i<nrVisitedVertixes; i++)
        printf("%c -> %c\t",edgesArray[i].source+'A',edgesArray[i].destination+'A');
    printf("\nCost of MST by Kruskal is %d.\n\n",minCost);
}
