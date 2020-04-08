#include "head.h"

int main()
{
    FILE *f=fopen("input.txt","r");
    FILE *g=fopen("output.out","w");

    int *nodesGraph=initializeArray();
    int **adjMatrix=initializeMatrix();
    int nrOfNodesGraph;
    Node *adjList[20];

    constructAdjMatrix(nodesGraph,adjMatrix,&nrOfNodesGraph,f);
    printAdjMatrix(adjMatrix,&nrOfNodesGraph,g);

    initializeAdjList(&nrOfNodesGraph,adjList);
    adjMatrixIntoAdjList(adjMatrix,&nrOfNodesGraph,adjList);
    printAdjList(adjList,&nrOfNodesGraph,g);

    adjListIntoAdjMatrix(adjList,adjMatrix,&nrOfNodesGraph);
    printAdjMatrix(adjMatrix,&nrOfNodesGraph,g);

    BFSAdjList(adjList,&nrOfNodesGraph,g,nodesGraph);
    DFSAdjList(adjList,&nrOfNodesGraph,g,nodesGraph);

    return 0;
}
