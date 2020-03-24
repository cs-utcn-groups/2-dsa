#include <stdio.h>
#include "head.h"

int main() {
    NodeT *root = createBinaryTree();
    initializeList();
    NodeL *firstFromList = getListFromTree(root);
    traverseList();
    root = getTreeFromList(firstFromList);
    prettyPrint(root, 0);
    return 0;
}