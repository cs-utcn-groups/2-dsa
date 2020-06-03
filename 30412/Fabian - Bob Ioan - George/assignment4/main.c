#include <stdio.h>
#include <stdlib.h>

typedef  struct node{
    int key;
    struct node *left,*right;
    int height;
}NodeT;

NodeT *create(int key);

void print(NodeT *root, int n);
int MAX(int x, int y);
int HEIGHT(NodeT *root);
int eq(NodeT *root);

NodeT* insert(NodeT *root, int key);
NodeT *leftR(NodeT *root);
NodeT *rightR(NodeT *root);

int main() {

    NodeT * root;
    int userIn,n,auxRoot;

    printf("How many nodes do you want to insert? \n");
    scanf("%d",&n);

    printf("Nodes: \n");
    auxRoot=1;
    for(int i=0; i<n; i++)
    {
        scanf("%d",&userIn);
        if(auxRoot == 1) {
            root = create(userIn);
            auxRoot = 0;
        }
        else{
            root=insert(root, userIn);
        }
    }
    print(root, 0);
    return 0;
}

NodeT *create(int key) {
    NodeT *newNode=(NodeT*)malloc(sizeof(NodeT));
    newNode->left=NULL;
    newNode->right=NULL;
    newNode->key=key;
    newNode->height=1;
    return newNode;
}

void print(NodeT *root, int n) {
    if (root == NULL) {
        return;
    }
    n = n+2;
    print(root->right, n);
    printf("\n");
    for (int i = 2; i<n; i++) {
        printf(" ");
    }
    printf("%d", root->key);
    print(root->left, n);
}
NodeT* insert(NodeT *root, int key)
{
    int balance;
    if (root == NULL)
        return(create(key));
    if (key < root->key)
        root->left  = insert(root->left, key);
    else if (key > root->key)
        root->right = insert(root->right, key);
    else
        return root;
    root->height = MAX(HEIGHT(root->left),HEIGHT(root->right)) + 1;
    balance = eq(root);
    if (balance>1 && key<root->left->key)
        return rightR(root);
    if (balance<-1 && key>root->right->key)
        return leftR(root);
    if (balance>1 && key>root->left->key)
    {
        root->left = leftR(root->left);
        return rightR(root);
    }
    if (balance<-1 && key<root->right->key)
    {
        root->right = rightR(root->right);
        return leftR(root);
    }
    return root;
}
int MAX(int x, int y)
{
    if(x>y)
        return x;
    else
        return y;
}
int HEIGHT(NodeT *root)
{
    if(root==NULL)
    {
        return 0;
    }
    return root->height;

}
int eq(NodeT *root)
{
    if(root==NULL)
    {
        return 0;
    }
    return HEIGHT(root->left) - HEIGHT(root->right);
}
NodeT *leftR(NodeT *root)
{
    NodeT *next=root->right;
    NodeT* grandchild=next->left;
    next->left=root;
    root->right=grandchild;
    root->height= MAX(HEIGHT(root->left), HEIGHT(root->right)) + 1;
    next->height= MAX(HEIGHT(next->left), HEIGHT(next->right)) + 1;
    return next;
}
NodeT *rightR(NodeT *root)
{
    NodeT* child=root->left;
    NodeT* next2=child->right;
    child->right=root;
    root->left=next2;
    root->height= MAX(HEIGHT(root->left), HEIGHT(root->right)) + 1;
    child->height= MAX(HEIGHT(child->left), HEIGHT(child->right)) + 1;
    return child;
}