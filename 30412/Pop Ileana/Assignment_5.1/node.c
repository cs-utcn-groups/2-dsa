//
// Created by ileana on 4/5/2020.
//

#include "node.h"

NodeT * createListNode(int label, int content)
{
    NodeT * newNode = (NodeT * )malloc(sizeof(NodeT));
    newNode->label = label;
    newNode->content=content;
    newNode->next=NULL;
    return newNode;
}

NodeT *createNode(int label) {
    NodeT *newN = (NodeT *) malloc(sizeof(NodeT));
    newN->label = label;
    newN->next = NULL;
    return newN;
}