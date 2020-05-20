#include <stdio.h>
#include <stdlib.h>

typedef struct treeStruct
{
    char key;
    struct treeStruct * left, * right;
}treeStruct;

treeStruct * root;

treeStruct * insertKey(treeStruct * root,char key);
treeStruct * createNode(char key);
void preOrder(treeStruct * node);
void inOrder(treeStruct * node);
void postOrder(treeStruct * node);
treeStruct * deleteNode(treeStruct * node, char key);
treeStruct * findd(treeStruct * root,char key);
treeStruct * findMin(treeStruct * node );
treeStruct * findMax(treeStruct * node);
void read(FILE * f);
