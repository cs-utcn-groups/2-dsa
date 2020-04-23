#include <stdio.h>
#include "graphAdjMatrix.h"
#include "graphAdjList.h"
#include "graphTraversal.h"

#define MATRIX "../adjMatrix.txt"
#define LIST "../adjList.txt"

int main() {
    FILE *matrix = fopen(MATRIX, "r");
    FILE *list = fopen(LIST, "r");
    ///adjacency matrix -> adjacency list
    readAdjacencyMatrix(matrix);
    printAdjacencyList();
    checkBFS('G' - 'A');
    checkDFS('G' - 'A');


    ///adjacency list -> adjacency matrix
    readAdjacencyList(list);
    printAdjacencyMatrix();
    checkBFS('G' - 'A');
    checkDFS('G' - 'A');
    return 0;
}
