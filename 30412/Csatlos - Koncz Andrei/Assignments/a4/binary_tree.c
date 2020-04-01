//
// Created by csatl on 3/30/2020.
//

#include "binary_tree.h"

tree *Insert(tree * root, int key)
{
    if(root == NULL)
        return CreateNode(key);
    if(key < root->id)
        root->left = Insert(root->left,key);
    else if (key > root->id)
        root->right = Insert(root->right, key);
    else
        return root;
    root->height =Max(Height(root->left), Height(root->right)) + 1;

    int balance = GetBalance(root);
    if(balance > 1 && key < root->left->id)
        return RightRotate(root);
    if (balance < -1 && key > root->right->id)
        return LeftRotate(root);
    if (balance < -1 && key < root->right->id)
    {
        root->right = RightRotate(root->right);
        return LeftRotate(root);
    }
    if (balance > 1 && key > root->left->id)
    {
        root->left = LeftRotate(root->left);
        return RightRotate(root);
    }
    return root;
}

tree *CreateNode(int key)
{
    tree *p = (tree*)malloc(sizeof(tree));
    p->right = NULL;
    p->left = NULL;
    p->id = key;
    p->height = 1;
    return p;
}

int Height(tree * root)
{
    if(!root)
        return 0;
    return root->height;
}

int Max(int a, int b)
{
    if(a>b)
        return a;
    return b;
}

tree *RightRotate(tree *root)
{
    tree *x = root->left;
    tree *y = x->right;

    x->right = root;
    root->left = y;

    root->height = Max(Height(root->left), Height(root->right)) + 1;
    x->height = Max(Height(x->left), Height(x->right)) + 1;

    return x;
}

tree *LeftRotate(tree *root)
{
    tree *y = root->right;
    tree *x = y->left;

    y->left = root;
    root->right = x;

    root->height = Max(Height(root->left), Height(root->right)) + 1;
    y->height = Max(Height(y->left), Height(y->right)) + 1;
    return y;
}

int GetBalance(tree *N)
{
    if (N == NULL)
        return 0;
    return Height(N->left) - Height(N->right);
}

void PrettyPrint(tree *currentRoot, int level)
{
    if(currentRoot != NULL)
    {
        PrettyPrint(currentRoot->right,level+1);
        for(int i=0; i<level;i++)
            printf("     ");
        printf("%d\n",currentRoot->id);
        PrettyPrint(currentRoot->left,level+1);
    }
}