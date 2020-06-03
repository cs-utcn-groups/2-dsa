//
// Created by Irina on 29/03/2020.
//
#include "head.h"

NodeT *createNode(int key){
    NodeT * newNode = (NodeT*)malloc(sizeof(NodeT));
    newNode->value = key;
    newNode-> height = 1;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}
int max(int a, int b){
    if(a > b){
        return a;
    } else {
        return b;
    }
}
int getHeight(NodeT * node){
    if(node == NULL){
        return 0;
    } else {
        return node->height;
    }
}
int getBalance(NodeT *node){
    if(node == NULL){
        return 0;
    } else {
        return getHeight(node->left) - getHeight(node->right);
    }
}
NodeT *rotateRight(NodeT *root) {
    NodeT *leftNode = root->left;
    NodeT *temp = leftNode->right;
    leftNode->right = root;
    root->left = temp;
    root->height = max(getHeight(root->left), getHeight(root->right)) + 1;
    leftNode->height = max(getHeight(leftNode->left), getHeight(leftNode->right)) + 1;
    return leftNode;
}
NodeT *rotateLeft(NodeT *root) {
    NodeT *rightNode = root->right;
    NodeT *aux2 = rightNode->left;
    rightNode->left = root;
    root->right = aux2;
    root->height = max(getHeight(root->left), getHeight(root->right)) + 1;
    rightNode->height = max(getHeight(rightNode->left), getHeight(rightNode->right)) + 1;
    return rightNode;
}
NodeT * insertNode(NodeT * root, int value) {
    if (root == NULL) {
        return createNode(value);
    }
    if (value < root->value) {
        root->left = insertNode(root->left, value);
    } else if (value > root->value) {
        root->right = insertNode(root->right, value);
    } else {
        printf("The value %d is already in the tree", value);
        return root;
    }
    root->height = 1 + max(getHeight(root->left), getHeight(root->right));
    if (getBalance(root) < -1 && value > root->right->value) {
        root = rotateLeft(root);
        return root;
    } else if (getBalance(root) > 1 && value < root->left->value) {
        root = rotateRight(root);
        return root;
    } else if (getBalance(root) < -1 && value < root->right->value) {
        root->right = rotateRight(root->right);
        root = rotateLeft(root);
        return root;
    } else if (getBalance(root) > 1 && value > root->left->value) {
        root->left = rotateLeft(root->left);
        root = rotateRight(root);
        return root;
    }
}
void prettyPrint(NodeT *root, int space) {
    {
        if (root == NULL) {
            return;
        }
        space += COUNT;
        prettyPrint(root->right, space);
        printf("\n");
        for (int i = COUNT; i < space; i++)
            printf(" ");
        printf("%d", root->value);
        prettyPrint(root->left, space);
    }
}
