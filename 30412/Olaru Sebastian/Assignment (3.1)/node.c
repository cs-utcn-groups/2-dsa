#include "node.h"

NodeT *createNewTreeNode(char data) {
    NodeT *newNode = (NodeT *) malloc(sizeof(NodeT));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

NodeL *createNewListNode(char data) {
    NodeL *newNode = (NodeL *) malloc(sizeof(NodeL));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}