//
// Created by Bori on 3/19/2020.
//

#ifndef ASSIGNMENT3_BINTREE_BINTREE_H
#define ASSIGNMENT3_BINTREE_BINTREE_H

#include <stdio.h>
#include "queue.h"

#define NULL_NODE "*"
#define MAX_DATA_LENGTH 100

typedef struct _binTree {
    char *rootData;
    struct _binTree *left, *right;
} binTree;


binTree* createBinTree(Queue* expQueue);

void inOrder(binTree *myTree, int level, FILE *outFile);


#endif //ASSIGNMENT3_BINTREE_BINTREE_H
