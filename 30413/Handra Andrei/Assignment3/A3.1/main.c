#include "head.h"

int main()
{
    Initialize_DLL();
    NodeT * root= createBinTree();
    NodeL * firstFromList =ListFromTree(root);
    TraverseList(firstFromList);
    root=TreeFromList();
    prettyPrint(root,0);
    return 0;
}
