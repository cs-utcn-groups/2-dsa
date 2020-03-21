#include "head.h"
int main()
{
    NodeT *root=createBinTree();
    NodeL *first=getListFromT(root);
    traverseList(first);
    root=getTreeFromList(first);
    prettyPrint(root,0);
    return 0;
}
