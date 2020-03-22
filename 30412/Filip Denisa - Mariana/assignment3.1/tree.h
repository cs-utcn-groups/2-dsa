//
// Created by Denisa on 3/14/2020.
//

#ifndef ASSIGNMENT3_1_TREE_H
#define ASSIGNMENT3_1_TREE_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node {
    char *id;
    struct node *right, *left;
} NodeT;

NodeT *createTreeNode();

NodeT *createBinTree();

void prettyPrint(NodeT *currentRoot, int level);
#endif //ASSIGNMENT3_1_TREE_H
