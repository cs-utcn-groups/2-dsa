#include "avl.h"
#include <stdio.h>
#include <stdlib.h>

int height(struct node *root)
{
    if (root == NULL)
        return 0;
    return root->height;
}

int max(int a, int b)
{
    if(a>b) return a;
    else    return b;
}

NodeT *newNode( int key )
{
    NodeT *p = (NodeT*)malloc(sizeof(NodeT));
    p->key = key;
    p->left = NULL;
    p->right = NULL;
    p->height = 1;
    return p;
}

NodeT *rightRotate( NodeT *root)
{
    NodeT *x = root->left;
    NodeT *T2 = x->right;

    x->right = root;
    root->left = T2;

    root->height = max(height(root->left), height(root->right))+1;
    x->height = max(height(x->left), height(x->right))+1;

    return x;
}

NodeT *leftRotate( NodeT *root)
{
    NodeT *y = root->right;
    NodeT *T2 = y->left;

    y->left = root;
    root->right = T2;

    root->height = max(height(root->left), height(root->right))+1;
    y->height = max(height(y->left), height(y->right))+1;

    return y;
}

int getBalance(NodeT *root)
{
    if(root == NULL)
        return 0;
    return height(root->left) - height(root->right);
}

NodeT *insert(NodeT * root, int key)
{
    if(root == NULL)
        return newNode(key);

    if(key <  root->key)
        root->left = insert(root->left, key);
    else if(key > root->key)
        root->right = insert(root->right, key);
    else return root;

    root->height = 1 + max(height(root->left), height(root->right));

    int bf = getBalance(root);

    //LLC
    if(bf > 1 && key < root->left->key)
        return rightRotate(root);

    //RRC
    if(bf < -1 && key > root->right->key)
        return leftRotate(root);

    //lRC
    if(bf > 1 && key > root->left->key)
    {
        root->left = leftRotate(root->left);
        return rightRotate(root);
    }

    //RLC
    if( bf < -1 && key < root->right->key)
    {
        root->right = rightRotate(root->right);
        return leftRotate(root);
    }

    return root;
}




