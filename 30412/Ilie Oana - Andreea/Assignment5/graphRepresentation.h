//
// Created by andre on 06.05.2020.
//

#ifndef ASSIGNMENT5_GRAPHREPRESENTATION_H
#define ASSIGNMENT5_GRAPHREPRESENTATION_H

#include "graph.h"
#include "list.h"

int **createMatrix(int noOfVertices);

void initializeMatrix(int noOfVertices, int **adjMatrix);

int getNumberOfVertices(FILE *inputFile);

int **getAdjMatrix(FILE *inputFile, int noOfVertices);

void printAdjMatrix(FILE *outputFile, int noOfVertices, int **adjMatrix);

int getNumberOfNeighboursOfVertex(int noOfVertices, int **adjMatrix, int v);

int *getAllNeighboursOfVertex(int noOfVertices, int **adjMatrix, int v);

ListT *convertMatrixToList(int noOfVertices, int **adjMatrix);

void freeAdjMatrix(int noOfVertices, int **adjMatrix);

int **convertListToMatrix(int noOfVertices, ListT *adjList);

#endif //ASSIGNMENT5_GRAPHREPRESENTATION_H
