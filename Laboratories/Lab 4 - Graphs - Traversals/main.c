#include <stdio.h>
#include "graphRepresentation.h"
#include "graphTraversals.h"

int main() {
    FILE *f = fopen("matrix.txt", "r");
    readFromAdjMatrix(f);
    printAdjMatrix();
    bfs('G' - 'A');
    dfs('G' - 'A');
    dfsRecurs('G' - 'A');
    return 0;
}
