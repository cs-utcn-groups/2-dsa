#include "head.h"

int main()
{
    FILE *f=fopen("input.in","r");
    FILE *g=fopen("output.out","w");

    int **cost=initializeMatrix();
    int nrOfNodes;
    constructGraph(f,cost,&nrOfNodes);
    int source=getSource(&nrOfNodes);
    int *dist=(int *)malloc(sizeof(int)*MAX_LENGTH);
    dijkstra(&nrOfNodes,source,cost,dist);
    printDistances(&nrOfNodes,source,dist,g);

    return 0;
}
