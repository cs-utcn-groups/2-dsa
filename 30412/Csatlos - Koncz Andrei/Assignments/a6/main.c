#include <stdio.h>
#include "graphRepresentation.h"
#include "graphTraversals.h"
#include "graphAlgorithms.h"

int main() {
    FILE *f = fopen("../edges.txt", "r");
    //readFromAdjMatrix(f);
    //printAdjMatrix();
    readFromListOfWeightedGraph(f);
    printEdges();
    kruskal();
    bellmanFord(0);
    /*
    bfs('G' - 'A');
    dfs('G' - 'A');
    dfsRecurs('G' - 'A');
    prim(0);
    dijkstra(6);
     */
    fclose(f);
    return 0;
}

/*
7 11
1 2 2
1 7 4
2 3 3
2 5 2
2 6 3
2 7 3
3 4 1
3 5 2
4 5 1
5 6 3
6 7 5
 */