#include "tree.h"

int main()
{
    FILE *f=fopen("input.dat","r");
    NodeT *root=createBinTree(NULL,f);
    initializeList();
    NodeL *firstFromList=getListFromTree(root);
    traverseList(firstFromList);
    root=getTreeFromList();
    prettyPrint(root,0);
    return 0;
}
