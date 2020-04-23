#include <stdio.h>
#include "graphRepresentation.h"
#include "node.h"
#define FILE_PATH "../matrix.txt"

int main() {
    FILE *f = fopen(FILE_PATH, "r");
    readFromAdjMatrix(f);
    printMatrix(adjM);
    printf("Enter the 2 nodes:\n");
    int source, destination;
    scanf("%d",&source);
    scanf("%d",&destination);
    dfsRecurs(source,destination);
    return 0;
}
