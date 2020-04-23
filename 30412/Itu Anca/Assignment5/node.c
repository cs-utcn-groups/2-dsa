//
// Created by Anca on 4/6/2020.
//
#include "node.h"

NodeT *createNode(int content){
    NodeT *newNode = (NodeT*) malloc (sizeof(NodeT));
    newNode->content = content;
    newNode->next = NULL;
    return newNode;
}

NodeL *createNodeL(int content, int weight){
    NodeL *newNode = (NodeL*) malloc (sizeof(NodeL));
    newNode->content = content;
    newNode->weight = weight;
    newNode->next = NULL;
    return newNode;
}