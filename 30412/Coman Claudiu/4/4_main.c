#include "head.h"

NodeT *createNode(int key){
    NodeT *node = (NodeT*)malloc(sizeof(NodeT));
    node->key = key;
    node->left = NULL;
    node->right = NULL;
    node->height = 1;
    return (node);
}

int max(int a, int b){
    return (a > b)? a : b;
}

int height(NodeT *node){
    if(node == NULL){
        return 0;
    }
    return node->height;
}

int getBalance(NodeT *node){
    if(node == NULL){
        return 0;
    }
    return height(node->left) - height(node->right);
}

void preOrder(NodeT *root){
    if (root != NULL){
        printf("%d ", root->key);
        preOrder(root->left);
        preOrder(root->right);
    }
}

NodeT *rightRotate(NodeT *y){
    NodeT *x = y->left;
    NodeT *T2 = x->right;

    x->right = y;
    y->left = T2;

    y->height = max(height(y->left), height(y->right)) + 1;
    x->height = max(height(x->left), height(x->right)) + 1;

    return x;
}

NodeT *leftRotate(NodeT *x){
    NodeT *y = x->right;
    NodeT *T2 = y->left;

    y->left = x;
    x->right = T2;

    x->height = max(height(x->left), height(x->right)) + 1;
    y->height = max(height(y->left), height(y->right)) + 1;

    return y;
}

NodeT *insert(NodeT *node, int key){
    if(node == NULL){
        return (createNode(key));
    }
    if(key < node->key){
        node->left = insert(node->left, key);
    }
    else if(key > node->key){
        node->right = insert(node->right, key);
    }
    else
        return node;

    node->height = max(height(node->left),height(node->right)) + 1;

    int balance = getBalance(node);

    //Left Left case
    if(balance > 1 && key < node->left->key){
       return rightRotate(node);
    }
    // Right Right case
    if(balance < -1 && key > node->right->key){
        return leftRotate(node);
    }
    //Left Right case
    if(balance > 1 && key > node->left->key){
        node->left = leftRotate(node->left);
        return rightRotate(node);
    }
    // Right Left case
    if(balance < -1 && key < node->right->key){
        node->right = rightRotate(node->right);
        return leftRotate(node);
    }
    return node;
}

int main() {
    NodeT *root = NULL;
    root = insert(root, 10);
    root = insert(root, 20);
    root = insert(root, 30);
    root = insert(root, 40);
    root = insert(root, 50);
    root = insert(root, 25);

    printf("Preorder traversal of the constructed AVL tree is \n");
    preOrder(root);

    return 0;
}
