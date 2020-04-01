
#include "list.h"
#include "tree.h"
#include "combined.h"


int main() {
    initList();
    tree *root = createBinaryTree();
    list *firstOfList = getListFromTree(root);
    traverseList(firstOfList);
    root = getTreeFromList(firstOfList);
    prettyPrint(root, 0);
    return 0;
}
