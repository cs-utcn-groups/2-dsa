//
// Created by Anca on 4/6/2020.
//

#ifndef ASSIGNMENT5_NODE_H

#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    int content;
    struct node *next;
}NodeT;

NodeT *createNode(int content);

typedef struct nodeList{
    int content;
    int weight;
    struct nodeList *next;
}NodeL;

NodeL *createNodeL(int content, int weight);

#define ASSIGNMENT5_NODE_H

#endif //ASSIGNMENT5_NODE_H
