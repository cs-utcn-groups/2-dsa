#include <stdlib.h>
#include "graphRepr.h"

void readFromAdjMatrix(FILE *f) {
    int n;
    fscanf(f, "%d", &n);
    nrOfVertexes = n;
    int i, j;
    adjMatrix = (int **) malloc(n * sizeof(int *));
    for (i = 0; i < n; i++) {
        *(adjMatrix + i) = (int *) malloc(n * sizeof(int));
    }

    for (i = 0; i < n; i++)
        for (j = 0; j < n; j++)
            fscanf(f, "%d", &adjMatrix[i][j]);
    fclose(f);
}

void printAdjMatrix() {
    int i, j;

    printf("\nThe matrix is:\n");
    printf("    ");
    for (i = 0; i < nrOfVertexes; i++) {
        printf("%c   ", 'A' + i);
    }
    printf("\n");
    for (i = 0; i < nrOfVertexes; i++) {
        printf("%c ", 'A' + i);
        for (j = 0; j < nrOfVertexes; j++)
            printf("%3d ", adjMatrix[i][j]);
        printf("\n");
    }
    printf("\n");
}

