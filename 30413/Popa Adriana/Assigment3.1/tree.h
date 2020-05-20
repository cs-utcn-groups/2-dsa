#include <stdio.h>
#include <stdlib.h>

typedef struct node_type
{
    char id ;
    struct node_type *left, *right ;
} NodeT;

typedef struct node
{
    char id;
    struct node *next, *previous;
}NodeL;
NodeL *first, *last, *current;

NodeT *createBinTree(NodeT *parent,FILE *f);
NodeL *getListFromTree(NodeT *root);
NodeT *getTreeFromList();
void fatalError( const char *msg );
void prettyPrint( NodeT *p, int level );
void traverseList(NodeL *fisrt);
