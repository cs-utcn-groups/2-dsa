#include <stdio.h>
#include "graphRepresentation.h"
#include "graphTraversals.h"
#include "graphAlgorithms.h"
#include "graphTraversals.c"
#include "graphRepresentation.c"
#include "graphAlgorithms.c"
#include "node.c"
#include "queue.c"

int main() {
    FILE *f = fopen("D:\\Facultate\\SEM2\\DSA\\MyProblems\\Assignment6\\matrix.txt", "r");
    readFromAdjMatrix(f);
    printAdjMatrix();

    bfs('G' - 'A');
    dfs('G' - 'A');
    dfsRecurs('G' - 'A');
    prim(0);
    dijkstra(6);

    kruskal();
    bellmanford(6);

    return 0;
}