#include <stdio.h>
#include <stdlib.h>
#include "tree.h"

nodeT *createNode(int key) {
    nodeT *node = (nodeT *) malloc(sizeof(nodeT));
    node->left = NULL;
    node->right = NULL;
    node->key = key;
    node->height = 1;
    return node;
}

int height(nodeT *currentNode) {
    if (currentNode == NULL)
        return 0;
    return currentNode->height;
}

int max(int x, int y) {
    return (x > y) ? x : y;
}

nodeT *rightRotate(nodeT *currentRoot) {
    nodeT *leftRoot = currentRoot->left;
    currentRoot->left = leftRoot->right;
    leftRoot->right = currentRoot;
    currentRoot->height = max(height(currentRoot->left), height(currentRoot->right)) + 1;
    leftRoot->height = max(height(leftRoot->left), height(leftRoot->right)) + 1;
    return leftRoot;
}

nodeT *leftRotate(nodeT *currentRoot) {
    nodeT *rightRoot = currentRoot->right;
    currentRoot->right = rightRoot->left;
    rightRoot->left = currentRoot;
    currentRoot->height = max(height(currentRoot->left), height(currentRoot->right)) + 1;
    rightRoot->height = max(height(rightRoot->left), height(rightRoot->right)) + 1;
    return rightRoot;
}

int getBalance(nodeT *currentRoot) {
    if (currentRoot == NULL)
        return 0;
    return height(currentRoot->left) - height(currentRoot->right);
}

nodeT *getSuccessor(nodeT *node) {
    nodeT *current = node->right;
    while (current != NULL && current->left != NULL) {
        current = current->left;
    }
    return current;
}

nodeT *getBalancedTree(nodeT *currentRoot, int key) {
    currentRoot->height = 1 + max(height(currentRoot->left), height(currentRoot->right));
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


nodeT *insertNode(nodeT *currentRoot, int key) {
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

nodeT *deleteNode(nodeT *currentRoot, int key) {
    if (currentRoot == NULL)
        return currentRoot;
    if (key < currentRoot->key)
        currentRoot->left = deleteNode(currentRoot->left, key);
    else if (key > currentRoot->key)
        currentRoot->right = deleteNode(currentRoot->right, key);
    else {
        if ((currentRoot->left == NULL) || (currentRoot->right == NULL)) {
            nodeT *temp = currentRoot->left ? currentRoot->left : currentRoot->right;
            if (temp == NULL) {
                temp = currentRoot;
                currentRoot = NULL;
            } else
                *currentRoot = *temp;
            free(temp);
        } else {
            nodeT *temp = getSuccessor(currentRoot->right);
            currentRoot->key = temp->key;
            currentRoot->right = deleteNode(currentRoot->right, temp->key);
        }
    }
    if (currentRoot == NULL)
        return currentRoot;
    currentRoot = getBalancedTree(currentRoot, key);
    return currentRoot;
}


void prettyPrint(nodeT *currentRoot, int level, FILE *outputFile) {
    if (currentRoot != NULL) {
        prettyPrint(currentRoot->right, level + 1, outputFile);
        for (int i = 0; i < 6 * level; i++) {
            fprintf(outputFile, " ");
        }
        fprintf(outputFile, "%d\n", currentRoot->key);
        prettyPrint(currentRoot->left, level + 1, outputFile);
    }
}