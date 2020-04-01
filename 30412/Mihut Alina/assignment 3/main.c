#include <stdio.h>
#include "tree.h"
#include "dll.h"
#include "other_functions.h"
int main() {

    FILE *fin;
    fin=fopen("../date.in","r");
    if (fin==NULL)
        perror ("File couldn't be opened");

    NodeT *root=createBinTree();
    NodeL *firstFromList=getListFromTree(root);
    transverseList(firstFromList);
    root=getTreeFromList(firstFromList);
    prettyPrint (root,0);
    return 0;
}
