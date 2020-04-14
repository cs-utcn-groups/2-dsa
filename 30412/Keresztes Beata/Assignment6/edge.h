//
// Created by q on 4/9/2020.
//

#ifndef ASSIGNMENT5_EDGE_H
#define ASSIGNMENT5_EDGE_H

#include "node.h"

typedef struct edge {
    int src;
    int dest;
    int weight;
}EdgeT;

EdgeT * createEdges(int N);
void printEdges(int N, EdgeT * e);

#endif //ASSIGNMENT5_EDGE_H