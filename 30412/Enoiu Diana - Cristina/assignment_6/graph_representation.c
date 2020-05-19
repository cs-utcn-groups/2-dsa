//
// Created by Diana on 04/05/2020.
//

#include <stdlib.h>
#include <stdio.h>
#include "graph.h"

void readFromAdjMatrix (FILE*f) {
    fscanf(f, "%d",&noOfVertices);
    adjMatrix = (int **) malloc (noOfVertices * sizeof (int *));
    for (int i=0; i< noOfVertices; i++) {
        adjMatrix[i] = (int *) malloc (noOfVertices * sizeof (int));
    }
    for (int i=0;i<noOfVertices;i++) {
        for (int j=0;j<noOfVertices;j++) {
            fscanf(f,"%d",&adjMatrix[i][j]);
        }
    }
}
void printAdjMatrix() {
    int i, j;

    printf("\nThe matrix is:\n");
    printf("    ");
    for (i = 0; i < noOfVertices; i++) {
        printf("%c   ", 'A' + i);
    }
    printf("\n");
    for (i = 0; i < noOfVertices; i++) {
        printf("%c ", 'A' + i);
        for (j = 0; j < noOfVertices; j++)
            printf("%3d ", adjMatrix[i][j]);
        printf("\n");
    }
    printf("\n");
}