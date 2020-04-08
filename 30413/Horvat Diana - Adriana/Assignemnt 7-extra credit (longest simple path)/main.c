#include "head.h"

int main()
{
    FILE *f=fopen("input.in","r");
    FILE *g=fopen("output.out","w");

    int **cost=initializeMatrix();
    int nrOfNodes;
    int *nodesGraph=initializeArray();
    constructGraph(f,cost,&nrOfNodes,nodesGraph);

    printf("Enter the first and last node of the path: ");
    char *string=(char *)malloc(sizeof(char)*10);
    strcpy(string,"first");
    int a=getNode(&nrOfNodes,string,nodesGraph);
    strcpy(string,"last");
    int b=getNode(&nrOfNodes,string,nodesGraph);

    longestPath(a,b,&nrOfNodes,cost,g);

    return 0;
}
