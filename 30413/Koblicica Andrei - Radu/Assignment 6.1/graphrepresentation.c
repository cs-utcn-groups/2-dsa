#include <stdlib.h>
#include "graphRepresentation.h"

void initializeMatrix()
{
    int i, j;
    adjMatrix = (int **) malloc(sizeof(int *)*nrOfVertexes);
    for (i = 0; i < nrOfVertexes; i++)
    {
        *(adjMatrix + i) = (int *) malloc(sizeof(int)*nrOfVertexes);
    }
    for(i=0; i<nrOfVertexes; i++)
        for(j=0; j<nrOfVertexes; j++)
            adjMatrix[i][j]=0;

}
void readFromAdjMatrix(FILE *f)
{
    int n;
    fscanf(f, "%d", &n);
    nrOfVertexes = n;
    int i, j;
    initializeMatrix();
    for (i = 0; i < n; i++)
        for (j = 0; j < n; j++)
            {
                fscanf(f, "%d", &adjMatrix[i][j]);
                if(adjMatrix[i][j]>0 && j>i)
                {
                    nrOfEdges++;
                }
            }
    fclose(f);
}

void printAdjMatrix()
{
    int i, j;

    printf("\nThe matrix is:\n");
    printf("    ");
    for (i = 0; i < nrOfVertexes; i++)
    {
        printf("%c   ", 'A' + i);
    }
    printf("\n");
    for (i = 0; i < nrOfVertexes; i++)
    {
        printf("%c ", 'A' + i);
        for (j = 0; j < nrOfVertexes; j++)
            printf("%3d ", adjMatrix[i][j]);
        printf("\n");
    }
    printf("\n");
}


/*int getNumberOfNeighborsOfVertex(int v)
{
    if (v < nrOfVertexes)
    {
        int nrOfNeighbors = 0;
        int i;
        for (i = 0; i < nrOfVertexes; i++)
        {
            if (adjMatrix[v][i] > 0 && i != v)
            {
                nrOfNeighbors++;
            }
        }
        return nrOfNeighbors;
    }
    else
    {
        return 0;
    }
}

int *getAllNeighborsOfVertex(int v)
{
    if (v < nrOfVertexes)
    {
        int nrOfNeighbors = getNumberOfNeighborsOfVertex(v);
        int *neighbors = (int *) malloc(sizeof(int) * nrOfNeighbors);
        int i, j = 0;
        for (i = 0; i < nrOfVertexes; i++)
        {
            if (adjMatrix[v][i] > 0 && i != v)
            {
                neighbors[j] = i;
                j++;
            }
        }
        return neighbors;
    }
    else
    {
        return NULL;
    }
}*/



