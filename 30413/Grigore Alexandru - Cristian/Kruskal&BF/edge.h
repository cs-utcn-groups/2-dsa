#include "graph.h"

typedef struct{
    int source;
    int destination;
    int weight;
}Edge;

typedef struct{
    int n;
    Edge *data;
}edgeList;

edgeList *createEdge();

edgeList *eList,*spanningTree;
