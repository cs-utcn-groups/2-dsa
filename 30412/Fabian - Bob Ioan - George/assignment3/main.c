#include "tree.h"

int main() {
    root=createTree();

    printT(root, 0);

    intializeList();

    createList(root);

    freeTree();

    printL();

    root= back();

    printT(root, 0);

    freeTree();

    return 0;
}