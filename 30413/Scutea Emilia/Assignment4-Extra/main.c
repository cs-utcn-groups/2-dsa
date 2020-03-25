#include <stdio.h>
#include <stdlib.h>
typedef struct node
{
    int key,height;
    struct node * left, * right;
} BSTNode;
int height(BSTNode * root)
{
    if(root==NULL)
        return 0;
    else
    {
        int leftDepth=height(root->left);
        int rightDepth=height(root->right);
        if(leftDepth>rightDepth)
            return leftDepth+1;
        else
            return rightDepth+1;
    }
}
int balanceFactor(BSTNode * root)
{
    if(root==NULL)
        return 0;
    else
        return height(root->left)-height(root->right);
}
BSTNode * minimumNode(BSTNode * root)
{
    if(root==NULL)
        return root;
    else if(root->left!=NULL)
        return minimumNode(root->left);
    else return root;
}
BSTNode * leftRotate(BSTNode * x)
{
    BSTNode * aux1=x->right;
    BSTNode * aux2=aux1->left;
    aux1->left=x;
    x->right=aux2;
    aux1->height=height(aux1);
    x->height=height(x);
    return aux1;
}
BSTNode * rightRotate(BSTNode * x)
{
    BSTNode * aux1=x->left;
    BSTNode * aux2=aux1->right;
    aux1->right=x;
    x->left=aux2;
    aux1->height=height(aux1);
    x->height=height(x);
    return aux1;
}
BSTNode * newNode(int key)
{
    BSTNode * p=(BSTNode*)malloc(sizeof(BSTNode));
    p->key=key;
    p->height=1;
    p->left=NULL;
    p->right=NULL;
    return p;
}

BSTNode * recursiveInsert(BSTNode * root,int key)
{
    if(root==NULL)
    {
        root=newNode(key);
        return root;
    }
    else if(key<root->key)
        root->left=recursiveInsert(root->left,key);
    else if(key>root->key)
        root->right=recursiveInsert(root->right,key);
    else return root;

    root->height=height(root);
    int balance=balanceFactor(root);
    ///LEFT LEFT CASE
    if(balance>1 && key<root->left->key)
        return rightRotate(root);
    ///LEFT RIGHT CASE
    if(balance>1 && key>root->left->key)
    {
        root->left=leftRotate(root->left);
        return rightRotate(root);
    }
    ///RIGHT RIGHT CASE
    if(balance<-1 && key>root->right->key)
        return leftRotate(root);
    ///RIGHT LEFT CASE
    if(balance<-1 && key<root->right->key)
    {
        root->right=rightRotate(root->right);
        return leftRotate(root);
    }
    return root;
}

BSTNode * createTree(BSTNode * root)
{
    int n;
    printf("Insert the number of nodes:\n");
    scanf("%d",&n);
    for(int i=0; i<n; i++)
    {
        int key;
        printf("Insert a key:\n");
        scanf("%d",&key);
        root=recursiveInsert(root,key);
    }
    return root;
}

BSTNode * deleteNode(BSTNode * root,int key)
{
    if(root==NULL)
        return root;
    else if(key<root->key)
        root->left=deleteNode(root->left,key);
    else if(key>root->key)
        root->right=deleteNode(root->right,key);
    else
    {
        if(root->left !=NULL && root->right!=NULL)
        {
            BSTNode * p=minimumNode(root->right);
            root->key=p->key;
            root->right=deleteNode(root->right,p->key);
        }
        else
        {
            BSTNode * p=root;
            if(root->left==NULL)
                root=root->right;
            else root=root->left;
            free(p);
        }
    }
    return root;

    root->height=height(root);
    int balance=balanceFactor(root);
    ///LEFT LEFT CASE
    if(balance>1 && key<root->left->key)
        return rightRotate(root);
    ///LEFT RIGHT CASE
    if(balance>1 && key>root->left->key)
    {
        root->left=leftRotate(root->left);
        return rightRotate(root);
    }
    ///RIGHT RIGHT CASE
    if(balance<-1 && key>root->right->key)
        return leftRotate(root);
    ///RIGHT LEFT CASE
    if(balance<-1 && key<root->right->key)
    {
        root->right=rightRotate(root->right);
        return leftRotate(root);
    }
    return root;
}

void inorder(BSTNode * root,int level)
{
    if(root!=NULL)
    {
        inorder(root->left,level+1);
        for(int i=0; i<=level; i++)
            printf(" ");
        printf("%d\n",root->key);
        inorder(root->right,level+1);
    }
}

void deleteGivenNode(BSTNode * root)
{
    int key;
    printf("\nInsert the key of the node you wanna delete:\n");
    scanf("%d",&key);
    deleteNode(root,key);
    printf("Inorder listing of the changed tree:\n");
    inorder(root,0);
}
int main()
{
    BSTNode * root=NULL;
    root=createTree(root);
    printf("Inorder listing of the binary tree:\n");
    inorder(root,0);
    deleteGivenNode(root);
    return 0;
}
