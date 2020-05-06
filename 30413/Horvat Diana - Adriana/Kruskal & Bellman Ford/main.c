#include "head.h"

int main()
{
    FILE *f=fopen("input.in","r");
    FILE *g=fopen("output.out","w");

    Edge *edges[N];
    int nrOfNodes,nrOfEdges;
    constructGraph(f,&nrOfNodes,edges,&nrOfEdges);
    Kruskal(&nrOfEdges,edges,&nrOfNodes,g);

    constructGraph(f,&nrOfNodes,edges,&nrOfEdges);
    BellmanFord(&nrOfNodes,&nrOfEdges,edges,g);

    return 0;
}
