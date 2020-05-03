/*
 Kruskal
1. Sort all the edges in non-decreasing order of their weight.
2. Pick the smallest edge. Check if it forms a cycle with the spanning tree formed so far. If cycle is not formed, include this edge. Else, discard it.
3. Repeat step#2 until there are (V-1) edges in the spanning tree.
 */

#include "Kruskal.h"

edgeT getMinimumEdgeForAdjacencyMatrix(int **adjMat,int *parent) {
    edgeT minEdge;
    minEdge.weight = MAX;
    for (int i = 0; i < nrOfVertexes; i++) {
        for (int j = 0; j < nrOfVertexes; j++) {
            if (adjMat[i][j] < minEdge.weight && adjMat[i][j] != 0 && getParent(parent, i) != getParent(parent, j)) {
                minEdge.weight = adjMat[i][j];
                minEdge.source = i;
                minEdge.destination = j;
            }
        }
    }
    adjMat[minEdge.source][minEdge.destination] = 0;
    adjMat[minEdge.destination][minEdge.source] = 0;
    return minEdge;
}

int **getCopyOfAdjecencyMatrix() {
    int i, j;
    int **copyAdjMatrix = (int **) malloc(nrOfVertexes * sizeof(int *));
    for (i = 0; i < nrOfVertexes; i++) {
        *(copyAdjMatrix + i) = (int *) malloc(nrOfVertexes * sizeof(int));
        for (j = 0; j < nrOfVertexes; j++) {
            copyAdjMatrix[i][j] = adjMatrix[i][j];
        }
    }
    return copyAdjMatrix;
}


int *initializeParentArray(int noOfVertices) {
    int *parent = (int *) malloc(noOfVertices * sizeof(int));
    for (int i = 0; i < noOfVertices; i++) {
        parent[i] = i;
    }
    return parent;
}

int getParent(const int *parent, int i) {
    while (parent[i] != i) {
        i = parent[i];
    }
    return i;
}

void uni(int *parent, int i, int j){
    i = getParent(parent, i);
    j = getParent(parent, j);
    if (i != j) {
        parent[i] = j;
    }
}

void order(int noOfEdges,edgeT *m){
    int i,j,sem;
    edgeT x;
    j=-1;
    do
    {
        sem=1;
        j++;
        for(i=1;i<noOfEdges-j;i++)
            if(m[i].weight>m[i+1].weight)
            {
                x=m[i];
                m[i]=m[i+1];
                m[i+1]=x;
                sem=0;
            }
    }while(sem==0);
}

void kruskal(FILE *fout) {
    fprintf(fout,"Kruskal algorithm started:\n");
    int **adjMat = getCopyOfAdjecencyMatrix();
    edgeT *edges = (edgeT *) malloc(sizeof(edgeT) * (nrOfVertexes - 1));
    int *parent = initializeParentArray(nrOfVertexes);
    int minCost = 0, noOfEdges = 0;

    while (noOfEdges < nrOfVertexes - 1) {
        edgeT minEdge = getMinimumEdgeForAdjacencyMatrix(adjMat,parent);
        edges[noOfEdges++] = minEdge;
        uni(parent, minEdge.source, minEdge.destination);
        minCost += minEdge.weight;
    }
    printEdges(fout, edges, noOfEdges);
    fprintf(fout, "Cost: %d", minCost);
    fprintf(fout, "\nKruskal algorithm ended");
}