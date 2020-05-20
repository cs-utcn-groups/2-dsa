#include <stdio.h>
#include <stdlib.h>


typedef struct node
{
    char id;
    struct node *left, *right;
} NodeT;

typedef struct nd

{
    char idd;
    struct nd *next, *previous;
} NdT;

NdT *first, *last, *currentN;

void initializeList();
void fatalError( const char *msg );
NodeT *createBinTree( NodeT *parent,FILE *f );
NodeT *TreeList();
void createList(char i);
NdT *ListTree(NodeT *root);
void printList(NdT *first);
void preorder( NodeT *p, int level);
