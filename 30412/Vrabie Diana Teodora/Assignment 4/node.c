//
// Created by diana on 07/05/2020.
//

#include <stdio.h>
#include "node.h"

void printTree(Node* node, int level) {
    if (node != NULL)
    {
        printTree(node->left, level + 1);
        for (int i = 1; i <= level; i++) {
            printf("    ");
        }
        printf("%d\n", node->key);
        printTree(node->right, level + 1);
    }
}

int maximum(int a, int b) {
    // returns non-zero if a > b
    return (a > b) ? a : b;
}

int height(Node *node) {
    if (node == NULL)
        return 0;
    return node->height;
}

Node *createNewNode(int key) {
    Node *newNode = (Node *) malloc(sizeof(Node));
    newNode->key = key;
    newNode->left = newNode->right = NULL;
    newNode->height = 1; // assume node is leaf
    return newNode;
}

Node *rotateRight(Node *currentNode) {
    Node *newRoot = currentNode->left;
    Node *newRootChild = newRoot->right;

    // rotation
    newRoot->right = currentNode;
    currentNode->left = newRootChild;

    // update the heights of nodes
    currentNode->height = maximum(height(currentNode->left), height(currentNode->right) + 1);
    newRoot->height = maximum(height(newRoot->left), height(newRoot->right) + 1);

    return newRoot;
}

Node *rotateLeft(Node *currentNode) {
    Node *newRoot = currentNode->right;
    Node *newRootChild = newRoot->left;

    // rotation
    newRoot->left = currentNode;
    currentNode->right = newRootChild;

    // update the heights of nodes
    currentNode->height = maximum(height(currentNode->left), height(currentNode->right)+1);
    newRoot->height = maximum(height(newRoot->left), height(newRoot->right)+1);

    return newRoot;
}

int getBalanceFactor(Node *node) {
    if (node == NULL)
        return 0;
    return height(node->left) - height(node->right);
}

Node *insertNode(Node *root, int key) {
    // normal insertion in a BST
    if (root == NULL) { // tree is empty
        Node *newNode = createNewNode(key);
        return newNode;
    }

    if (key < root->key)
        root->left = insertNode(root->left, key);
    else if (key > root->key)
        root->right = insertNode(root->right, key);
    else {
        perror("Duplicate key, terminating.");
        exit(-1);
    }

    // new node inserted, height of root must be adjusted
    root->height = 1+ maximum(height(root->left), height(root->right));

    // get balance factor to determine if rotation is needed
    int balance = getBalanceFactor(root);

    // check for the unbalancing cases
    // Left Left
    if (balance > 1 && key < root->left->key)
        return rotateRight(root);

    // Right Right
    if (balance < -1 && key > root->right->key)
        return  rotateLeft(root);

    // Left Right
    if (balance > 1 && key > root->left->key) {
        root->left = rotateLeft(root->left);
        return rotateRight(root);
    }

    // Right Left
    if (balance < -1 && key < root->right->key) {
        root->right = rotateRight(root->right);
        return rotateRight(root);
    }

    // No rotation necessary
    return root;
}
