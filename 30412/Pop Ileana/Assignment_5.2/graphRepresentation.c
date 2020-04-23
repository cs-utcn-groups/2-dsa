//
// Created by ileana on 4/5/2020.
//

#include "graphRepresentation.h"
void addAdjNode(int index,int content);


void printList(NodeT * first, int index)
{
    printf("Adjacency list vertex %d: ", index);
    if(first!=NULL)
    {
        NodeT * aux= first;
        while(aux!=NULL)
        {
            printf("%d ", aux->content);
            aux=aux->next;
        }
    }
    else
        printf("NULL");
    printf("\n");
}

void addAdjNode(int index,int content)
{
    if(adjList[index]==NULL)
        adjList[index] = createNode(content);
    else
    {
        NodeT * aux = adjList[index];
        while(aux->next!=NULL)
            aux=aux->next;
        aux->next = createNode(content);
    }

}

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
                addAdjNode(i, j);

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
