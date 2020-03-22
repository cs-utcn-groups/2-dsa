//
// Created by q on 3/16/2020.
//

#ifndef ASS3_EXTRA_TREE_H
#define ASS3_EXTRA_TREE_H

#endif //ASS3_EXTRA_TREE_H

#include "queue.h"

/*
 * function that creates the binary tree
 * --returns: pointer to the root
 */
NodeT * createTree(NodeT * s);
 // display operation tree
void printTree(NodeT * root, int level);
//function that prints both children of the given root
void printChildren(NodeT * root, int level);
//free memory of tree
void freeTree(NodeT ** root);