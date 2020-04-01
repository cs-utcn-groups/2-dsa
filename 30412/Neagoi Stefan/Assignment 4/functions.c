//
// Created by Stefan on 31/03/2020.
//
#include "header.h"

NodeT *newNode(int data) {
    NodeT *node = (NodeT*)malloc(sizeof(NodeT));
    node->left = NULL;
    node->right = NULL;
    node->data = data;
    node->height = 1;

    return node;
}

int height(NodeT *N)
{
    if (N == NULL)
        return 0;
    return N->height;
}

int max(int a, int b) {
    return (a > b)? a : b;
}

NodeT *rotateRight(NodeT *y) {
    NodeT *x = y->left;
    NodeT *T2 = x->right;
    x->right = y;
    y->left = T2;
    y->height = max(height(y->left),
                    height(y->right)) + 1;
    x->height = max(height(x->left),
                    height(x->right)) + 1;

    return x;
}

NodeT *rotateLeft(NodeT *x) {
    NodeT *y = x->right;
    NodeT *T2 = y->left;
    y->left = x;
    x->right = T2;
    x->height = max(height(x->left),
                    height(x->right)) + 1;
    y->height = max(height(y->left),
                    height(y->right)) + 1;

    return y;
}

int getBalance(NodeT *N) {
    if (N == NULL)
        return 0;
    return height(N->left) - height(N->right);

}

NodeT* insert(NodeT* node, int key) {

    if (node == NULL)
        return(newNode(key));
    if (key < node->data)
        node->left  = insert(node->left, key);
    else if (key > node->data)
        node->right = insert(node->right, key);
    else
        return node;


    node->height = 1 + max(height(node->left),
                           height(node->right));
    int balance = getBalance(node);


    if (balance > 1 && key < node->left->data)
        return rotateRight(node);
    if (balance < -1 && key > node->right->data)
        return rotateLeft(node);
    if (balance > 1 && key > node->left->data)
    {
        node->left =  rotateLeft(node->left);
        return rotateRight(node);
    }

    if (balance < -1 && key < node->right->data)
    {
        node->right = rotateRight(node->right);
        return rotateLeft(node);
    }

    return node;
}

void prettyPrint(NodeT *root, int level) {
    if (root->right != NULL)
        prettyPrint(root->right, level + 1);
    for (int i = 0; i < level; i++)
        printf("    ");
    printf("%c\n", root->data);
    if (root->left != NULL)
        prettyPrint(root->left, level + 1);
}

void preorder(NodeT *currentRoot, int lv){
    if (currentRoot != NULL) {
        for (int i = 0; i < lv; i++) {
            printf("*");
        }
        printf("%d", currentRoot->data);
        preorder(currentRoot->left, lv + 1);
        preorder(currentRoot->right, lv + 1);
    }
}

