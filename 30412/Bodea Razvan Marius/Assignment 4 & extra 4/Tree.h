//
// Created by razvi on 3/30/2020.
//

#ifndef CODE_HERE_TREE_H
#define CODE_HERE_TREE_H

#define SPACE 5

typedef struct node {
    struct node *left, *right;
    int key;
    int height;
} NodeT;

NodeT *createNode(int key);
int getMax(int a, int b);
int getHeight(NodeT *curr);
int getBalance(NodeT *curr);
NodeT *rotateRight(NodeT *currentRoot);
NodeT *rotateLeft(NodeT *currentRoot);
NodeT *balanceTree(NodeT *node, int key);
NodeT *insertNode(NodeT *currentRoot, int key);
void prettyPrint(NodeT *currentRoot, int level);

NodeT *getSuccessor(NodeT *node);
NodeT *deleteNode(NodeT *currentRoot, int key);

#endif //CODE_HERE_TREE_H