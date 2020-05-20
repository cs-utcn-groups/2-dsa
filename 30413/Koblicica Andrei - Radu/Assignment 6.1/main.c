#include <stdio.h>
#include "graphRepresentation.h"
#include "graphAlgorithms.h"


int main() {
    FILE *f = fopen("matrix.txt", "r");
    readFromAdjMatrix(f);
    printAdjMatrix();
    kruskal();
    belmanford(0);
    return 0;
}
