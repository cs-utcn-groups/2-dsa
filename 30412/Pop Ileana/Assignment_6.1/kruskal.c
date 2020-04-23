//
// Created by ileana on 4/11/2020.
//

#include "kruskal.h"

edgeT getMinimumEdgeForAdjacencyMatrix(int ** adjMat)
{
    edgeT minimumEdge;
    minimumEdge.weight = MAX;

    for(int i = 0;i < nrOfVertexes; i++) {
        for (int j = 0; j < nrOfVertexes; j++)
            if (adjMat[i][j] < minimumEdge.weight && adjMat[i][j] > 0) {
                minimumEdge.weight = adjMat[i][j];
                minimumEdge.source = i;
                minimumEdge.destination = j;
            }
    }
    adjMat[minimumEdge.source][minimumEdge.destination]=0;
    adjMat[minimumEdge.destination][minimumEdge.source]=0;
    return minimumEdge;
}

int ** getCopyOfAdjacencyMatrix()
{
    int i,j;
    int ** copyAdjMatrix =(int**)malloc(nrOfVertexes*sizeof(int*));
    for (i=0; i<nrOfVertexes; i++)
    {
        *(copyAdjMatrix+i)=(int*)malloc(nrOfVertexes*sizeof(int));
        for(j=0; j<nrOfVertexes; j++)
        {
            copyAdjMatrix[i][j] = adjMatrix[i][j];
        }
    }
    return copyAdjMatrix;
}

int getParent(const int * parent, int i)
{
    while(parent[i]!=i)
        i = parent[i];
    return i;
}


void uni(int * parent, int i,int j)
{
    i=getParent(parent,i);
    j=getParent(parent,j);
    parent[i]=j;
}

void printEdges(edgeT *edges, int n) {
    int i;
    for (i = 0; i < n; i++) {
        printf("%c -> %c\t", edges[i].source + 'A', edges[i].destination + 'A');
    }
    printf("\n");
}

void kruskal()
{
    printf("Kruskal started\n");
    int minCost = 0;
    int ** adjMat = getCopyOfAdjacencyMatrix();

    edgeT *edges = (edgeT *) malloc(sizeof(edgeT) * (nrOfVertexes - 1));
    int nrEdgesAdded = 0;
    int * parent = (int *) malloc (nrOfVertexes * sizeof(int));

    for(int i = 0; i < nrOfVertexes; i++)
        parent[i]=i;

    while(nrEdgesAdded < nrOfVertexes - 1)
    {
        edgeT minEdge = getMinimumEdgeForAdjacencyMatrix(adjMat);
        if(getParent(parent,minEdge.source)!=getParent(parent,minEdge.destination))
        {
            uni(parent,minEdge.source,minEdge.destination);
            edges[nrEdgesAdded++]=minEdge;

            minCost = minCost+minEdge.weight;
        }

    }
    printEdges(edges, nrEdgesAdded);
    printf("Cost of MST by Kruskal's Algorithm: %d\n", minCost);

    printf("Kruskal ended\n\n");
}
