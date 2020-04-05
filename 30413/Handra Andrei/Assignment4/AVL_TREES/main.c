#include "head.h"

int height(NodeT *node);
int maxn(int,int);
NodeT* rightRotate(NodeT *node);
NodeT* leftRotate(NodeT *node);
int balance(NodeT *node);
NodeT *createnode(int key);
NodeT *insertAVL(NodeT * root,int key);


int main()
{
    NodeT *root=createnode(10);
    insertAVL(root,11);
    insertAVL(root,4);
    insertAVL(root,2);
    insertAVL(root,15);
    insertAVL(root,3);
    PrettyPrint(root,0);
}

int height(NodeT *node)
{
    if(node==NULL)
    {
        return 0;
    }
    return node->height;
}
int maxn(int a,int b)
{
    if (a>b)
        return a;
    else
        return b;
}
NodeT* rightRotate(NodeT *node)
{
    NodeT *x=node->left;
    NodeT *y=x->right;

    x->right=node;
    node->left=y;

    node->height=maxn(height(node->left),height(node->right))+1;
    x->height=maxn(height(x->left),height(x->right))+1;

    return x;
}
NodeT* leftRotate(NodeT *node)
{
    NodeT *x=node->right;
    NodeT *y=x->left;

    x->left=node;
    node->right=y;

    node->height=maxn(height(node->left),height(node->right))+1;
    x->height=maxn(height(x->left),height(x->right))+1;

    return x;
}
int balance(NodeT *node)
{
    if(node == NULL)
    {
        return 0;
    }
    return balance(node->left)-balance(node->right);
}
NodeT *createnode(int key)
{
    NodeT *node=(NodeT*)malloc(sizeof(NodeT));
    node->key=key;
    node->left=NULL;
    node->right=NULL;
    node->height=1;
    return node;
}
NodeT *insertAVL(NodeT * root,int key)
{
    if(root == NULL)
    {
        return(createnode(key));
    }
    if (key < root->key)
    {
        root->left  = insertAVL(root->left, key);
    }
    else if (key > root->key)
    {
        root->right = insertAVL(root->right, key);
    }
    else
    {
        return root;
    }

    root->height=1+ maxn(height(root->left),height(root->right));

    int balance_nr=balance(root);

    if(balance_nr > 1 && key < root->left->key)
    {
        return rightRotate(root);
    }
    if(balance_nr > 1 && key > root->right->key)
    {
        return leftRotate(root);
    }
    if(balance_nr > 1 && key > root->left->key)
    {
        root->left=leftRotate(root->left);
        return rightRotate(root);
    }
    if(balance_nr < -1 && key<root->right->key)
    {
        root->right=rightRotate(root->right);
        return leftRotate(root);
    }
    return root;

}
