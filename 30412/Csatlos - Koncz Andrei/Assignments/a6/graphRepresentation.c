//
// Created by csatl on 4/8/2020.
//

#include <stdlib.h>

#include "graphRepresentation.h"

void readFromListOfWeightedGraph(FILE *f)
{
    fscanf(f,"%d %d",&nrOfVertexes,&nrOfEdges);
    edge = (edgeT*) malloc(nrOfEdges * sizeof(edgeT));
    for(int i=0; i<nrOfEdges; i++){
        fscanf(f,"%d %d %d",&edge[i].source,&edge[i].destination,&edge[i].weight);
        edge[i].added = false;
    }

}

void sortEdgeByWeight(edgeT* edge)
{
    int ok = 0;
    while(!ok)
    {
        ok = 1;
        for(int i=0; i<nrOfEdges-1; i++)
        {
            if(edge[i].weight>edge[i+1].weight)
            {
                edgeT aux;
                aux = edge[i];
                edge[i] = edge[i+1];
                edge[i+1] = aux;
                ok = 0;
            }
        }
    }
}

void printEdges()
{
    printf("The EDGES are:\n");
    for(int i = 0; i<nrOfEdges; i++)
    {
        printf("%d %d %d\n",edge[i].source, edge[i].destination, edge[i].weight);
    }
    printf("Those were the edges\n");
}

void readFromAdjMatrix(FILE *f) {
    int n;
    fscanf(f, "%d", &n);
    nrOfVertexes = n;
    int i, j;
    adjMatrix = (int **) malloc(n * sizeof(int *));
    for (i = 0; i < n; i++) {
        *(adjMatrix + i) = (int *) malloc(n * sizeof(int));
    }

    for (i = 0; i < n; i++)
        for (j = 0; j < n; j++)
            fscanf(f, "%d", &adjMatrix[i][j]);
    fclose(f);
}

void printAdjMatrix() {
    int i, j;

    printf("\nThe matrix is:\n");
    printf("    ");
    for (i = 0; i < nrOfVertexes; i++) {
        printf("%c   ", 'A' + i);
    }
    printf("\n");
    for (i = 0; i < nrOfVertexes; i++) {
        printf("%c ", 'A' + i);
        for (j = 0; j < nrOfVertexes; j++)
            printf("%3d ", adjMatrix[i][j]);
        printf("\n");
    }
    printf("\n");
}


int getNumberOfNeighborsOfVertex(int v) {
    if (v < nrOfVertexes) {
        int nrOfNeighbors = 0;
        int i;
        for (i = 0; i < nrOfVertexes; i++) {
            if (adjMatrix[v][i] > 0 && i != v) {
                nrOfNeighbors++;
            }
        }
        return nrOfNeighbors;
    } else {
        return 0;
    }
}

int *getAllNeighborsOfVertex(int v) {
    if (v < nrOfVertexes) {
        int nrOfNeighbors = getNumberOfNeighborsOfVertex(v);
        int *neighbors = (int *) malloc(sizeof(int) * nrOfNeighbors);
        int i, j = 0;
        for (i = 0; i < nrOfVertexes; i++) {
            if (adjMatrix[v][i] > 0 && i != v) {
                neighbors[j] = i;
                j++;
            }
        }
        return neighbors;
    } else {
        return NULL;
    }
}
