#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#define MAX_LENGTH 200
#define infinity 999999999

int **initializeMatrix();
char **initializeBuffer();
void initializeCostValues(int **cost, int *n);
void constructGraph(FILE *f, int **cost, int *nrOfNodes);
int findNode(int node, int *n);
int getSource(int *n);
int findMin(int *dist, int *nrOfNodes, int *visited);
void dijkstra(int *nrOfNodes, int source, int **cost, int *dist);
void printDistances(int *nrOfNodes, int source, int *dist, FILE *g);
