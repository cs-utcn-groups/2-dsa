#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct node_type
{
    int id;
    struct node_type *left, *right;
} NodeT;

void preorder(NodeT *p, int level);
void inorder (NodeT *p, int level);
void postorder(NodeT *p, int level);
void fatalError(const char *msg);
NodeT *createBinTree(int branch, NodeT *parent,FILE *f);
bool ifNodeExists(NodeT *node, int data);
void swapTree(NodeT *node);
int searchNodeForAddress(NodeT *node, int data);
int findHeight(NodeT *node);
int nrOfLeaves(NodeT *node);

