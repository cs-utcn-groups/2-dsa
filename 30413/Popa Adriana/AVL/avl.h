#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define LEFT 1
#define RIGHT 2

typedef struct node
{
    char  Key;
    int Height;
    struct node *Left, *Right;
} NodeT;


void initializeTree(NodeT **Tree);
NodeT *Insert(NodeT *Tree, char key);
void prettyPrint( NodeT *p, int level );

