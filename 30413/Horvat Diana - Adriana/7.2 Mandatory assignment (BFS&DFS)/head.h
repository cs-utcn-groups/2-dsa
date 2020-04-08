#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define MAX_LENGTH 100

typedef struct node
{
    int data;
    struct node *next, *prev;
} Node;

void addElQueue(int data);
void addElStack(int data);
int deleteEl();
int takeEl();
int *initializeArray();
int **initializeMatrix();
void initializeAdjMatrix(int **matrix, int *n);
char **initializeBuffer();
void constructGraph(int *nodesGraph, int **adjMatrix, int *nrOfNodesGraph, FILE *f);
int findNode(int node,int *nodesGraph, int *nrOfNodesGraph);
void BFS(int **adjMatrix, int *nrOfNodesGraph, FILE *g, int *nodesGraph);
void DFS(int **adjMatrix, int *nrOfNodesGraph, FILE *g, int *nodesGraph);
