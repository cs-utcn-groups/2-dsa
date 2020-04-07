#include <stdio.h>
#include "graphRepresentation.h"
#include "graphTraversals.h"
#include "graphAlgorithms.h"

int main() {
    FILE *f = fopen("matrix.txt", "r");
    readFromAdjMatrix(f);
    printAdjMatrix();
    bfs('G' - 'A');
    dfs('G' - 'A');
    dfsRecurs('G' - 'A');
    prim(0);
    dijkstra(6);
    return 0;
}
