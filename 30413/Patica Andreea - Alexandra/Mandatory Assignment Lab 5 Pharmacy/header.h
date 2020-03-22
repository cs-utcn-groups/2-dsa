#include <stdio.h>
#include <stdlib.h>

typedef struct _INFO
{
    char *Name;
    char *Price;
    char *Amount;
    char *DateOfManufacturing;
    char *DateOfExpiration;
}INFO;

typedef struct _TREE {
    INFO *Info;
    struct _TREE* Left;
    struct _TREE* Right;
}TREE;

void PrintTree(TREE *Tree, FILE *g);
void InitializeTree(TREE **Tree);
void InsertTree(TREE *Tree, FILE *f);
void DeleteFromTree(TREE *Tree, FILE *f);
void CreateExpired(TREE *NewTree, TREE *Tree, FILE *f);
void FindAndReplace(TREE *Tree, FILE *f, FILE *g);
