#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "header.h"
int main()
{
    NodeT * root=createBinTree();
    NodeL * firstFromList=getListFromTree(root);
    traverseList(firstFromList);
    root=getTreeFromList(firstFromList);
    prettyPrint(root,0);
}
