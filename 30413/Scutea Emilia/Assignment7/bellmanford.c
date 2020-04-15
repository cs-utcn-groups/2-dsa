#include "header.h"
Edge * getArrayEdges()
{
    int i,j,k=0;
    nrOfEdges=nrOfVertixes*(nrOfVertixes-1)/2;
    Edge * edge =(Edge*)malloc(sizeof(Edge)*nrOfEdges);
    for(i=0; i<nrOfVertixes; i++)
        for(j=0; j<nrOfVertixes; j++)
            if(cost[i][j]!=0)
            {
                edge[k].source=i;
                edge[k].destination=j;
                edge[k].weight=cost[i][j];
                k++;
            }
    nrOfEdges=k;
    return edge;
}

void Bellmanford(int startNode)
{
    printf("Bellmanford Algorithm:\nThe start node is %c.\n",startNode+'A');
    int i,index=0,verify=0;;
    int * dist=(int*)malloc(sizeof(int)*nrOfVertixes);
    for(i=0;i<nrOfVertixes;i++)
        dist[i]=INFTY;
    dist[startNode]=0;
    while(index<nrOfVertixes-1 && verify==0)
    {
        verify=1;
        for(i=0;i<nrOfEdges;i++)
        {
            int src=edges[i].source;
            int dst=edges[i].destination;
            if(dist[src]+cost[src][dst]<dist[dst])
            {
                dist[dst]=dist[src]+cost[src][dst];
                verify=0;
            }
        }
        index++;
    }
    for(i=0;i<nrOfVertixes;i++)
        printf("The distance from the start node to %c is %d.\n",i+'A',dist[i]);
}
