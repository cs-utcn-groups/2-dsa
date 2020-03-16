#include <stdio.h>
#include <stdlib.h>

typedef struct node_type
{
    char id ;
    struct node_type *left, *right ;
} NodeT;

NodeT *createBinTree(int branch,NodeT *parent,FILE *f);
void fatalError(const char *msg);
void inorder(NodeT *p,int level);
void preorder(NodeT *p,int level);
void postorder(NodeT *p,int level);
void interchange(NodeT *p,int x);
int determineHigh(NodeT *p);
int determineNumberLeaves(NodeT *p);
