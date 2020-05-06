#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#define MAX_LENGTH 200
#define N 50
#define infinity 999999999

typedef struct edge
{
    int weight,source,dest;
} Edge;

typedef struct node
{
    int data;
    struct node *next;
} Node;

char **initializeBuffer();
Edge *createNode(int source, int dest, int weight);
void constructGraph(FILE *f, int *nrOfNodes, Edge *edges[], int *nrOfEdges);
void sortAccToWeight(int *nrOfEdges, Edge *edges[]);
int **initializeMatrix();
void initializeAdjMatrix(int **matrix, int *n);
int deleteEl();
int takeEl();
void addStack(int data);
void initializeStack();
int isCycle(int source, int dest, int *visited,int *nrOfNodes,int **adjMatrix);
void Kruskal(int *nrOfEdges, Edge *edges[],int *nrOfNodes,FILE *g);
int readSource(int *nrOfNodes);
void BellmanFord(int *nrOfNodes, int *nrOfEdges, Edge *edges[], FILE *g);
