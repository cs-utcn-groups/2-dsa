//
// Created by Andreea on 23-Mar-20.
//

#ifndef ASSIGNMENT3_TREE_H
#define ASSIGNMENT3_TREE_H

#include <stdio.h>
#include "dll.h"

typedef struct _nodeT {
    char *id;
    struct _nodeT *left, *right;
} nodeT;

nodeT *createBinaryTree(FILE *inputFile);

nodeL *getListFromTree(nodeT *root);

nodeT *getTreeFromList();

void prettyPrint(nodeT *currentRoot, int level, FILE *outputFile);


#endif //ASSIGNMENT3_TREE_H
