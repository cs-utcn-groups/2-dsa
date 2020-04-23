//
// Created by Alex on 4/7/2020.
//

#ifndef GRAPHS___TRAVERSALS_GRAPHALGORITHMS_H
#include "graph.h"

typedef struct subset
{
    int parent;
}subsetT;

void prim(int startNode);
void dijkstra(int startNode);
void kruskalMST();
void bellmanFord(int startVertex);

#define GRAPHS___TRAVERSALS_GRAPHALGORITHMS_H

#endif //GRAPHS___TRAVERSALS_GRAPHALGORITHMS_H