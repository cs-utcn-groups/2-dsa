#include "tree.h"
#include "list.h"

int main() {
    NodeT *root = createBinTree();
    NodeL *firstFromList = getListFromTree(root);
    traverseList(firstFromList);
    root = getTreeFromList(&firstFromList);
    prettyPrint(root, 0);
    return 0;
}