#include <stdio.h>
#include <stdlib.h>
typedef struct node
{
    int key,height;
    struct node * left, * right;
}BSTNode;
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
        else return rightDepth+1;
    }
}
int balanceFactor(BSTNode * root)
{
    if(root==NULL)
        return 0;
    return height(root->left)-height(root->right);
}
BSTNode * rightRotate(BSTNode * p)
{
    BSTNode * temp1 = p->left;
    BSTNode * temp2 = temp1->right;
    temp1->right = p;
    p->left =temp2;
    p->height=height(p);
    temp1->height=height(temp1);
    return temp1;
}
BSTNode * leftRotate(BSTNode * p)
{
    BSTNode * temp1=p->right;
    BSTNode * temp2=temp1->left;
    temp1->left=p;
    p->right=temp2;
    p->height=height(p);
    temp1->height=height(temp1);
    return temp1;
}
BSTNode * newNode(int key)
{
    BSTNode * p=(BSTNode*)malloc(sizeof(BSTNode));
    p->key=key;
    p->left=NULL;
    p->right=NULL;
    p->height=1;
    return p;
}
BSTNode * recursiveInsert(BSTNode * root,int key)
{
    if (root==NULL)
        root=newNode(key);
    else if(key<root->key)
        root->left=recursiveInsert(root->left, key);
    else if(key>root->key)
        root->right=recursiveInsert(root->right, key);
    root->height=height(root);
    int balance=balanceFactor(root);
    ///LEFT LEFT
    if(balance>1 && key<root->left->key)
        return rightRotate(root);
    /// LEFT RIGHT
    if(balance>1 && key>root->left->key)
    {
        root->left = leftRotate(root->left);
        return rightRotate(root);
    }
    /// RIGHT RIGHT
    if (balance<-1 && key>root->right->key)
        return leftRotate(root);
    ///RIGHT LEFT
    if (balance<-1 && key<root->right->key)
    {
        root->right = rightRotate(root->right);
        return leftRotate(root);
    }
    return root;
}
BSTNode * createTree(BSTNode * root)
{
    int n;
    printf("Insert the number of nodes:\n");
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        int key;
        printf("Insert a key:\n");
        scanf("%d",&key);
        root=insert(root,key);
    }
    return root;
}
void inorder(BSTNode * root,int level)
{
    if(root!=NULL)
    {
        inorder(root->left,level+1);
        for(int i=0;i<=level;i++)
            printf(" ");
        printf("%d\n",root->key);
        inorder(root->right,level+1);
    }
}
int main()
{
    BSTNode *root = NULL;
    root=createTree(root);
    printf("Inorder listing:\n");
    inorder(root,0);
    return 0;
}
