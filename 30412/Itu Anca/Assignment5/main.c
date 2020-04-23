#include <stdio.h>
#include "graphRepresentation.h"
#include "graphTraversals.h"
#include "graphTraversals.c"
#include "graphRepresentation.c"
#include "node.c"
#include "queue.c"

int main() {
    FILE *f = fopen("D:\\Facultate\\SEM2\\DSA\\Assignment5\\matrix.txt", "r");
    readFromAdjMatrix(f);
    printAdjMatrix();

    createListFromMatrix();
    printList();

    BFSfromList('G' - 'A');
    DFSfromList('G' - 'A');

    createMatrixFromList();
    printAdjMatrix();

    BFS('G' - 'A');
    DFS('G' - 'A');
    return 0;
}