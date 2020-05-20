#include "header.h"

vertexNeibStructure ** readMatrix(FILE * in,vertexNeibStructure ** vertexFirst)
{
    fscanf(in,"%d",&totalNrVertexesMatrixInput);

    int * matrixRow=(int *) malloc(sizeof(int) * totalNrVertexesMatrixInput);
    vertexFirst=(vertexNeibStructure **) malloc(sizeof(vertexNeibStructure *) * totalNrVertexesMatrixInput);

    for(int i=0; i<totalNrVertexesMatrixInput; i++)
    {
        for(int j=0; j<totalNrVertexesMatrixInput; j++)
        {
            fscanf(in,"%d",&matrixRow[j]);
        }

        vertexFirst[i]=convertToList(matrixRow,vertexFirst[i]);
    }

    free(matrixRow);
    fclose(in);

    return vertexFirst;
}

vertexNeibStructure * convertToList(int * matrixRow, vertexNeibStructure * vertexFirst)
{
    vertexFirst=NULL;
    vertexNeibStructure * vertexLast=NULL;

    for(int i=0; i<totalNrVertexesMatrixInput; i++)
    {
        if(matrixRow[i]==1)
        {
            if(vertexFirst==NULL)
            {
                vertexFirst=(vertexNeibStructure *) malloc(sizeof(vertexNeibStructure));

                vertexFirst->vertexIndex=i;
                vertexFirst->nextVertex=vertexLast;
                vertexLast=vertexFirst;
                vertexLast->nextVertex=NULL;
            }

            else
            {
                vertexNeibStructure * newElement=(vertexNeibStructure *) malloc(sizeof(vertexNeibStructure));
                newElement->nextVertex = NULL;
                newElement->vertexIndex=i;
                vertexLast->nextVertex=newElement;
                vertexLast=newElement;
            }
        }
    }

    return vertexFirst;
}

int ** readList(FILE * in,int ** adjMatrix)
{
    fscanf(in,"%d",&totalNrVertexesListInput);
    adjMatrix=(int **) malloc(sizeof(int *) * totalNrVertexesListInput);

    for(int i=0; i<totalNrVertexesListInput; i++)
    {
        adjMatrix[i]=(int *) calloc(totalNrVertexesListInput,sizeof(int));
    }

    int a,b;
    while(fscanf(in,"%d %d",&a,&b)==2)
    {
        adjMatrix[a][b]=adjMatrix[b][a]=1;
    }

    fclose(in);

    return adjMatrix;
}
