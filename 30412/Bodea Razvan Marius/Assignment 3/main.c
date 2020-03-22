#include <stdio.h>
#include "Head.h"

int main() {
    initializeList();
    NodeT *root = createBinaryTree();
    NodeL *firstFromList = getListFromTree(root);
    printf("List from tree:\n");
    traverseList(firstFromList);
    root = getTreeFromList();
    printf("Tree from list:\n");
    prettyPrint(root, 0);
    return 0;
}