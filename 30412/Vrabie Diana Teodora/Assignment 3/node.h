#ifndef ASSIGNMENT_3_NODE_H
#define ASSIGNMENT_3_NODE_H

#include <stdlib.h>

typedef struct _tNode {
    char value;
    struct _tNode *leftChild;
    struct _tNode *rightChild;
} TreeNode;

TreeNode *readBinaryTree();


typedef struct _lNode {
    char value;
    struct _lNode *prevNode;
    struct _lNode *nextNode;
} ListNode;

ListNode *initializeEmptyNode();

#endif