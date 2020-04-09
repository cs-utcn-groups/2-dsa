#include "header.h"

int main()
{
    FILE * inFileMatrix=fopen("inMatrix2.txt","r");
    FILE * inFileList=fopen("inList.txt","r");

    vertexNeibStructure ** vertexFirst=NULL;
    vertexFirst=readMatrix(inFileMatrix,vertexFirst);

    printf("Convert adjacency matrix from inMatrix.txt into vertices list:\n");

    for(int i=0; i<totalNrVertexesMatrixInput; i++)
    {
        vertexNeibStructure * element=vertexFirst[i];
        printf("%d: ",i);
        while(element!=NULL)
        {
            printf("%d ",element->vertexIndex);
            element=element->nextVertex;
        }
        printf("\n");
        free(element);
    }

    printf("\n");
    free(vertexFirst);

    int ** adjMatrix=NULL;
    adjMatrix=readList(inFileList,adjMatrix);

    printf("Convert vertices list from inList.txt into  adjacency matrix:\n");

    for(int i=0;i<totalNrVertexesListInput;i++)
    {
        for(int j=0;j<totalNrVertexesListInput;j++)
        {
            printf("%d ",adjMatrix[i][j]);
        }
        printf("\n");
    }
    free(adjMatrix);

    return 0;
}
