#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int id;
    struct node *left, *right;
} nodeT;

void preorder( nodeT *p, int level );
void inorder( nodeT *p, int level );
void postorder( nodeT *p, int level );
int findHeightTree(nodeT *currentNode);
int findNrLeaves(nodeT *currentNode);
nodeT *findFinalNode(nodeT *root);
nodeT *findNodeInTree(nodeT *currentNode, int number);
void interchangeSubtrees(nodeT *ourNode);
