//
// Created by Irina on 23/03/2020.
//

#ifndef ASSIGNMENT3_1_HEAD_H
#define ASSIGNMENT3_1_HEAD_H

#include <string.h>
#include <stdlib.h>
#include <stdio.h>

typedef struct NodeT{
    char id;
    struct NodeT *left, *right;
}NodeT;

typedef struct NodeL{
    char id;
    struct NodeL * next, *previous;
}NodeL;
NodeL * first, *last;

NodeT *createBinaryTree();

void initializeList();

NodeL *getListFromTree(NodeT *root);

void traverseList();

NodeT *getTreeFromList();

void prettyPrint(NodeT *currentRoot, int level);

#endif //ASSIGNMENT3_1_HEAD_H
