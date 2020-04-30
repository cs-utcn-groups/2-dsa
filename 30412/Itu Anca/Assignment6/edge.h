//
// Created by Anca on 4/27/2020.
//

#ifndef ASSIGNMENT6_EDGE_H


typedef struct edge {
    int source;
    int destination;
    int weight;
} edgeT;

int getNumberOfEdges();
void createEdgesArr(edgeT *edges);

#define ASSIGNMENT6_EDGE_H

#endif //ASSIGNMENT6_EDGE_H
