#include <stdio.h>
#include "binary_tree.h"

int main()
{
    tree *root = CreateBinaryTree();
    dll_tree *dllRoot = GetListFromTree(root, NULL);

    printf("Root id: %c\n",root->id);
    PrettyPrint(root,0);

    printf("Root id: %c\n",dllRoot->id);
    PrettyPrintDLL(dllRoot,0);

    return 0;
}