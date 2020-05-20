#include <stdio.h>
#include <stdlib.h>

typedef struct NodeT
{
    int info;
    struct NodeT *left;
    struct NodeT *right;
    int height;
} NodeT;

NodeT* insertNode(NodeT* node, int key);
void preOrder(NodeT * root);
int getHeight(NodeT * node);
NodeT *rotRight(NodeT *y);
NodeT *rotLeft( NodeT *x);
int getBalance(NodeT *node);
