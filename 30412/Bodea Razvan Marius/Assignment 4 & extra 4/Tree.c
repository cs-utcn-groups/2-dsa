//
// Created by razvi on 3/30/2020.
//
#include "Tree.h"
#include <stdlib.h>
#include <stdio.h>

NodeT *createNode(int key) {
    NodeT *newNode = (NodeT *) malloc(sizeof(NodeT));
    newNode->key = key;
    newNode->left = NULL;
    newNode->right = NULL;
    newNode->height = 1;
    return newNode;
}

int getMax(int a, int b) {
    if (a > b)
        return a;
    else
        return b;
}

int getHeight(NodeT *curr) {
    if (curr == NULL)
        return 0;
    return curr->height;
}

int getBalance(NodeT *curr) {
    if (curr == NULL)
        return 0;
    return getHeight(curr->left) - getHeight(curr->right);
}

NodeT *rotateRight(NodeT *currentRoot) {
    NodeT *leftRoot = currentRoot->left;
    NodeT *T2 = leftRoot->right;

    leftRoot->right = currentRoot;
    currentRoot->left = T2;

    currentRoot->height = getMax(getHeight(currentRoot->left), getHeight(currentRoot->right)) + 1;
    leftRoot->height = getMax(getHeight(leftRoot->left), getHeight(leftRoot->right)) + 1;

    return leftRoot;
}

NodeT *rotateLeft(NodeT *currentRoot) {
    NodeT *rightRoot = currentRoot->right;
    NodeT *T2 = rightRoot->left;

    rightRoot->left = currentRoot;
    currentRoot->right = T2;

    currentRoot->height = getMax(getHeight(currentRoot->left), getHeight(currentRoot->right)) + 1;
    rightRoot->height = getMax(getHeight(rightRoot->left), getHeight(rightRoot->right)) + 1;

    return rightRoot;
}

NodeT *balanceTree(NodeT *node, int key) {
    if (node == NULL)
        return (createNode(key));

    if (key < node->key)
        node->left = balanceTree(node->left, key);
    else if (key > node->key)
        node->right = balanceTree(node->right, key);
    else
        return node;

    node->height = 1 + getMax(getHeight(node->left), getHeight(node->right));

    int balance = getBalance(node);

    // Left Left Case
    if (balance > 1 && key < node->left->key)
        return rotateRight(node);
    // Right Right Case
    if (balance < -1 && key > node->right->key)
        return rotateLeft(node);
    // Left Right Case
    if (balance > 1 && key > node->left->key) {
        node->left = rotateLeft(node->left);
        return rotateRight(node);
    }
    // Right Left Case
    if (balance < -1 && key < node->right->key) {
        node->right = rotateRight(node->right);
        return rotateLeft(node);
    }

    return node;
}

NodeT *insertNode(NodeT *currentRoot, int key) {
    NodeT *node = createNode(key);
    if (currentRoot == NULL) {
        return node;
    }
    if (key < currentRoot->key) {
        currentRoot->left = insertNode(currentRoot->left, key);
    } else if (key > currentRoot->key) {
        currentRoot->right = insertNode(currentRoot->right, key);
    } else {
        printf("Key %d already in tree!", key);
        free(node);
    }
    currentRoot = balanceTree(currentRoot, key);
    return currentRoot;
}

void prettyPrint(NodeT *currentRoot, int level) {
    if (currentRoot != NULL) {
        level += SPACE;
        prettyPrint(currentRoot->right, level);
        printf("\n");
        for (int i = SPACE; i < level; i++) {
            printf(" ");
        }
        printf("%d\n", currentRoot->key);
        prettyPrint(currentRoot->left, level);
    }
}

//for deleting

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

    currentRoot->height = 1 + getMax(getHeight(currentRoot->left), getHeight(currentRoot->right));

    int balance = getBalance(currentRoot);

    // Left Left Case
    if (balance > 1 && getBalance(currentRoot->left) >= 0)
        return rotateRight(currentRoot);

    // Left Right Case
    if (balance > 1 && getBalance(currentRoot->left) < 0) {
        currentRoot->left = rotateLeft(currentRoot->left);
        return rotateRight(currentRoot);
    }

    // Right Right Case
    if (balance < -1 && getBalance(currentRoot->right) <= 0)
        return rotateLeft(currentRoot);

    // Right Left Case
    if (balance < -1 && getBalance(currentRoot->right) > 0) {
        currentRoot->right = rotateRight(currentRoot->right);
        return rotateLeft(currentRoot);
    }
    return currentRoot;
}

NodeT *getSuccessor(NodeT *node) {
    NodeT *current = node;
    while (current->left != NULL)
        current = current->left;
    return current;
}