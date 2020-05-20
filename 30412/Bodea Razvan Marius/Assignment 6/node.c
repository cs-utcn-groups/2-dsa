//
// Created by razvi on 4/7/2020.
//

#include "node.h"

NodeT *createNode(int content) {
    NodeT *newN = (NodeT *) malloc(sizeof(NodeT));
    newN->content = content;
    newN->next = NULL;
    newN->prev=NULL;
    return newN;
}