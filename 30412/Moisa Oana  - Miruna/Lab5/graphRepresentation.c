//
// Created by User on 04.04.2020.
//
#include <stdlib.h>
#include "graphRepresentation.h"


void readFromAdjMatrix(FILE *f)
{
    int n;
    fscanf(f,"%d",&n);
    nrOfVertexes=n;
    int i,j;
    adjM=(int**)malloc(n* sizeof(int *));
    for(i=0;i<n;i++)
    {
        *(adjM+i)=(int*)malloc(n* sizeof(int));

    }
    for (i = 0; i < n; i++)
        for (j = 0; j < n; j++)
            fscanf(f, "%d", &adjM[i][j]);
    fclose(f);
}
void printMatrix(int **matrix)
{
    printf("The adjacency matrix is: \n");
    printf("    ");
    for(int i=0;i< nrOfVertexes;i++)
    {
        printf("%c  ", i+'A');
    }
    printf("\n");
    for(int i=0;i<nrOfVertexes;i++)
    {
        printf("%c  ",i+'A');
        for(int j=0;j<nrOfVertexes;j++)
        {
            if(adjM[i][j]>9)
                printf("%d ", matrix[i][j]);
            else
                printf("0%d ",matrix[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}
int getNumberOfNeighborsOfVertex(int v){
    if(v<nrOfVertexes)
    {
        int nrOfNeighbors=0;
        for(int i=0;i<nrOfVertexes;i++)
        {
            if(adjM[v][i]!=0 && i!=v)
                nrOfNeighbors++;
        }
        return nrOfNeighbors;
    } else{
        return 0;
    }

}

int * getAllNeighborsOfVertex(int v){
    if(v<nrOfVertexes)
    {
        int nrOfNeighbors= getNumberOfNeighborsOfVertex(v);
        int *neighbors=(int*)malloc(nrOfNeighbors* sizeof(int));
        int j=0;
        for(int i=0;i<nrOfVertexes;i++)
        {
            if(adjM[v][i]>0 && i!=v)
            {
                neighbors[j]=i;
                j++;
            }
        }
        return  neighbors;
    } else{
        return NULL;
    }
}
void matrixToList()
{

    for(int i=0;i<nrOfVertexes;i++)
    {
        for(int j=0;j<nrOfVertexes;j++)
        {
            if(adjM[i][j]>00) {

                if (adjList[i].first == NULL) {
                    adjList[i].first = (NodeL *) malloc(sizeof(NodeL));
                    adjList[i].first->key=(int*)malloc(2* sizeof(int));
                    adjList[i].first->key[1] = j;
                    adjList[i].first->key[2] = adjM[i][j];
                    adjList[i].first->next = adjList[i].last;
                    adjList[i].last = adjList[i].first;
                } else {
                    NodeL *newNode = createNodeforList(j,adjM[i][j]);
                    adjList[i].last->next = newNode;
                    adjList[i].last = newNode;
                }

            }
        }

    }
}
void initializeMatrix()
{
    newAdjM=(int**)malloc(nrOfVertexes* sizeof(int*));
    for(int i=0;i<nrOfVertexes;i++)
    {
        *(newAdjM+i)=(int*)malloc(nrOfVertexes* sizeof(int));

    }
    for(int i=0;i<nrOfVertexes;i++)
    {
        for(int j=0;j<nrOfVertexes;j++)
            newAdjM[i][j]=0;
    }
}
void listToMatrix() {
    initializeMatrix();

    for (int i = 0; i < nrOfVertexes; i++) {
        NodeL *currentNode = adjList[i].first;
        while (currentNode != NULL) {
            newAdjM[i][currentNode->key[1]] = currentNode->key[2];
            currentNode = currentNode->next;
        }

    }
}
int getNumberOfNeighborsOfVertexfromList(int v){
    if(v<nrOfVertexes)
    {
        int nrOfNeighbors=0;
       NodeL *currentNode=adjList[v].first;
       while(currentNode!=NULL)
       {
           nrOfNeighbors++;
           currentNode=currentNode->next;
       }
        return nrOfNeighbors;
    } else{
        return 0;
    }

}

int * getAllNeighborsOfVertexFromList(int v){
    if(v<nrOfVertexes)
    {
        int nrOfNeighbors= getNumberOfNeighborsOfVertexfromList(v);
        int *neighbors=(int*)malloc(nrOfNeighbors* sizeof(int));
        int j=0;
        NodeL *currentNode=adjList[v].first;
        while(currentNode!=NULL) {

            neighbors[j] = currentNode->key[1];
            j++;
            currentNode=currentNode->next;
        }

        return  neighbors;
    } else{
        return NULL;
    }
}
