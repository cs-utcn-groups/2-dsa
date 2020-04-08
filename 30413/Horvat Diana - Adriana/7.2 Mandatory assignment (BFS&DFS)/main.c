#include "head.h"

int main()
{
    FILE *f=fopen("input.in","r");
    FILE *g=fopen("output.out","w");

    int *nodesGraph=initializeArray();
    int **adjMatrix=initializeMatrix();
    int nrOfNodesGraph,nodeBFS;
    constructGraph(nodesGraph,adjMatrix,&nrOfNodesGraph,f);
    BFS(adjMatrix,&nrOfNodesGraph,g,nodesGraph);
    DFS(adjMatrix,&nrOfNodesGraph,g,nodesGraph);

    return 0;
}
