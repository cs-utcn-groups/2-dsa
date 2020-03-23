//
// Created by Dominic on 3/19/2020.
//

#ifndef BST_5_2_HEADER_H
#define BST_5_2_HEADER_H

#endif //BST_5_2_HEADER_H

#include <stdlib.h>
#include <stdio.h>
#include "header.c"


BSTNodeT *createNode(char key);

BSTNodeT *insertNode(BSTNodeT *root, char key);

BSTNodeT *find(BSTNodeT *root, char key);

BSTNodeT *findMin(BSTNodeT *node);

BSTNodeT *findMax(BSTNodeT *node);

BSTNodeT *deleteNode (BSTNodeT *node, char key);