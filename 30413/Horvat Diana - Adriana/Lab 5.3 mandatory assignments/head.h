#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

typedef struct node
{
    char *name;
    int price, amount, dateOfManufacturing, dateOfExpiration;
    struct node *left, *right;
} NodeT;

NodeT *newNode(char *s);
NodeT *insertNode(NodeT *node, char *s);
NodeT *getMin(NodeT *node);
NodeT *deleteNode(NodeT *node,char *s);
NodeT *updateNode(NodeT *node,char *s);
NodeT *preorder(NodeT *node, int level,FILE *g);
NodeT *newNode2(NodeT *nodeFirstTree);
NodeT *insertNode2(NodeT *node, NodeT *nodeFirstTree);
NodeT *expiredProducts(NodeT *node,int level);
void readFile(FILE *f, FILE *g);

