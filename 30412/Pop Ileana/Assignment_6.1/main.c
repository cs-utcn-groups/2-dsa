#include <stdio.h>
#include "graphRepresentation.h"
#include "kruskal.h"
#include "bellmanFord.h"
#define DATA_PATH1 "../matrix.txt"
#define DATA_PATH2 "../matrix1.txt"
#define DATA_PATH3 "../matrix2.txt"

int main() {

    FILE *f = fopen(DATA_PATH1, "r");
    readFromAdjMatrix(f);
    printAdjMatrix();
    kruskal();
    fclose(f);

    f = fopen(DATA_PATH2, "r");
    readFromAdjMatrix(f);
    printAdjMatrix();
    bellmanFord(0);
    fclose(f);

    f = fopen(DATA_PATH3, "r");
    readFromAdjMatrix(f);
    printAdjMatrix();
    bellmanFord(0);
    fclose(f);
    return 0;
}