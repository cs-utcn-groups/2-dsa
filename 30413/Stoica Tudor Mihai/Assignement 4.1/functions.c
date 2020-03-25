#include "header.h"

NodeT* insertNode(NodeT* node, int data)
{
    if (node == NULL)
    {
        NodeT* node = (NodeT *) malloc(sizeof(NodeT));
        node->info   = data;
        node->left = node->right= NULL;
        node->height = 1;
        return node;
    }

    if (data < node->info)
    {
        node->left  = insertNode(node->left, data);
    }
    else if (data > node->info)
    {
        node->right = insertNode(node->right, data);
    }
    else
    {
        return node;
    }

    if(getHeight(node->left) > getHeight(node->right))
    {
        node->height = 1 + getHeight(node->left);
    }

    else
    {
        node->height = 1 + getHeight(node->right);
    }

    int balance = getBalance(node);

    if (balance > 1 && data < node->left->info)
    {
        return rotRight(node);
    }

    if (balance > 1 && data > node->left->info)
    {
        node->left =  rotLeft(node->left);
        return rotRight(node);
    }

    if (balance < -1 && data > node->right->info)
        return rotLeft(node);

    if (balance < -1 && data < node->right->info)
    {
        node->right = rotRight(node->right);
        return rotLeft(node);
    }

    return node;
}

void preOrder(NodeT *root)
{
    if(root != NULL)
    {
        printf("%d ", root->info);
        preOrder(root->left);
        preOrder(root->right);
    }
}

int getHeight(NodeT *node)
{
    if (node == NULL)
    {
        return 0;
    }
    return node->height;
}

int getBalance(NodeT *node)
{
    if (node == NULL)
    {
        return 0;
    }
    return getHeight(node->left) - getHeight(node->right);
}

NodeT *rotRight(NodeT * node)
{
    NodeT *nodeLeft = node->left;
    NodeT *nodeLR = nodeLeft->right;

    nodeLeft->right = node;
    node->left = nodeLR;

    if(getHeight(node->left) > getHeight(node->right))
    {
        node->height=getHeight(node->left)+1;
    }

    else
    {
        node->height=getHeight(node->right)+1;
    }

    if(getHeight(nodeLeft->left) > getHeight(nodeLeft->right))
    {
        nodeLeft->height=getHeight(nodeLeft->left)+1;
    }

    else
    {
        nodeLeft->height=getHeight(nodeLeft->right)+1;
    }

    return nodeLeft;
}

NodeT *rotLeft( NodeT *node)
{
    NodeT *nodeRight = node->right;
    NodeT *nodeRL = nodeRight->left;

    nodeRight->left = node;
    node->right = nodeRL;

    if(getHeight(node->left) > getHeight(node->right))
    {
        node->height=getHeight(node->left)+1;
    }

    else
    {
        node->height=getHeight(node->right)+1;
    }

    if(getHeight(nodeRight->left) > getHeight(nodeRight->right))
    {
        nodeRight->height=getHeight(nodeRight->left)+1;
    }

    else
    {
        nodeRight->height=getHeight(nodeRight->right)+1;
    }

    return nodeRight;
}

