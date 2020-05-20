#include <stdio.h>
#include "Functions.h"

int main()
{
    f = fopen("../dataIn.txt", "r");
    if(f == NULL)
        perror("FILE NOT FOUND!");

    int V, E;
    fscanf(f, "%d", &V);

    InitMatrix(V);
    E = readMatrix(AdjMatrix, V);

    edgeT **edges = (edgeT**)malloc(sizeof(edgeT*)*E);
    getEdges(edges, V);

    kruskal(V, E, edges);
    bellmanFord(V, E, edges);

}