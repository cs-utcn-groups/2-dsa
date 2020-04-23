#include <stdio.h>
#include "graphRepresentation.h"
#include "graphAlgorithms.h"

int main() {
    FILE *f = fopen("input.dat", "r");
    readFromAdjMatrix(f);
    printAdjMatrix();
    kruskalMST();
    bellmanFord(6);
    return 0;
}