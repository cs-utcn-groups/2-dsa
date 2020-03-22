#include <stdio.h>
#include <stdlib.h>

typedef struct _TREE {
    char Key;
    int Height;
    struct _TREE* Left;
    struct _TREE* Right;
}TREE;

void InitializeTree(TREE **Tree);
void InsertTree(TREE **Tree, char Key);
void Preorder(TREE *Node, FILE *g);
