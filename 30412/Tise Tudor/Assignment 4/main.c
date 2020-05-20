#include <stdio.h>
#include <stdlib.h>

#define COUNT 2

typedef struct node{
    int key;
    struct node *left, *right;
    int height;
} NodeT;

NodeT *createNode(int key);
void prettyPrint(NodeT *root, int space);
int height(NodeT *currentNode);
int findBalance(NodeT *currentNode);
int findMax(int a, int b);
NodeT *rightRotate(NodeT *y);
NodeT *leftRotate(NodeT *x);
NodeT* insert(NodeT* node, int key);


int main() {
    NodeT *root = createNode(10);

    root = insert(root, 5);
    root = insert(root, 4);
    root = insert(root, 3);
    root = insert(root, 2);
    root = insert(root, 1);
    prettyPrint(root,0);

    return 0;
}


NodeT *createNode(int key) {
    NodeT *node = (NodeT *) malloc(sizeof(NodeT));
    node->left = NULL;
    node->right = NULL;
    node->key = key;
    node->height = 1;
    return node;
}

void prettyPrint(NodeT *root, int space) {
    {
        if (root == NULL) {
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

int height(NodeT *currentNode){
    if (currentNode == NULL){
        return 0;
    }
    return currentNode->height;
}

int findBalance(NodeT *currentNode)
{
    if (currentNode == NULL)
        return 0;
    return height(currentNode->left) - height(currentNode->right);
}

int findMax(int a, int b)
{
    if (a > b)
        return a;
    else
        return b;
}

NodeT *rightRotate(NodeT *y)
{
    NodeT *x = y->left;
    NodeT *T2 = x->right;

    //rotations
    x->right = y;
    y->left = T2;

    // change heights
    y->height = findMax(height(y->left), height(y->right))+1;
    x->height = findMax(height(x->left), height(x->right))+1;

    return x;
}

NodeT *leftRotate(NodeT *x)
{
    NodeT *y = x->right;
    NodeT *T2 = y->left;

    //rotations
    y->left = x;
    x->right = T2;

    // change heights
    x->height = findMax(height(x->left), height(x->right))+1;
    y->height = findMax(height(y->left), height(y->right))+1;

    return y;
}

NodeT* insert(NodeT* node, int key)
{
    if (node == NULL)
        return(createNode(key));

    if (key < node->key)
        node->left  = insert(node->left, key);
    else if (key > node->key)
        node->right = insert(node->right, key);
    else
        return node;

    node->height = 1 + findMax(height(node->left),
                           height(node->right));

    int balance = findBalance(node);


    // Left Left Case
    if (balance > 1 && key < node->left->key)
        return rightRotate(node);

    // Right Right Case
    if (balance < -1 && key > node->right->key)
        return leftRotate(node);

    // Left Right Case
    if (balance > 1 && key > node->left->key)
    {
        node->left =  leftRotate(node->left);
        return rightRotate(node);
    }

    // Right Left Case
    if (balance < -1 && key < node->right->key)
    {
        node->right = rightRotate(node->right);
        return leftRotate(node);
    }

    return node;
}