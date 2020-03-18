#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct NodeT
{
    char id;
    struct NodeT *left, *right, *parent;
    bool visited;
} NodeT;

typedef struct NodeL
{
    struct Node *first, *last;
} NodeL;

typedef struct Node
{
    char id;
    struct Node *next,*previous;
} Node;

Node * first,*last,*element;

void addElementToEnd(int data);
void addToEnd(NodeL ** sentinel, char data);
NodeT * createBinTree();
NodeT * addParentsToBinaryTree(NodeT * element, NodeT * parent, NodeL ** sentinel);
NodeL * getListFromTree(NodeT * root);
void traverseList(NodeL * sentinel);
NodeT * createBinTreeFromList();
NodeT * getTreeFromList(NodeL * sentinel);
void prettyPrint(NodeT *p,int level);
