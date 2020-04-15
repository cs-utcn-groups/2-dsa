#include <stdio.h>
#include <stdlib.h>
#define VISITED 1
#define UNVISITED 0
#define INFTY 1000
typedef struct edge
{
    int source,destination,weight;
} Edge;
Edge * edges;
int ** cost;
int nrOfVertixes;
int nrOfEdges;
void readCost(FILE * f);
void printCost();
Edge getMinEdge(int * visited);
void Prim(int startNode);
Edge * getArrayOfEdges();
void ascendingOrderEdges();
Edge getMinimumEdge(int * visited);
void Kruskal(int startNode);
Edge * getArrayEdges();
void Bellmanford(int startNode);


