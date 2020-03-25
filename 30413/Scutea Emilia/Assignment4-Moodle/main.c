#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
typedef struct node
{
    char key;
    struct node * left, * right;
} BSTNode;
BSTNode * recursiveInsert(BSTNode * root,char key)
{
    BSTNode * p;
    if(root==NULL)
    {
        p=(BSTNode*)malloc(sizeof(BSTNode));
        p->key=key;
        p->left=p->right=NULL;
        root=p;
        return root;
    }
    else
    {
        if(key<root->key)
            root->left=recursiveInsert(root->left,key);
        else if(key>root->key)
            root->right=recursiveInsert(root->right,key);
        else
            printf("Node already exists in tree.\n");
    }
    return root;
}
BSTNode * createNode(BSTNode * root)
{
    int n;
    printf("Insert the nr of nodes:\n");
    scanf("%d",&n);
    char key;
    for(int i=0; i<n; i++)
    {
        printf("Insert an uppercase key:\n");
        scanf(" %c",&key);
        while(!isupper(key))
        {
            printf("Key is not uppercase. Insert a key again:\n");
            scanf(" %c",&key);
        }
        root=recursiveInsert(root,key);
    }
    return root;
}
void inorder(BSTNode * root,int level)
{
    if(root)
    {
        inorder(root->left,level+1);
        for(int i=0; i<=level; i++)
            printf(" ");
        printf("%c\n",root->key);
        inorder(root->right,level+1);
    }
}
void preorder(BSTNode * root,int level)
{
    if(root)
    {
        for(int i=0; i<=level; i++)
            printf(" ");
        printf("%c\n",root->key);
        preorder(root->left,level+1);
        preorder(root->right,level+1);
    }
}
void postorder(BSTNode * root,int level)
{
    if(root)
    {
        preorder(root->left,level+1);
        preorder(root->right,level+1);
        for(int i=0; i<=level; i++)
            printf(" ");
        printf("%c\n",root->key);
    }
}
BSTNode * findMin(BSTNode * p)
{
    if(p==NULL)
        return NULL;
    if(p->left)
        return findMin(p->left);
    else
        return p;
}
BSTNode * findMax(BSTNode * p)
{
    if(p == NULL)
        return NULL;
    if(p->right!=NULL)
        return findMax(p->right);
    else
        return p;
}
int findNode(BSTNode * p,char key)
{
    if(p==NULL)
        return NULL;
    else if(key==p->key)
        return 1;
    else if(key<p->key)
        return findNode(p->left,key);
    else if(key>p->key)
        return findNode(p->right,key);
    else return 0;
}
BSTNode * deleteNode(BSTNode * p,char key)
{
    if(p==NULL)
        printf("Element not found.\n");
    else if(key<p->key)
        p->left=deleteNode(p->left,key);
    else if(key>p->key)
        p->right=deleteNode(p->right,key);
    else
    {
        if(p->left && p->right)
        {
            BSTNode * temp=findMin(p->right);
            p->key=temp->key;
            p->right=deleteNode(p->right,temp->key);
        }
        else
        {
            BSTNode * temp=p;
            if(p->left==NULL)
                p=p->right;
            else p=p->left;
            free(temp);
        }
    }
    return p;
}
void deleteGivenNode(BSTNode * root)
{
    char key;
    printf("Enter the key of the node you wanna delete:\n");
    scanf(" %c",&key);
    deleteNode(root,key);
    printf("Inorder listing of the changed tree:\n");
    inorder(root,0);
}
void printSearchedNode(BSTNode * root)
{
    char key;
    printf("Enter the key you want to search in the tree:\n");
    scanf(" %c",&key);
    if(findNode(root,key)==1)
        printf("The node with key %c was found in the tree.\n",key);
    else printf("The node with key %c was not found in the tree.\n",key);
}

int main()
{
    BSTNode * root=NULL;
    root=createNode(root);
    printf("Preorder listing:\n");
    preorder(root,0);
    printf("Inorder listing:\n");
    inorder(root,0);
    printf("Postorder listing:\n");
    postorder(root,0);
    BSTNode * minimum=findMin(root);
    printf("The minimum of the tree is %c.\n",minimum->key);
    BSTNode * maximum=findMax(root);
    printf("The maximum of the tree is %c.\n",maximum->key);
    printSearchedNode(root);
    deleteGivenNode(root);
}
