#ifndef ASSIGNMENT_4_1_AVL_H
#define ASSIGNMENT_4_1_AVL_H

typedef struct node
{
    int key;
    struct node *left;
    struct node *right;
    int height;
}NodeT;

int height(struct node *N);
int max(int a, int b);
NodeT *newNode(int key);
NodeT *rightRotate(NodeT *root);
NodeT *leftRotate( NodeT *root);
int getBalance(NodeT *root);
NodeT *insert(NodeT * root, int key);



#endif //ASSIGNMENT_4_1_AVL_H
