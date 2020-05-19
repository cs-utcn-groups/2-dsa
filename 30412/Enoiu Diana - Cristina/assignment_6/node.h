//
// Created by Diana on 04/05/2020.
//

#ifndef GRAPH_ALGORITHMS_NODE_H
#include "stdlib.h"
typedef struct _node {
    int key;
    struct _node * next;
}NodeT;
NodeT * createNode (int key);
#define GRAPH_ALGORITHMS_NODE_H

#endif //GRAPH_ALGORITHMS_NODE_H
