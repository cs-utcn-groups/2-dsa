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
    if(node==NULL)
        return 0;
    else
        return node->height;
}

int getBalance(NodeT *node)
{
    if(node==NULL)
        return;
    else
        return height(node->left)-height(node->right);
}

int max(int x, int y)
{
    if(x>=y)
        return x;
    else
        return y;
}

NodeT *rotateRight(NodeT *z)
{
    NodeT *y=z->left;
    NodeT *ST=y->right;

    y->right=z;
    z->left=ST;

    z->height=max(height(z->left),height(z->right))+1;
    y->height=max(height(y->left),height(y->right))+1;

    return y;
}

NodeT *rotateLeft(NodeT *z)
{
    NodeT *y=z->right;
    NodeT *ST=y->left;

    y->left=z;
    z->right=ST;

    y->height=1+max(height(y->left),height(y->right));
    z->height=1+max(height(z->left),height(z->right));

    return y;
}

NodeT *insertNode(NodeT *node,int key)
{
    int balance;
    if(node==NULL)
    {
        return node=newNode(key);
    }
    else
    {
        if(key<node->data)
            node->left=insertNode(node->left,key);
        else if(key>node->data)
            node->right=insertNode(node->right,key);
    }

    node->height=1+max(height(node->left),height(node->right));

    balance=getBalance(node);

    if(balance>1 && key<node->left->data)
        return rotateRight(node);

    else if(balance>1 && key>node->left->data)
    {
        node->left=rotateLeft(node->left);
        return rotateRight(node);
    }

    else if(balance<-1 && key<node->right->data)
    {
        node->right=rotateRight(node->right);
        return rotateLeft(node);
    }

    else if(balance<-1 && key>node->right->data)
        return rotateLeft(node);

    return node;
}

NodeT *preorder(NodeT *node, int level, FILE *g)
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
        root=insertNode(root,key);
    }

    fprintf(g,"The Perfectly Balanced Binary Search Tree is:\n");
    preorder(root,0,g);
}

NodeT *findNode(NodeT *node,int key)
{
    if(node==NULL)
        return;

    NodeT *p=node;

    while(p!=NULL)
    {
        if(key<p->data)
            p=p->left;
        else if(key>p->data)
            p=p->right;
        else
            return p;
    }
    return;
}

NodeT *getMin(NodeT *node)
{
    if(node==NULL)
        return;
    else if(node->left)
        return getMin(node->left);
    else
        return node;
}

NodeT *deleteNode(NodeT *node, int key)
{
    int balance;
    if(node==NULL)
        printf("Element not found/n");
    else
    {
        if(key<node->data)
            node->left=deleteNode(node->left,key);
        else
        {
            if(key>node->data)
                node->right=deleteNode(node->right,key);
            else
            {
                if(node->left && node->right)
                {
                    NodeT *temp=getMin(node->right);
                    node->data=temp->data;
                    node->right=deleteNode(node->right,temp->data);
                }
                else
                {
                    NodeT *temp=node;
                    if(node->left==NULL)
                        node=node->right;
                    else if(node->right==NULL)
                        node=node->left;
                }

            }
        }
    }

    if(node==NULL)
        return;

    node->height=1+max(height(node->left),height(node->right));

    balance=getBalance(node);

    if(balance>1 && getBalance(node->left)>=0)
        return rotateRight(node);
    else if(balance>1 && getBalance(node->left)<0)
    {
        node->left=rotateLeft(node->left);
        return rotateRight(node);
    }
    else if(balance<-1 && getBalance(node->right)<=0)
        return rotateLeft(node);
    else if(balance<-1 && getBalance(node->right)>0)
    {
        node->right=rotateRight(node->right);
        return rotateLeft(node);
    }

    return node;
}

void deleteNodesInPBBST(FILE *g)
{
    int key,k=0;
    printf("Enter the node you want to delete: ");
    scanf("%d",&key);
    while(k==0)
    {
        if(findNode(root,key)==NULL)
        {
            printf("The node you entered doesn't exist in the initial tree. Enter another node: ");
            scanf("%d",&key);
        }
        else
        {
            k=1;
            deleteNode(root,key);
            fprintf(g,"After deleting the node with the value %d, our tree is:\n",key);
            preorder(root,0,g);
        }
    }

}

