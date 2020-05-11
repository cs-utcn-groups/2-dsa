#include <stdio.h>
#include "adj-matrix.h"
#include "adj-list-graph.h"
#include "graph-traversals.h"
#include "longest-path.h"
#include "prim.h"
#include "dijkstra.h"

#define NR_VERTICES 5

int main() {
    setbuf(stdout, 0);
    AdjMatrix *myMatrix = createAdjMatrix(NR_VERTICES);
    addEdgeToMatrix(myMatrix, 1, 2, 1);
    addEdgeToMatrix(myMatrix, 2, 1, 1);
    addEdgeToMatrix(myMatrix, 2, 3, 1);
    addEdgeToMatrix(myMatrix, 3, 2, 1);
    addEdgeToMatrix(myMatrix, 0, 4, 1);
    addEdgeToMatrix(myMatrix, 4, 0, 1);
    addEdgeToMatrix(myMatrix, 4, 3, 1);
    addEdgeToMatrix(myMatrix, 3, 4, 1);
    //printAdjMatrix(myMatrix, stdout);

    Graph *myGraph = createNewGraph(NR_VERTICES);
    addEdgeToGraph(myGraph, 1, 2, 1);
    addEdgeToGraph(myGraph, 2, 1, 1);
    addEdgeToGraph(myGraph, 2, 3, 1);
    addEdgeToGraph(myGraph, 3, 2, 1);
    addEdgeToGraph(myGraph, 0, 4, 1);
    addEdgeToGraph(myGraph, 4, 0, 1);
    addEdgeToGraph(myGraph, 4, 3, 1);
    addEdgeToGraph(myGraph, 3, 4, 1);
    //printGraph(myGraph, stdout);

    //matrixDFS(myMatrix, 2, stdout);
    //listDFS(myGraph, 2, stdout);
    //iterativeListDFS(myGraph, 2, stdout);

    //iterativeMatrixBFS(myMatrix, 2, stdout);
    //iterativeListBFS(myGraph, 2, stdout);

    //findLongestPath(myGraph, 1, 4, stdout);

    Graph *weightedGraph = createNewGraph(NR_VERTICES);
    addEdgeToGraph(weightedGraph, 0, 1, 3);
    addEdgeToGraph(weightedGraph, 1, 0, 3);
    addEdgeToGraph(weightedGraph, 0, 2, 2);
    addEdgeToGraph(weightedGraph, 2, 0, 2);
    addEdgeToGraph(weightedGraph, 0, 3, 3);
    addEdgeToGraph(weightedGraph, 3, 0, 3);
    addEdgeToGraph(weightedGraph, 1, 3, 4);
    addEdgeToGraph(weightedGraph, 3, 1, 4);
    addEdgeToGraph(weightedGraph, 1, 4, 5);
    addEdgeToGraph(weightedGraph, 4, 1, 5);
    addEdgeToGraph(weightedGraph, 2, 3, 8);
    addEdgeToGraph(weightedGraph, 3, 2, 8);
    addEdgeToGraph(weightedGraph, 3, 4, 2);
    addEdgeToGraph(weightedGraph, 4, 3, 2);

    printGraph(weightedGraph, stdout);
    prim(weightedGraph, 1, stdout);

    dijkstra(weightedGraph, 1, stdout);

    freeGraph(&weightedGraph);
    freeAdjMatrix(&myMatrix);
    freeGraph(&myGraph);
    return 0;
}