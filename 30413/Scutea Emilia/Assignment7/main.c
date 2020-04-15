#include "header.h"

int main()
{
    FILE * f=fopen("input.dat","r");
    FILE * g=fopen("bellmanford.dat","r");
    readCost(f);
    edges=getArrayOfEdges();
    printCost();
    Prim(0);
    ascendingOrderEdges();
    Kruskal(0);
    readCost(g);
    printCost();
    edges=getArrayEdges();
    Bellmanford(0);
}
