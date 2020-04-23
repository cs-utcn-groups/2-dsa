//
// Created by Diana on 4/2/2020.
//

#include <stdio.h>
#include <stdlib.h>
#include "head.h"
NodeT *createNode(int key) {
    NodeT *node = (NodeT *) malloc(sizeof(NodeT));
    node->left = NULL;
    node->right = NULL;
    node->key = key;
    node->height = 1;
    return node;
}

int height(NodeT *currentNode) {
    if (currentNode == NULL)
        return 0;
    return currentNode->height;
}

int max(int x, int y) {
    return (x > y) ? x : y;
}

NodeT *rightRotate(NodeT *currentRoot) {
    NodeT *leftRoot = currentRoot->left;
    currentRoot->left = leftRoot->right;
    leftRoot->right = currentRoot;
    currentRoot->height = max(height(currentRoot->left), height(currentRoot->right)) + 1;
    leftRoot->height = max(height(leftRoot->left), height(leftRoot->right)) + 1;
    return leftRoot;
}

NodeT *leftRotate(NodeT *currentRoot) {
    NodeT *rightRoot = currentRoot->right;
    currentRoot->right = rightRoot->left;
    rightRoot->left = currentRoot;
    currentRoot->height = max(height(currentRoot->left), height(currentRoot->right)) + 1;
    rightRoot->height = max(height(rightRoot->left), height(rightRoot->right)) + 1;
    return rightRoot;
}

int getBalance(NodeT *currentRoot) {
    if (currentRoot == NULL)
        return 0;
    return height(currentRoot->left) - height(currentRoot->right);
}

NodeT *getSuccessor(NodeT *node) {
    NodeT *current = node->right;
    while (current != NULL && current->left != NULL) {
        current = current->left;
    }
    return current;
}

NodeT *getBalancedTree(NodeT *currentRoot, int key) {
    currentRoot->height = 1 + max(height(currentRoot->left),
                                  height(currentRoot->right));
    int balance = getBalance(currentRoot);
    if (balance > 1 && key < currentRoot->left->key)
        return rightRotate(currentRoot);
    if (balance < -1 && key > currentRoot->right->key)
        return leftRotate(currentRoot);
    if (balance > 1 && key > currentRoot->left->key) {
        currentRoot->left = leftRotate(currentRoot->left);
        return rightRotate(currentRoot);
    }
    if (balance < -1 && key < currentRoot->right->key) {
        currentRoot->right = rightRotate(currentRoot->right);
        return leftRotate(currentRoot);
    }
    return currentRoot;
}


NodeT *insertNode(NodeT *currentRoot, int key) {
    if (currentRoot == NULL)
        return (createNode(key));
    if (key < currentRoot->key)
        currentRoot->left = insertNode(currentRoot->left, key);
    else if (key > currentRoot->key)
        currentRoot->right = insertNode(currentRoot->right, key);
    else
        return currentRoot;
    getBalancedTree(currentRoot, key);

}

NodeT *deleteNode(NodeT *currentRoot, int key) {
    if (currentRoot == NULL)
        return currentRoot;
    if (key < currentRoot->key)
        currentRoot->left = deleteNode(currentRoot->left, key);
    else if (key > currentRoot->key)
        currentRoot->right = deleteNode(currentRoot->right, key);
    else {
        if ((currentRoot->left == NULL) || (currentRoot->right == NULL)) {
            NodeT *temp = currentRoot->left ? currentRoot->left : currentRoot->right;
            if (temp == NULL) {
                temp = currentRoot;
                currentRoot = NULL;
            } else
                *currentRoot = *temp;
            free(temp);
        } else {
            NodeT *temp = getSuccessor(currentRoot->right);
            currentRoot->key = temp->key;
            currentRoot->right = deleteNode(currentRoot->right, temp->key);
        }
    }
    if (currentRoot == NULL)
        return currentRoot;
    currentRoot = getBalancedTree(currentRoot, key);
    return currentRoot;
}


void prettyPrint(NodeT *currentRoot, int level, FILE *out) {
    if (currentRoot == NULL) {
        return;
    }
    level += COUNT;
    prettyPrint(currentRoot->right, level,out);
    fprintf(out,"\n");
    for (int i = COUNT; i < level; i++)
        fprintf(out," ");
    fprintf(out,"%d", currentRoot->key);
    prettyPrint(currentRoot->left, level,out);
}