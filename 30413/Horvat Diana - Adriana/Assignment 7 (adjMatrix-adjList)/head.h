#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#define MAX_LENGTH 100

typedef struct node
{
    int data;
    struct node *next;
} Node;

int *initializeArray();
int **initializeMatrix();
void initializeAdjMatrix(int **matrix, int *n);
char **initializeBuffer();
void constructAdjMatrix(int *nodesGraph, int **adjMatrix, int *nrOfNodesGraph, FILE *f);
void printAdjMatrix(int **adjMatrix, int *nrOfNodesGraph, FILE *g);
Node *createNode(int data);
void initializeAdjList(int *nrOfNodesGraph, Node *adjList[]);
void adjMatrixIntoAdjList(int **adjMatrix, int *nrOfNodesGraph, int *adjList[]);
void printAdjList(Node *adjList[], int *nrOfNodesGraph, FILE *g);
void adjListIntoAdjMatrix(Node *adjList[], int **adjMatrix, int *nrOfNodesGraph);
int findNode(int *nrOfNodesGraph, int *nodesGraph, int node);
int readTheSourceNode(int *nrOfNodesGraph, int *nodesGraph, char *algorithm);
int deleteEl();
int takeEl();
void addQueue(int data);
void addStack(int data);
void BFSAdjList(Node *adjList[], int *nrOfNodesGraph, FILE *g, int *nodesGraph);
void DFSAdjList(Node *adjList[], int *nrOfNodesGraph, FILE *g, int *nodesGraph);
