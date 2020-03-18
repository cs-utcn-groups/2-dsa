#include<stdio.h>
#include<stdlib.h>

typedef struct Node1_type
{
    char id;
    struct Node1_type *left, *right;
}NodeT;

typedef struct Node2_type
{
    char id;
    struct Node2_type *next, *prev;
}NodeL;

NodeL *first,*last,*current;

void FatalError(const char *msg);
void Initialize_DLL();
NodeT *createBinTree();
void prettyPrint(NodeT *root,int level);
void AddtoNode(char ch);
NodeL *ListFromTree(NodeT *root);
void TraverseList(NodeL *first);
NodeT *TreeFromList();
