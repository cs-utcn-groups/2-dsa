//
// Created by bindi on 4/6/2020.
//
#include <stdio.h>
#include <stdlib.h>
#include "graph.h"

void readAdjacencyMatrix(FILE *input) {
    fscanf(input, "%d", &noOfVertices);
    adjMatrix = (int **) malloc(noOfVertices * sizeof(int *));
    for (int i = 0; i < noOfVertices; ++i) {
        adjMatrix[i] = (int *) malloc(noOfVertices * sizeof(int));
        for (int j = 0; j < noOfVertices; ++j) {
            fscanf(input, "%d", &adjMatrix[i][j]);
        }
    }
    fclose(input);
}

void printAdjacencyMatrix(void) {
    printf("The adjacency matrix is:\n");
    printf("     ");
    for (int i = 0; i < noOfVertices; ++i) {
        printf("%c   ", 'A' + i);
    }
    printf("\n");
    for (int i = 0; i < noOfVertices; ++i) {
        printf("%c  ", 'A' + i);
        for (int j = 0; j < noOfVertices; ++j) {
            printf("%3d ", adjMatrix[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}