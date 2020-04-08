#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#define MAX_LENGTH 250
#define infinity -99999999

int **initializeMatrix();
int *initializeArray();
char **initializeBuffer();
void initializeCostValues(int **cost, int *n);
void initializeAdjMatrix(int **matrix, int *n);
void constructGraph(FILE *f, int **cost, int *nrOfNodes, int *nodesGraph);
int findMax(int *dist, int *nrOfNodes, int *visited);
void longestPath(int a, int b, int *nrOfNodes, int **cost, FILE *g);
int findNode(int *nrOfNodes,int *nodesGraph, int node);
int getNode(int *nrOfNodes, char *string, int *nodesGraph);
