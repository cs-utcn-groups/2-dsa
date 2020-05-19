//
// Created by Diana on 04/05/2020.
//
#include "graph.h"
int getNumberOfNeighborsOfVertex (int v) {
    if(v < noOfVertices) {
        int noOfNeighbors = 0 ;
        for(int i=0;i<noOfVertices;i++) {
            if(adjMatrix[v][i]>0 && i!=v) {
                noOfNeighbors++;
            }
        }
        return noOfNeighbors;
    } else {
        return 0;
    }
}

int *getAllNeighborsOfVertex (int v) {
    if (v < noOfVertices) {
        int noOfNeighbors = getNumberOfNeighborsOfVertex(v);
        int * neighbors = (int *) malloc (noOfNeighbors * sizeof(int));
        int neighborIndex = 0;
        for (int i=0;i < noOfVertices; i++) {
            if(adjMatrix[v][i] > 0 && i!= v) {
                neighbors[neighborIndex] = i;
                neighborIndex++;
            }
        }
        return neighbors;
    } else {
        return NULL;
    }
}