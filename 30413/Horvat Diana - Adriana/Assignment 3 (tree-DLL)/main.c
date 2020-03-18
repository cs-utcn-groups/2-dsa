#include "head.h"

int main()
{
    FILE *f=fopen("input.in","r"); //ca sa fie mai usoara testarea am adaugat un fisier in plus pe langa ceea ce se cerea sa fie in main

    NodeT *root=createBinTree(0,NULL,f);
    NodeL *firstFromList=getListFromTree(root);
    traverseList(firstFromList);
    root=getTreeFromList(firstFromList);
    prettyPrint(root,0);

    return 0;
}
