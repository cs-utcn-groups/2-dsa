//
// Created by Alina Mihut on 4/6/20.
//
#include "matrix.h"

void initializeMatrix()
{
    newMatrix= (int**) malloc (sizeof(int*));
    for(int i=0;i<MAX_N;i++) {
        newMatrix[i] = (int *) malloc(MAX_N * (sizeof(int)));
        for (int j = 0; j < MAX_N; j++)
            newMatrix[i][j] = 0;
    }
}

void printMatrix()
{
    for(int i=0;i<nrOfVertexes;i++)
        for(int j=0;j<nrOfVertexes;i++)
            printf("%d " , newMatrix[i][j]);
         printf("\n");
    printf("\n");

}
void createMatrixFromList (List *l)
{
    initializeMatrix();
    int j;
    for (int i=0;i<nrOfVertexes;i++)
    {
        NodeT *temp = l[i].first;
        j=0;
        while(temp)
        {
            newMatrix[i][j]=temp->vertex;
            temp=temp->next;
            j++;
        }

    }
}