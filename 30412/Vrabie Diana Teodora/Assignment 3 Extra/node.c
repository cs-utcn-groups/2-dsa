//
// Created by diana on 07/05/2020.
//

#include "node.h"

QueueNode *createNewQueueNode(char *value) {
    QueueNode *node = (QueueNode*) malloc(sizeof(QueueNode));
    node->value = value;
    node->next = NULL;
    return node;
}

TreeNode *createNewTreeNode(char *value) {
    TreeNode *node = (TreeNode*) malloc(sizeof(TreeNode));
    node->value = value;
    node->left = node->right = NULL;
    return node;
}
