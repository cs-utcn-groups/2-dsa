#include "nodes.h"

int main() {
    root=createTree();
    printTree(root,0);
    printf("\n");
    intializeList();
    createList(root);
    freeTree();
    printList();
    root=goBack();
    printTree(root,0);
    freeTree();
    return 0;
}