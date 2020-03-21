#include <stdio.h>
#include <stdlib.h>

typedef struct vertex
{
    int id;
    struct vertex *left, *right;
}vertexT;

typedef struct node
{
    int id;
    struct node *next;
}nodeT;

void prettyPrint(vertexT *pVertex, int i);
vertexT *getTreeFromList(nodeT *t);
void traverseList(nodeT *t);
nodeT *getListFromTree(vertexT *pVertex);
vertexT *createBinTree();

int main()
{
    vertexT *root = createBinTree();
    nodeT * firstFromList = getListFromTree(root);
    traverseList(firstFromList);
    root = getTreeFromList(firstFromList);
    prettyPrint(root, 0);

    return 0;
}

vertexT *createBinTree()
{
    return NULL;
}

nodeT *getListFromTree(vertexT *pVertex)
{
    return NULL;
}

void traverseList(nodeT *t)
{

}

vertexT *getTreeFromList(nodeT *t)
{
    return NULL;
}

void prettyPrint(vertexT *pVertex, int i)
{

}

