//
// Created by diana on 07/05/2020.
//

#ifndef ASSIGNMENT_3_EXTRA_TREE_H
#define ASSIGNMENT_3_EXTRA_TREE_H

#include "node.h"
#include "queue.h"

typedef struct _tree {
    TreeNode *root;
} Tree;

Tree initializeTree();

TreeNode* buildTreeFromQueue(TreeNode *currentNode, Queue *queue);

void printTree(TreeNode* node, int level);

#endif //ASSIGNMENT_3_EXTRA_TREE_H
