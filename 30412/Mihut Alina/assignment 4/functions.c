//
// Created by Alina Mihut on 3/29/20.
//
#include "header.h"

int height(NodeT *current)
{
    if (current==NULL)
        return 0;
    return current->height;
}

NodeT *createNewNode (int key)
{
    NodeT *n= (NodeT*) malloc (sizeof(NodeT));
    n->key=key;
    n->left=NULL;
    n->right = NULL;
    n->height=1;
    return n;
}
int max(int a, int b)
{
    if (a>b) return a;
    else return b;
}

int getBalance (NodeT *node)
{
    if(node==NULL) return 0;
    return height(node->left)-height(node->right);
}

NodeT *rightRotate (NodeT *node)
{
    NodeT *n1=node->left;
    NodeT *n2=n1->right;

    n1->right=node;
    node->left=n2;


    node->height=max(height(node->left),height(node->right))+1;
    n1->height=max(height(n1->left),height(n1->right))+1;
    return n1;
}
NodeT *leftRotate (NodeT *node)
{
    NodeT *n1=node->right;
    NodeT *n2=n1->left;

    n1->left=node;
    node->right=n2;


    node->height=max(height(node->left),height(node->right))+1;
    n1->height=max(height(n1->left),height(n1->right))+1;
    return n1;
}

NodeT *insert (NodeT *node, int key)
{

    if (node==NULL)
        return createNewNode(key);
    if(key< node->key)
        node->left=insert(node->left, key);
    else if(key> node->key)
        node->right=insert(node->right, key);
    else {
        printf("Key %d already exists! \n", key);
        return node;
    }
    node=balanceTree(node, key);
    return node;
}

NodeT *getSuccessor (NodeT *node)
{
    NodeT *current=node->right;
    while (current!=NULL && current->left!=NULL)
    {
        current=current->left;
    }
    return current;
}

NodeT *delete (NodeT *root, int key){
    if(root==NULL)
        return root;

    if (key<root->key)
    { root->left=delete(root->left, key);}
    else if (key>root->key)
        root->right=delete (root->right, key);

    else{
        if(root->left==NULL){
            NodeT *temp=root->right;
            free(root);
            return temp;
        }
        else if(root->right==NULL){
            NodeT *temp=root->left;
            free(root);
            return temp;
        }
        else {
            NodeT *temp = getSuccessor(root);
            root->key = temp->key;
            root->right = delete(root->right, temp->key);
        }
    root= balanceTree(root, key);
   return root;
    }
}



NodeT *balanceTree(NodeT *node,int key) {
    node->height = 1 + max(height(node->left), height(node->right));

    int balance = getBalance(node);

    if (balance > 1 && key < node->left->key)
        node = rightRotate(node);

    if (balance < -1 && key > node->right->key)
        node = leftRotate(node);

    if (balance > 1 && key > node->left->key) {
        node->left = leftRotate(node->left);
        node = rightRotate(node);
    }

    if (balance < -1 && key < node->right->key) {
        node->right = rightRotate(node->right);
        node = leftRotate(node);
    }
    return node;
}

void prettyPrint (NodeT *root, int space){
    if (root==NULL)
        return;
    space +=COUNT;
    prettyPrint (root->right, space);
    printf ("\n");
    for (int i=COUNT;i<space;i++)
        printf(" ");

    printf("%d", root->key);
    prettyPrint(root->left, space);
}








