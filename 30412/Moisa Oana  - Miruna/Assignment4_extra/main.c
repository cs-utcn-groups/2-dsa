#include <stdio.h>
#include <stdlib.h>
#define COUNT 2
typedef struct node{
    int key;
    int height;
    struct node *left,*right;
}NodeT;

NodeT *createNode(int key);
void preOrder(NodeT *root);
void prettyPrint(NodeT *root, int space);
int getMax(int x, int y);
int getHeight(NodeT *root);
NodeT * rotateRight(NodeT *root);
NodeT * getSuccessor(NodeT *root);
NodeT *rotateLeft(NodeT *root);
NodeT * insert(NodeT*root, int key);
NodeT *delete(NodeT *root, int key);
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
    printf("\n");
    printf("Node to delete: \n");
    scanf("%d",&value);
    root = delete(root, value);
    prettyPrint(root,0);
    return 0;
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

NodeT *createNode(int key) {
    NodeT *newNode=(NodeT*)malloc(sizeof(NodeT));
    newNode->key=key;
    newNode->height=1;
    newNode->left=NULL;
    newNode->right=NULL;
    return newNode;
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
    if(root==NULL) {
        return 0;
    }
    return root->height;

}
NodeT * rotateRight(NodeT *root)
{
    NodeT* child=root->left;
    NodeT* grandchild=child->right;
    child->right=root;
    root->left=grandchild;
    root->height=getMax(getHeight(root->left),getHeight(root->right))+1;
    child->height=getMax(getHeight(child->left),getHeight(child->right))+1;
    return child;
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
int getBalance(NodeT *root)
{
    if(root==NULL)
        return 0;
    return getHeight(root->left)-getHeight(root->right);
}
NodeT * insert(NodeT*root, int key)
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
NodeT * getSuccessor(NodeT *root)
{
   NodeT* currentNode = root->right;

    while (currentNode->left != NULL && currentNode!=NULL)
        currentNode = currentNode->left;
    return currentNode;
}
NodeT *delete(NodeT *root, int key)
{
    if(root==NULL)
        return root;
    if(key<root->key)
    {
        root->left=delete(root->left,key);
    }else if(key>root->key)
    {
        root->right=delete(root->right,key);
    } else{
        if(root->left==NULL)
        {
            NodeT*temp=root->right;
            *root = *temp;
            free(temp);

        }else if(root->right==NULL)
        {
            NodeT *temp=root->left;
            *root = *temp;
            free(temp);

        }
        else {
            NodeT *temp = getSuccessor(root);
            root->key = temp->key;
            root->right = delete(root->right, temp->key);
        }
    }
    root->height =  getMax(getHeight(root->left),
                           getHeight(root->right))+1;
    int balance = getBalance(root);
    if (balance > 1 && getBalance(root->left) >= 0)
        return rotateRight(root);
    if (balance > 1 && getBalance(root->left) < 0)
    {
        root->left =  rotateLeft(root->left);
        return rotateRight(root);
    }
    if (balance < -1 && getBalance(root->right) <= 0)
        return rotateLeft(root);

    if (balance < -1 && getBalance(root->right) > 0)
    {
        root->right = rotateRight(root->right);
        return rotateLeft(root);
    }
    return root;
}
