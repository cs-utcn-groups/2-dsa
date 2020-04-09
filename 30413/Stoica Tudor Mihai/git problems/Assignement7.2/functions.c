#include "header.h"

void read(FILE * in)
{
    fscanf(in,"%d",&nrVertices);
    int * verticesStack=(int *) malloc(sizeof(int) * nrVertices);

    bool ** adjMatrix=(bool **) malloc(sizeof(bool *) * nrVertices);

    for(int i=0; i<nrVertices; i++)
    {
        adjMatrix[i]=(bool *) malloc(sizeof(bool) * nrVertices);

        for(int j=0; j<nrVertices; j++)
        {
            int a;
            fscanf(in,"%d",&a);
            adjMatrix[i][j]=a;
        }
    }

    int startVertex,endVertex;
    fscanf(in,"%d %d",&startVertex,&endVertex);

    solveLongestPath(verticesStack,adjMatrix,startVertex,endVertex);

    free(verticesStack);
    free(adjMatrix);
    fclose(in);
}

void solveLongestPath(int * verticesStack, int ** adjMatrix, int startVertex, int endVertex)
{
    bool * visited=(bool *) calloc(nrVertices,sizeof(bool));

    verticesStack[0]=startVertex;
    bck(verticesStack,adjMatrix,visited,endVertex);

    printf("Longest distance from %d to %d -> %d\n",startVertex,endVertex,bestPathSize);

    for(int i=0; i<=bestPathSize; i++)
    {
        printf("%d ",bestPath[i]);
    }
}

void bck(int * verticesStack,bool ** adjMatrix,bool * visited, int endVertex)
{
    int currentVertex=verticesStack[stackSize];
    visited[currentVertex]=true;

    for(int i=0; i<nrVertices; i++)
    {
        if(adjMatrix[currentVertex][i] && !visited[i])
        {
            verticesStack[++stackSize]=i;

            if(i==endVertex)
            {
                processStack(verticesStack);
                stackSize--;
            }

            else
            {
                bck(verticesStack,adjMatrix,visited,endVertex);
                visited[currentVertex]=false;
                stackSize--;
            }
        }
    }
}

void processStack(int * verticesStack)
{
    if(stackSize>bestPathSize)
    {
        for(int i=0;i<stackSize;i++)
        {
            for(int j=i+1;j<=stackSize;j++)
            {
                if(verticesStack[i]==verticesStack[j])
                {
                    return;
                }
            }
        }

        bestPathSize=stackSize;

        for(int i=0; i<=bestPathSize; i++)
        {
            bestPath[i]=verticesStack[i];
        }
    }
}
