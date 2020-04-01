//
// Created by ileana on 3/29/2020.
//

#include "head.h"


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

int getBalance(NodeT * node)
{
    return height(node->left)-height(node->right);

}
NodeT * minValue(NodeT * root)
{
    if(root!=NULL) {
        NodeT *node = root;
        while (node->left != NULL)
            node = node->left;
        return node;
    }
    return NULL;
}

