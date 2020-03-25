#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data, height;
    struct node *left, *right;
} NodeT;

NodeT *newNode(int key);
int height(NodeT *node);
int getBalance(NodeT *node);
int max(int x, int y);
NodeT *rotateRight(NodeT *z);
NodeT *rotateLeft(NodeT *z);
NodeT *insertNode(NodeT *node,int key);
NodeT *preorder(NodeT *node, int level, FILE *g);
void createPBBST(FILE *f, FILE *g);
NodeT *findNode(NodeT *node,int key);
NodeT *getMin(NodeT *node);
NodeT *deleteNode(NodeT *node, int key);
void deleteNodesInPBBST(FILE *g);
