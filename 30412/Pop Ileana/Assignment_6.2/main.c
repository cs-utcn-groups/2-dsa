#include <stdio.h>
#include "graphRepresentation.h"
#include "vertexCover.h"
#define DATA_PATH "../matrix.txt"


int main() {

    FILE *f = fopen(DATA_PATH, "r");
    readFromAdjMatrix(f);
    printAdjMatrix();
    vertexCover();
    printCoverSet();
    return 0;
}