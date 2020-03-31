#ifndef ASSIGNMENT4_TREE_H
#define ASSIGNMENT4_TREE_H

#include <stdbool.h>

typedef struct _nodeT {
    int key, height;
    struct _nodeT *left, *right;
} nodeT;

nodeT *createNode(int key);

nodeT *insertNode(nodeT *currentRoot, int key);

void prettyPrint(nodeT *currentRoot, int level, FILE *outputFile);

nodeT *deleteNode(nodeT *currentRoot, int key);


nodeT *getSuccessor(nodeT *node);

#endif //ASSIGNMENT4_TREE_H