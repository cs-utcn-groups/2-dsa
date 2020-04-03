//
// Created by Bori on 4/2/2020.
//

#ifndef ASSIGNMENT5_GRAPHS_EDGE_H
#define ASSIGNMENT5_GRAPHS_EDGE_H

typedef struct _edge
{
    int length, endPoint;
    struct _edge* next;
} edge;

edge* createedge(int endPoint, int length);

edge *createedgeWithNext(int endPoint,  int length, edge *next);

#endif //ASSIGNMENT5_GRAPHS_EDGE_H
