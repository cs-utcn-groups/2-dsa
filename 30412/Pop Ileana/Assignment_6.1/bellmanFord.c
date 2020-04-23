//
// Created by ileana on 4/11/2020.
//


#include "bellmanFord.h"

//Bellman Ford Algorithm

int getNrOfEdges()
{
    int nrEdges = 0;
    for(int i=0; i<nrOfVertexes;i++)
        for(int j=0;j<nrOfVertexes;j++)
            if(adjMatrix[i][j]!=0)
                nrEdges++;
    return nrEdges;
}

edgeT * getEdgeList()
{
    int nrEdges = getNrOfEdges();
    edgeT * edges = (edgeT*)malloc(nrEdges*sizeof(edgeT));
    nrEdges=0;
    for(int i = 0;i < nrOfVertexes; i++)
        for(int j = 0; j < nrOfVertexes; j++)
            if(adjMatrix[i][j]!=0)
            {
                edgeT newEdge;
                newEdge.source=i;
                newEdge.destination=j;
                newEdge.weight=adjMatrix[i][j];
                edges[nrEdges++]=newEdge;
            }
    return edges;
}

void bellmanFord(int startNode)
{
    printf("Bellman Ford started\n");

    edgeT * edges = getEdgeList();

    int *distances = (int *) malloc(nrOfVertexes * sizeof(int));
    int *previous = (int *) malloc(nrOfVertexes * sizeof(int));

    int nrEdges = getNrOfEdges();

    for (int i = 0; i < nrOfVertexes; i++) {
        distances[i] = MAX;
        previous[i] = UNDEFINED;
    }

    distances[startNode] = 0;


    for(int i = 0; i < nrOfVertexes-1;i ++)
        for(int j = 0; j < nrEdges ;j++)
        {
            int u = edges[j].source;
            int w = edges[j].destination;
            int weight = edges[j].weight;
            int alt = distances[u] + weight;
            if(alt < distances[w])
            {
                distances[w] = alt;
                previous[w] = u;
            }
        }

    int detectNegativeCycles = 0;

    for(int j = 0; j < nrEdges;j++)
    {
        int u = edges[j].source;
        int w = edges[j].destination;
        int weight = edges[j].weight;
        int alt = distances[u] + weight;
        if(alt < distances[w]) {
            detectNegativeCycles = 1;
            break;
        }
    }

    if(detectNegativeCycles == 1)
        printf("The graph contains negative cycles\n");
    else
    {
        for (int i = 0; i < nrOfVertexes; i++) {
            int u = i;
            if (i != startNode) {
                while (previous[u] != UNDEFINED) {
                    push(u);
                    u = previous[u];
                }

                printf("Path from %c to %c is: %c ", startNode + 'A', i + 'A', startNode + 'A');
                while (!isEmptyStack()) {
                    printf(" -> %c ", peekStack()->content + 'A');
                    pop();
                }
                printf("\n");
            }
        }

    }

    printf("Bellman Ford's Algorithm ended\n");
}