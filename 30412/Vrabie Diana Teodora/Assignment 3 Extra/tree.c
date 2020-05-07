//
// Created by diana on 07/05/2020.
//

#include "tree.h"
#include <ctype.h>
#include <string.h>
#include <stdbool.h>

bool isLeaf(TreeNode *node);

Tree initializeTree() {
    Tree newTree;
    newTree.root = NULL;
    return newTree;
}

TreeNode* buildTreeFromQueue(TreeNode *currentNode, Queue *queue) {
    if (isEmpty(*queue)) {
        // queue is empty, nothing left to do
        return NULL;
    }
    // dequeue an element and build a node from its value, add new node to tree
    currentNode = createNewTreeNode(dequeue(queue)->value);

    if (isLeaf(currentNode)) {
        // current node is a leaf, can't go to its children
        return currentNode;
    }

    // current node is not leaf, we can proceed to its children (taken left to right)
    currentNode->left = buildTreeFromQueue(currentNode->left, queue);
    currentNode->right = buildTreeFromQueue(currentNode->right, queue);
    return currentNode;
}

bool isLeaf(TreeNode *node) {
    // only numerical values are leaves in an expression tree; check if last character of the value is digit
    char c = node->value[strlen(node->value) - 1];
    if (isdigit(c)) return true;
    return false;
}
