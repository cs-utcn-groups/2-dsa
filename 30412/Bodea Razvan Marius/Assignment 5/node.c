//
// Created by razvi on 4/5/2020.
//
#include "node.h"

NodeT *createNode(int content) {
    NodeT *newN = (NodeT *) malloc(sizeof(NodeT));
    newN->data = content;
    newN->next = NULL;
    return newN;
}