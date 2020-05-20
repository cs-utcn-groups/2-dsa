#include <stdio.h>
#include "graphRepresentation.h"
#include "graphTraversals.h"
#include "list.h"

int main() {
    FILE *f = fopen("matrix.txt", "r");
    readFromAdjMatrix(f);
    printAdjMatrix();

    bfsFromMatrix('G'-'A');
    dfsFromMatrix('G'-'A');
    dfsRecurs('G'-'A');

    matrixToList();
    printAdjList();

    listToMatrix();
    printAdjMatrix();

    bfsFromList('G'-'A');
    dfsFromList('G'-'A');
    return 0;
}
