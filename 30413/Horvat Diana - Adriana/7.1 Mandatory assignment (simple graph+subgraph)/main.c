#include "head.h"

int main()
{
    FILE *f=fopen("input.in","r");
    FILE *g=fopen("output.out","w");

    int *nodesGraph=initializeArray();
    int *nodesSubGraph=initializeArray();
    int **adjMatrix=initializeMatrix();
    int nrOfNodesGraph, nrOfNodesSubGraph;
    constructGraph(nodesGraph,nodesSubGraph,adjMatrix,&nrOfNodesGraph,&nrOfNodesSubGraph,f);
    constructSubGraph(nodesSubGraph,adjMatrix,&nrOfNodesSubGraph,g);

    return 0;
}
