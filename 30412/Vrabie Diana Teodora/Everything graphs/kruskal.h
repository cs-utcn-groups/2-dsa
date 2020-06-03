//
// Created by diana on 10/05/2020.
//

#ifndef EVERYTHING_GRAPHS_KRUSKAL_H
#define EVERYTHING_GRAPHS_KRUSKAL_H

#include "graph-traversals.h"
#include "adj-list-graph.h"

typedef struct subset {
    int parent;
    int rank;
} Subset;

void kruskal(Graph *graph);

#endif //EVERYTHING_GRAPHS_KRUSKAL_H
