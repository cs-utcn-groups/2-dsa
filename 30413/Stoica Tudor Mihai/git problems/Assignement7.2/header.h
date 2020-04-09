#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int nrVertices,bestPathSize;
int stackSize;
int bestPath[105];

void read(FILE * in);
void bck(int * verticesStack,bool ** adjMatrix,bool * visited, int endVertex);
void processStack(int * verticesStack);
