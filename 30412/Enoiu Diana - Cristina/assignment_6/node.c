//
// Created by Diana on 04/05/2020.
//

#include "node.h"

NodeT * createNode (int key){
    NodeT * newN = (NodeT *) malloc (sizeof(NodeT));
    newN->key = key;
    newN->next = NULL;
    return newN;
}