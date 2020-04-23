#include <stdio.h>
#include "graphRepresentation.h"
#include "list.h"
#include "graphTraversals.h"
#include "matrix.h"
int main() {
    FILE *f=fopen ("../date.in", "r");
    readFromAdjMatrix(f);
    List *adjList2=createListFromMatrix();
    printList (adjList2);
    BFS('D'-'A', adjList2);
    DFS('D'-'A', adjList2);
    DFSRecurs('D'-'A', adjList2);
    createMatrixFromList(adjList2);
    printMatrix();
    return 0;
}