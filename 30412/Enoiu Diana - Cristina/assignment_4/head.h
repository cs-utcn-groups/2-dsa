//
// Created by Diana on 4/2/2020.
//

#ifndef ASSIGNMENT_4_HEAD_H
#define ASSIGNMENT_4_HEAD_H
#define COUNT 4
typedef struct _node {
    int key;
    int height;
    struct _node * left,* right;
}NodeT;
NodeT *createNode(int key);
int height(NodeT *currentNode);
int max(int x, int y);
NodeT *rightRotate(NodeT *currentRoot);
NodeT *leftRotate(NodeT *currentRoot);
int getBalance(NodeT *currentRoot);
NodeT *getSuccessor(NodeT *node);
NodeT *getBalancedTree(NodeT *currentRoot, int key);
NodeT *insertNode(NodeT *currentRoot, int key);
NodeT *deleteNode(NodeT *currentRoot, int key);
void prettyPrint(NodeT *currentRoot, int level, FILE *out);
#endif //ASSIGNMENT_4_HEAD_H
