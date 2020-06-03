//
// Created by diana on 07/05/2020.
//

#ifndef ASSIGNMENT_3_EXTRA_NODE_H
#define ASSIGNMENT_3_EXTRA_NODE_H

#include <stdlib.h>
#include <stdio.h>

typedef struct _queueNode {
    char *value;
    struct _queueNode *next;
} QueueNode;

typedef struct _treeNode {
    char *value;
    struct _treeNode *left, *right;
} TreeNode;

QueueNode *createNewQueueNode(char *value);

TreeNode *createNewTreeNode(char *value);

#endif //ASSIGNMENT_3_EXTRA_NODE_H
