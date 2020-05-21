//
// Created by Irina on 08/05/2020.
//

#include "node.h"

NodeT *createNode(int content) {
    NodeT *newN = (NodeT *) malloc(sizeof(NodeT));
    newN->content = content;
    newN->next = NULL;
    return newN;
}
