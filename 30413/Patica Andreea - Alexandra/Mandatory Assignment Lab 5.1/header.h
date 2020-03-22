#include <stdio.h>
#include <stdlib.h>

typedef struct _TREE {
    char Key;
    struct _TREE* Left;
    struct _TREE* Right;
}TREE;

void InitializeTree(TREE **Tree);
char GetExtremum(TREE *Tree, char Mode);
void InsertTree(TREE *Tree, char Key);
void DeleteFromTree(TREE *Tree, char Key);
void Find(TREE *Tree, char Key, FILE *g);
void Transversal(TREE *Tree, char Mode, FILE *g);
