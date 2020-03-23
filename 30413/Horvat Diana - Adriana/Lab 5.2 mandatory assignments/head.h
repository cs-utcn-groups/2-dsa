#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node
{
    char data;
    struct node *left, *right;
} NodeT;

NodeT *newNode(char c);
NodeT *getMin(NodeT *node);
NodeT *deleteNode(NodeT *node, char c);
NodeT *findNode(NodeT *node, char c);
NodeT *preorder(NodeT *node, int level);
NodeT *inorder(NodeT *node, int level);
NodeT *postorder(NodeT *node, int level);
NodeT *getMax(NodeT *node);
NodeT *insertNode(NodeT *node, char c);
void readFile(FILE *f);

