#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node_type
{
    int data;
    struct node_type *left, *right;
} NodeT;
NodeT *root;

typedef struct node
{
    int value;
    char *leaves;
    struct node *prev, *next;
} NodeL;

NodeT *createBinTree(int branch, NodeT *parent, FILE *f);
NodeL *getListFromTree(NodeT *node);
void traverseList(NodeL *firstFromList);
NodeT *getTreeFromList(NodeL *firstFromList);
void prettyPrint(NodeT *node,int level);
