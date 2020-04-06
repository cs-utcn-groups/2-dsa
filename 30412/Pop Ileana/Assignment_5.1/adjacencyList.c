//
// Created by ileana on 4/5/2020.
//
#include "adjacencyList.h"


void printList(NodeT * first, int index)
{
    printf("Adjacency list vertex %d: ", index);
    if(first!=NULL)
    {
        NodeT * aux= first;
        while(aux!=NULL)
        {
            printf("%d ", aux->label);
            aux=aux->next;
        }
    }
    else
        printf("NULL");
    printf("\n");
}

void addAdjNode(int index, int label, int content)
{
    if(adjList[index]==NULL)
        adjList[index] = createListNode(label,content);
    else
    {
        NodeT * aux = adjList[index];
        while(aux->next!=NULL)
            aux=aux->next;
        aux->next = createListNode(label,content);
    }

}

