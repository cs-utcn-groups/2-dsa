#include <stdio.h>
#include "graph.h"

int main() {
    FILE * f;
    f = fopen("../matrix.txt","r");
    readFromAdjMatrix(f);
    fclose(f);
    printAdjMatrix();
    bfs(1);
    dfs(3);
    dfsRecursive(3);
    prim(2);
    dijkstra(4);
    kruskal();
    BellmanFord(0);
    return 0;
}