//
// Created by Alina Mihut on 4/12/20.
//
#include "node.h"

NodeT *createNode(int content) {
    NodeT *newN = (NodeT *) malloc(sizeof(NodeT));
    newN->content = content;
    newN->next = NULL;
    return newN;
}
