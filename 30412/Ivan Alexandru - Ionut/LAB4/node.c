//
// Created by Ivan on 4/1/2020.
//

#include <stdio.h>
#include <stdlib.h>
#include "node.h"

struct Node* newNode(int key)
{
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->key = key;
    node->left = NULL;
    node->right = NULL;
    node->height = 1;
    return(node);
}

int max(int a, int b);

int height(struct Node *N)
{
    if (N == NULL)
        return 0;
    return N->height;
}

int max(int a, int b)
{
    if(a > b)
        return a;
    else return b;
}

struct Node *rotateR(struct Node *y)
{
    struct Node *x = y->left;
    struct Node *T2 = x->right;

    x->right = y;
    y->left = T2;

    y->height = max(height(y->left), height(y->right))+1;
    x->height = max(height(x->left), height(x->right))+1;

    return x;
}

struct Node *rotateL(struct Node *x)
{
    struct Node *y = x->right;
    struct Node *T2 = y->left;

    y->left = x;
    x->right = T2;

    x->height = max(height(x->left), height(x->right))+1;
    y->height = max(height(y->left), height(y->right))+1;

    return y;
}

struct Node* insert(struct Node* node, int key)
{
    if (node == NULL)
        return(newNode(key));

    if (key < node->key)
        node->left = insert(node->left, key);
    else if (key > node->key)
        node->right = insert(node->right, key);
    else
        return node;

    node->height = 1 + max(height(node->left),
                           height(node->right));

    int balance;
    if (node == NULL)
        balance = 0;
    else balance = height(node->left) - height(node->right);

    if (balance > 1 && key < node->left->key)
    {
        return rotateR(node);
    }

    if (balance < -1 && key > node->right->key)
    {

    }

    if (balance > 1 && key > node->left->key)
    {
        node->left = rotateL(node->left);
        return rotateR(node);
    }

    if (balance < -1 && key < node->right->key)
    {
        node->right = rotateR(node->right);
        return rotateL(node);
    }

    return node;
}

void preord(struct Node *root)
{
    if(root != NULL)
    {
        printf("%d ", root->key);
        preord(root->left);
        preord(root->right);
    }
}
