#include <stdio.h>
#include <stdlib.h>

typedef struct vertexNeibStructure
{
    int vertexIndex;
    struct vertexStructure * nextVertex;

} vertexNeibStructure;

int totalNrVertexesMatrixInput,totalNrVertexesListInput;

vertexNeibStructure ** readMatrix(FILE * in,vertexNeibStructure ** vertexFirst);
vertexNeibStructure * convertToList(int * matrixRow, vertexNeibStructure * vertexFirst);
int ** readList(FILE * in,int ** adjMatrix);
