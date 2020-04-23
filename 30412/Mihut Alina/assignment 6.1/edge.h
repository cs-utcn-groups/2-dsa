//
// Created by Alina Mihut on 4/12/20.
//

#ifndef ASSIGNMENT_6_1_EDGE_H
#include "graph.h"
typedef struct edge {
    int source;
    int destination;
    int weight;
} edgeT;


typedef struct edgelist
{
    int n;
    edgeT *data;

}edgeL;
edgeL *createEdge ();

edgeL *eList, *spanningTree;
#define ASSIGNMENT_6_1_EDGE_H

#endif //ASSIGNMENT_6_1_EDGE_H
