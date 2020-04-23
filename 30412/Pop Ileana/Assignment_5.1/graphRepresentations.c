//
// Created by ileana on 4/5/2020.
//

#include "graphRepresentations.h"
void initializeAdjMatrix();

void createAdjacencyList(FILE * f)
{
    int n;
    fscanf(f, "%d", &n);
    nbOfNodes = n;
    int i, j;
    adjList = (NodeT**)malloc(nbOfNodes* sizeof(NodeT));
    for(i = 0; i < n; i++) {
        adjList[i] = (NodeT*) malloc(sizeof(NodeT));
        adjList[i]=NULL;
    }
    for(i = 0; i < n; i++)
        for(j = 0; j < n; j++)
        {
            int content;
            fscanf(f,"%d",&content);
            if(content>0 && i!=j)
                addAdjNode(i, j, content);

        }

}


void printAdjacencyList()
{
    if(nbOfNodes!=0)
    {
        for(int i = 0; i < nbOfNodes; i++)
            printList(adjList[i],i);
    }
}





void createAdjMatrix()
{
    adjMatrix = (int **)malloc(nbOfNodes* sizeof(int*));

    for(int i=0;i<nbOfNodes;i++)
        *(adjMatrix + i) = (int *) malloc(nbOfNodes * sizeof(int));

    initializeAdjMatrix();

    for(int i=0; i < nbOfNodes ; i++)
    {
        NodeT * aux = adjList[i];
        while(aux!=NULL)
        {
            adjMatrix[i][aux->label]=aux->content;
            aux=aux->next;
        }
    }

}

void initializeAdjMatrix()
{
    for(int i = 0; i < nbOfNodes ; i++)
        for( int j = 0; j < nbOfNodes ; j++)
            adjMatrix[i][j]=0;
}

void printAdjMatrix() {
    int i, j;

    printf("\nThe matrix is:\n");
    printf("    ");
    for (i = 0; i < nbOfNodes; i++) {
        printf("%c   ", 'A' + i);
    }
    printf("\n");
    for (i = 0; i < nbOfNodes; i++) {
        printf("%c ", 'A' + i);
        for (j = 0; j < nbOfNodes; j++)
            printf("%3d ", adjMatrix[i][j]);
        printf("\n");
    }
    printf("\n");
}