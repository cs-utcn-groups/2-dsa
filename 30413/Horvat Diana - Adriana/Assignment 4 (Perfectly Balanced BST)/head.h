#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data,height;
    struct node *left, *right;
} NodeT;

NodeT *newNode(int key);
int height(NodeT *node);
int max(int x, int y);
NodeT *rightRotate(NodeT *z);
NodeT *leftRotate(NodeT *z);
NodeT *insertPBBST(NodeT *node,int key);
void createPBBST(FILE *f,FILE *g);
NodeT *preorder (NodeT *node, int level, FILE *g);
