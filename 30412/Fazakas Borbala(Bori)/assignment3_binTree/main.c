#include <stdio.h>
#include "binTree.h"
#include "list.h"


int main() {
    binTree *originalTree = createBinTree(stdin);
    inOrder(originalTree, 0, stdout);
    dlList myList = getListFromTree(originalTree);
    printAll(&myList, stdout);
    binTree *newTree = getBinTreeFromList(&myList);
    inOrder(newTree, 0, stdout);
    return 0;
}