//
// Created by Alina Mihut on 4/5/20.
//
#include "node.h"
NodeT *createNode (int v)
{
    NodeT *newNode=(NodeT*)malloc (sizeof(NodeT));
    newNode->vertex=v;
    newNode->next=NULL;
    return newNode;

}