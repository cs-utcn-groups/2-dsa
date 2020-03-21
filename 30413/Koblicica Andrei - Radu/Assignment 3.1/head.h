#include <stdio.h>
#include <stdlib.h>

typedef struct treeNode
{
    char data;
    struct treeNode *left,*right;
}NodeT;

typedef struct listNode
{
    char data;
    int beenHere;
    struct listNode *next,*previous;
}NodeL;

NodeL *first,*last,*currentElement;


NodeT *createBinTree();
NodeL *getListFromT(NodeT *root);
void traverseList(NodeL *first);
NodeT *getTreeFromList(NodeL *first);
void prettyPrint(NodeT *root,int level);





