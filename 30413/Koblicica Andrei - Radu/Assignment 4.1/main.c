#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#define COUNT 2

typedef struct node
{
    struct node *left, *right;
    int key;
    int height;
} NodeT;

NodeT *createNode(int key)
{
    NodeT *node = (NodeT *) malloc(sizeof(NodeT));
    node->left = NULL;
    node->right = NULL;
    node->key = key;
    node->height=1;
    return node;
}

int max(int a, int b)
{
    if(a>b)
        return a;
    else
        return b;
}

int height(NodeT *node)
{
    if(node==NULL)
        return 0;
    return node->height;
}

int getBalance( NodeT *node)
{
    if(node==NULL)
        return 0;
    return height(node->left)-height(node->right);
}

NodeT *getSuccessor(NodeT *node)
{
    NodeT *current = node->right;
    while (current != NULL && current->left != NULL)
    {
        current = current->left;
    }
    return current;
}

bool find(NodeT *root, int key)
{
    if (root == NULL)
    {
        return false;
    }
    else
    {
        if (root->key == key)
        {
            return true;
        }
        else
        {
            if (key < root->key)
            {
                return find(root->left, key);
            }
            else
            {
                return find(root->right, key);
            }
        }
    }
}

void findWithPrint(NodeT *root, int key)
{
    printf(find(root, key) ? "Element %d found!\n" : "Element %d not found!\n", key);
}


NodeT *delete(NodeT *root, int key)
{
    if (root == NULL)
    {
        return root;
    }
    if (key < root->key)
    {
        root->left = delete(root->left, key);
    }
    else if (key > root->key)
    {
        root->right = delete(root->right, key);
    }
    else
    {
        if (root->left == NULL)
        {
            NodeT *temp = root->right;
            free(root);
            return temp;
        }
        else if (root->right == NULL)
        {
            NodeT *temp = root->left;
            free(root);
            return temp;
        }

        NodeT *temp = getSuccessor(root);
        root->key = temp->key;
        root->right = delete(root->right, temp->key);
    }
    return root;
}

NodeT *leftRotate(NodeT *current)
{
    NodeT *x=current->right;
    NodeT *y=x->left;

    x->left=current;
    current->right=y;

    current->height=max(height(current->left),height(current->right))+1;
    x->height=max(height(x->left),height(x->right))+1;
    return x;
}

NodeT *rightRotate(NodeT *current)
{
    NodeT *x=current->left;
    NodeT *y=x->right;

    x->right=current;
    current->left=y;

    current->height=max(height(current->left),height(current->right))+1;
    x->height=max(height(x->left),height(x->right))+1;
    return x;
}
NodeT *insertAndBalance(NodeT *root, int key)
{
    if(root==NULL)
        return createNode(key);
    if(key<root->key)
    {
        root->left=insertAndBalance(root->left,key);
    }
    else
    {
        if(key>root->key)
        {
            root->right=insertAndBalance(root->right,key);
        }
        else
        {
            printf("Key %d already in tree!", key);
            return NULL;
        }
    }

    root->height=1+max(height(root->left),height(root->right));
    int balance=getBalance(root);

    if(balance>1 && key<root->left->key)
        return rightRotate(root);
    if(balance<-1 && key>root->right->key)
        return leftRotate(root);
    if(balance>1 && key>root->left->key)
    {
        root->left=leftRotate(root->left);
        return rightRotate(root);
    }
    if(balance<-1 && key<root->right->key)
    {
        root->right=rightRotate(root->right);
        return leftRotate(root);
    }
    return root;

}
void prettyPrint(NodeT *root, int space)
{
    {
        if (root == NULL)
        {
            return;
        }
        space += COUNT;
        prettyPrint(root->right, space);
        printf("\n");
        for (int i = COUNT; i < space; i++)
            printf(" ");
        printf("%d", root->key);
        prettyPrint(root->left, space);
    }
}

int main()
{
    NodeT *root = NULL;
    root=insertAndBalance(root, 10);
    root=insertAndBalance(root, 20);
    root=insertAndBalance(root, 30);
    root=insertAndBalance(root, 40);
    root=insertAndBalance(root, 50);
    root=insertAndBalance(root, 25);
    prettyPrint(root, 0);
    printf("\n\n");

    findWithPrint(root, 30);
    findWithPrint(root, -4);
    findWithPrint(root, 25);
    printf("\n\n");

    delete(root, 30);
    prettyPrint(root, 0);

    return 0;
}
