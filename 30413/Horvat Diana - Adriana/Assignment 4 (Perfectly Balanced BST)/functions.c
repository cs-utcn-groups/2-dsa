#include "head.h"
NodeT *root=NULL;

NodeT *newNode(int key)
{
    NodeT *node=(NodeT *)malloc(sizeof(NodeT));
    node->data=key;
    node->height=1;
    node->left=NULL;
    node->right=NULL;
    return node;
}

int height(NodeT *node)
{
    if (node==NULL)
        return 0;
    else
        return node->height;
}

int max(int x, int y)
{
    if(x>=y)
        return x;
    else
        return y;
}

NodeT *rightRotate(NodeT *z)
{
    NodeT *y=z->left;
    NodeT *ST=y->right;

    y->right=z;
    z->left=ST;

    z->height=max(height(z->left),height(z->right))+1;
    y->height=max(height(y->left),height(y->right))+1;

    return y;
}

NodeT *leftRotate(NodeT *z)
{
    NodeT *y=z->right;
    NodeT *SB=y->left;

    y->left=z;
    z->right=SB;

    z->height=max(height(z->left),height(z->right))+1;
    y->height=max(height(y->left),height(y->right))+1;

    return y;
}

NodeT *insertPBBST(NodeT *node,int key)
{
    int balance;
    if(node==NULL)
    {
        return node=newNode(key);
    }
    else
    {
        if(key<node->data)
            node->left=insertPBBST(node->left,key);
        else if(key>node->data)
            node->right=insertPBBST(node->right,key);
    }

    node->height=1+max(height(node->left),height(node->right));

    balance=height(node->left)-height(node->right);

    if(balance>1 && key<node->left->data)
        return rightRotate(node);
    else if(balance>1 && key>node->left->data)
    {
        node->left=leftRotate(node->left);
        return rightRotate(node);
    }
    else if(balance<-1 && key<node->right->data)
    {
        node->right=rightRotate(node->right);
        return leftRotate(node);
    }
    else if(balance<-1 && key>node->right->data)
        return leftRotate(node);

    return node;

}

NodeT *preorder (NodeT *node, int level, FILE *g)
{
    if(node==NULL)
        return;
    else
    {
        for(int i=0; i<level; i++)
            fprintf(g,"  ");
        fprintf(g,"%d\n",node->data);
        preorder(node->left,level+1,g);
        preorder(node->right,level+1,g);
    }
}

void createPBBST(FILE *f, FILE *g)
{
    int key;
    while(fscanf(f,"%d",&key)>0)
    {
        root=insertPBBST(root,key);
    }

    preorder(root,0,g);
}

