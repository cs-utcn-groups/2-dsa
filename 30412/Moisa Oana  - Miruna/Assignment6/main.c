#include <stdio.h>
#include "graphRepresentation.h"
#include "graphAlgorithms.h"
#define FILE_PATH "../matrix.txt"

int main() {
    FILE *f=fopen(FILE_PATH,"r");
    readFromAdjMatrix(f);
    printAdjMatrix();
    Kruskal();
    BellmanFord(0);
    return 0;
}
