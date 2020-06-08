#include <stdio.h>
#include "graphAlgorithms.h"

int main()
{
    fin = fopen("input.dat", "r");

    int V, E;
    fscanf(fin, "%d", &V);

    initializeMatrix(V);
    E = inputMatrix(AdjMatrix, V);

    edgeT **edges = (edgeT**)malloc(E*sizeof(edgeT*));
    findEdges(edges, V);

    printf("\nKruskal algorithm for Miminum Spanning Tree:\n");
    kruskal(V, E, edges);

    printf("\nBellman-Ford algorithm for Miminum Spanning Tree:\n");
    bellmanFord(V, E, edges);

}