#include <stdio.h>
#include "node.h"
#include "list.h"

int main() {
    TreeNode *root = readBinaryTree();
    List *myList = initializeList();
    createDLListFromTree(root, myList);
    printDLList(myList);
    TreeNode *newRoot = createTreeFromList(myList->first);
    printPretty(newRoot, 0);
    return 0;
}