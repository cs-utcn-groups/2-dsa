#include <stdio.h>
#include<stdlib.h>
#define COUNT 2
typedef  struct node{
    int key;
    struct node *left,*right;
    int height;
}NodeT;

NodeT *createNode(int key);
void prettyPrint(NodeT *root, int space);
int getMax(int x, int y);
int getHeight(NodeT *root);
NodeT *rotateLeft(NodeT *root);
NodeT *rotateRight(NodeT *root);
int getBalance(NodeT *root);
NodeT* insert(NodeT *root, int key);
int main() {
    NodeT * root;
    int value,nr,isRoot;
    printf("Number of nodes you want to insert: \n");
    scanf("%d",&nr);
    printf("Insert nodes: \n");
    isRoot=1;
    for(int i=0;i<nr;i++)
    {
        scanf("%d",&value);
        if(isRoot==1) {
            root = createNode(value);
            isRoot = 0;
        }
        else{
            root=insert(root,value);
        }


    }

    prettyPrint(root,0);
    return 0;
}

NodeT *createNode(int key) {
   NodeT *newNode=(NodeT*)malloc(sizeof(NodeT));
   newNode->left=NULL;
   newNode->right=NULL;
   newNode->key=key;
   newNode->height=1;
   return newNode;
}
void prettyPrint(NodeT *root, int space) {
    if (root == NULL) {
        return;
    }
    space += COUNT;
    prettyPrint(root->right, space);
    printf("\n");
    for (int i = COUNT; i < space; i++) {
        printf(" ");
    }
    printf("%d", root->key);
    prettyPrint(root->left, space);
}
NodeT* insert(NodeT *root, int key)
{
    int balance;
    if (root == NULL)
        return(createNode(key));

    if (key < root->key)
        root->left  = insert(root->left, key);
    else if (key > root->key)
       root->right = insert(root->right, key);
    else
        return root;


    root->height = getMax(getHeight(root->left),
                           getHeight(root->right))+1;

    balance = getBalance(root);


    if (balance>1 && key<root->left->key)
        return rotateRight(root);


    if (balance<-1 && key>root->right->key)
        return rotateLeft(root);


    if (balance>1 && key>root->left->key)
    {
        root->left =  rotateLeft(root->left);
        return rotateRight(root);
    }

    if (balance<-1 && key<root->right->key)
    {
        root->right = rotateRight(root->right);
        return rotateLeft(root);
    }
    return root;
}
int getMax(int x, int y)
{
    if(x>y)
        return x;
    else
        return y;

}
int getHeight(NodeT *root)
{
    if(root==NULL)
    {
        return 0;
    }
    return root->height;

}
int getBalance(NodeT *root)
{
    if(root==NULL)
    {
        return 0;
    }
    return getHeight(root->left)-getHeight(root->right);
}
NodeT *rotateLeft(NodeT *root)
{
    NodeT *child=root->right;
    NodeT* grandchild=child->left;
    child->left=root;
    root->right=grandchild;
    root->height=getMax(getHeight(root->left),getHeight(root->right))+1;
    child->height=getMax(getHeight(child->left),getHeight(child->right))+1;
    return child;
}
NodeT *rotateRight(NodeT *root)
{
    NodeT* child=root->left;
    NodeT* grandchild=child->right;
    child->right=root;
    root->left=grandchild;
    root->height=getMax(getHeight(root->left),getHeight(root->right))+1;
    child->height=getMax(getHeight(child->left),getHeight(child->right))+1;
    return child;
}
