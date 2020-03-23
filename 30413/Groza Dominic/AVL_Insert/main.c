#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int key;
    struct node *left, *right;
    int height;
} NodeT;

int height(NodeT *p){
    if (p==NULL)return 0;
    return p->height;
}

int max(int a, int b) {
    return (a > b)? a : b;
}

int balanceOfNode(NodeT *p) {
    if (p == NULL)
        return 0;
    return height(p->left) - height(p->right);
}

NodeT *createNode(int key) {
    NodeT *p = (NodeT *) malloc(sizeof(NodeT));
    if (p) {
        p->key = key;
        p->right = NULL;
        p->left = NULL;
        p->height = 1; //since new node is initially a leaf
    }
    return p;
}



NodeT *rotateRight(NodeT *p) {
    NodeT *temp = p->left;
    NodeT *rightST = temp->right;

    temp->right = p; //rotating...
    p->left = rightST;

    p->height = max(height(p->left), height(p->right)) + 1; //update heights
    temp->height = max(height(temp->left), height(temp->right)) + 1;
    return temp;
}

NodeT *rotateLeft(NodeT *p) {
    NodeT *temp = p->right;
    NodeT *leftST = temp->left;

    p->right = leftST;
    temp->left = p;

    p->height = max(height(p->left), height(p->right)) + 1; //update heights
    temp->height = max(height(temp->left), height(temp->right)) + 1;

    return temp;
}

NodeT *insertNode(NodeT *p, int key) {
    if (p == NULL)
        return (createNode(key));
    if (key < p->key)
        p->left = insertNode(p->left, key);
    else if (key > p->key)
        p->right = insertNode(p->right, key);
    else return p;

    p->height = max(height(p->left),height(p->right))+1;

    int balance = balanceOfNode(p);

    //left left
    if (balance > 1 && key < p->left->key)
        return rotateRight(p);

    //right right
    if (balance < -1 && key > p->right->key)
        return rotateLeft(p);

    //left right
    if (balance > 1 && key > p->left->key) {
        p->left = rotateLeft(p->left);
        return rotateRight(p);
    }

    //right left
    if (balance < -1 && key < p->right->key) {
        p->right = rotateRight(p->right);
        return rotateLeft(p);
    }
    return p;
}

void preorder (NodeT *p, int level) {
    if (p != NULL) {
        for (int i = 0; i <= level; i++)
            printf(" "); //for nice listing
        printf("%2.2d\n", p->key);
        preorder(p->left, level + 1);
        preorder(p->right, level + 1);
    }
}

int main() {
    printf("Hello, World!\n");
    NodeT *root = NULL;
    int n;
    printf("How many elements do you want to insert into this wonderful tree?");
    scanf ("%d",&n);
    int j;
    for (int i=0;i<n;i++){
        printf("\nEnter element nr %d =  ",i+1);
        scanf("%d",&j);
        root=insertNode(root,j);
        j=0;
    }
    printf ("Tree is: \n");
    preorder(root,0);
    return 0;
}
