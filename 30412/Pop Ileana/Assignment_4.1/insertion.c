//
// Created by ileana on 3/28/2020.
//

#include "head.h"

int getMax(int a, int b);
int height(NodeT * node);


NodeT * createNode(int key)
{
    NodeT *  node = (NodeT*)malloc(sizeof(NodeT));
    node->key=key;
    node->left=NULL;
    node->right=NULL;
    node->height=1;
    return node;
}

NodeT * leftRotate(NodeT * node)
{
    NodeT * x = node->right;
    NodeT * restOfTree = x->left;

    x->left = node;
    node->right=restOfTree;

    node->height=1+getMax(height(node->left),height(node->right));
    x->height = 1 + getMax(height(x->left),height(x->right));

    return x;
}


NodeT * rightRotate(NodeT * node)
{
    NodeT * x = node->left;
    NodeT * restOfTree = x->right;

    x->right = node;
    node->left=restOfTree;

    node->height=1+getMax(height(node->left),height(node->right));
    x->height = 1 + getMax(height(x->left),height(x->right));
    return x;
}



NodeT * insert(NodeT * root, int key)
{
    if(root==NULL)
        return createNode(key);
    if(key < root->key)
        root->left = insert(root->left, key);
    else
        if(key > root->key)
            root->right=insert(root->right,key);
        else
            return root;

    root->height=1+getMax(height(root->left),height(root->right));

    int balance = height(root->left)-height(root->right);

    if(balance>1 || balance<-1)
        printf("Node %d is unbalanced %d \n",root->key,balance);

    if(balance>1 && key < root->left->key)   //Left Left Case
        return rightRotate(root);
    if(balance>1 && key > root->left->key)    //Left Right Case
    {
        root->left = leftRotate(root->left);
        return rightRotate(root);
    }
    if(balance<-1 && key > root->right->key)      //Right Right Case
        return leftRotate(root);
    if(balance<-1 && key < root->right->key)      //Right Left Case
    {
        root->right=rightRotate(root->right);
        return leftRotate(root);
    }
    return root;
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
        printf("%d", root->key);
        prettyPrint(root->left, space);
    }
}

int getMax(int a, int b)
{
    if(a>b)
        return a;
    return b;
}

int height(NodeT * node)
{
    if(node==NULL)
        return 0;
    return node->height;
}

