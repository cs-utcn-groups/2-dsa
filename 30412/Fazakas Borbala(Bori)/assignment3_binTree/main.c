#include <stdio.h>
#include "binTree.h"
#include "list.h"


int main() {
    binTree *originalTree = createBinTree(stdin);
    printf("original tree:\n");
    inOrder(originalTree, 0, stdout);
    dlList myList = getListFromTree(originalTree);
    printf("list from tree:\n");
    printAll(&myList, stdout);
    binTree *newTree = getBinTreeFromList(&myList);
    printf("tree from list:\n");
    inOrder(newTree, 0, stdout);
    return 0;
}