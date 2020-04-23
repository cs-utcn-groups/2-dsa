//
// Created by User on 11.04.2020.
//

#include "graphRepresentation.h"
void readFromAdjMatrix(FILE *f)
{
    fscanf(f,"%d",&nrOfVertexes);
    adjMatrix=(int**)malloc(nrOfVertexes* sizeof(int*));
    for(int i=0;i<nrOfVertexes;i++)
    {
        *(adjMatrix+i)=(int*)malloc(nrOfVertexes* sizeof(int));
    }
    for(int i=0;i<nrOfVertexes;i++)
    {
        for(int j=0;j<nrOfVertexes;j++)
        {
            fscanf(f,"%d",&adjMatrix[i][j]);
        }
    }
    fclose(f);
}

void printAdjMatrix()
{
    printf("The adj matrix is:\n");
    printf("    ");
    for(int i=0;i<nrOfVertexes;i++)
    {
        printf("%c  ",i+'A');
    }
    printf("\n");
    for(int i=0;i<nrOfVertexes;i++)
    {
        printf("%c: ",i+'A');
        for(int j=0;j<nrOfVertexes;j++)
        {
            if(adjMatrix[i][j]>9)
                 printf("%d ",adjMatrix[i][j]);
            else if(adjMatrix[i][j]<0)
                printf("%d ",adjMatrix[i][j]);
            else
                printf("0%d ",adjMatrix[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}
