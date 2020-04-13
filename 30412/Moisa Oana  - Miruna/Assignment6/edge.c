//
// Created by User on 11.04.2020.
//
#include "edge.h"
#include "graph.h"
EdgeT * createEdge(int source, int destination, int weight)
{
    EdgeT *newEdge=(EdgeT*)malloc(sizeof(EdgeT));
    newEdge->weight=weight;
    newEdge->source=source;
    newEdge->destination=destination;
    newEdge->next=NULL;
    return newEdge;
}
