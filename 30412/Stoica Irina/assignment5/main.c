#include <stdio.h>
#include "graphRepresentation.h"
#include "graphTraversals.h"
#include "list operations.h"

int main() {
    FILE *f = fopen("..//matrix.txt", "r");
    readFromAdjMatrix(f);
    printAdjMatrix();
    bfs('G' - 'A');
    dfs('G' - 'A');
    dfsRecurs('G' - 'A');

    NodeT ** listArray = (NodeT**)malloc(nrOfVertexes * sizeof(NodeT*));
    listArray = matrixToList(listArray);
    printList(listArray);
    listToMatrix(listArray);
    printMatrix();

    bfs_list('G' - 'A', listArray);
    dfs_list('G' - 'A', listArray);
    return 0;
}