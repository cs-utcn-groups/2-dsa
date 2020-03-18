#include <stdio.h>
#include <stdlib.h>
#include "headerlist.h"

int main()
{
    FILE*f=fopen("inputdata.txt","r+");
    initializeList();
    NodeT *root=createBinTree(NULL,f);
    NdT *fl=ListTree(root);
    printList(fl);
    root=TreeList();
    preorder(root,0);

    return 0;
}
