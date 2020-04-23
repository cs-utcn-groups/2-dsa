#include <stdio.h>
#include "graphRepresentation.h"
#include "graphAlgorithms.h"
int main() {
    FILE *f = fopen("../matrix.txt", "r");
    readFromAdjMatrix(f);
    printAdjMatrix();
    kruskalAlgorithm();
    bellmanFord(3);
    return 0;
}