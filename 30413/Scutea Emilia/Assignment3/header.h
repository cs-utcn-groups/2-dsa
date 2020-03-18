#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct node
{
    char label;
    struct node * left, * right;
} NodeT,NodeL;
NodeL * first, * last;
NodeT * createBinTree();
void initializeList();
void addInList(char data);
NodeL * getListFromTree(NodeT * p);
void traverseList(NodeL * p);
NodeT * getTreeFromList(NodeL * p);
void prettyPrint(NodeT * p,int level);

