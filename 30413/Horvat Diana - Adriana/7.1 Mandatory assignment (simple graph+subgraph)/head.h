#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_LENGTH 100

int *initializeArray();
int **initializeMatrix();
void initializeAdjMatrix(int **matrix, int *n);
char **initializeBuffer();
void constructGraph(int *nodesGraph, int *nodesSubGraph, int **adjMatrix, int *nrOfNodesGraph, int *nrOfNodesSubGraph,FILE *f);
void constructSubGraph(int *nodesSubGraph, int **adjMatrix, int *nrOfNodesSubGraph, FILE *g);
