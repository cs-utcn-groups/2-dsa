#include "Tree.h"

int main() {
    NodeT *root = createNode(10);
    root = insertNode(root, 6);
    root = insertNode(root, 7);
    root = insertNode(root, 11);
    root = insertNode(root, 21);
    root = insertNode(root, 3);
    root = insertNode(root, 8);
    root = insertNode(root, 34);
    root = insertNode(root, 1);

    root = deleteNode(root, 6);
    root = deleteNode(root, 1);
    root = deleteNode(root, 10);
    root = deleteNode(root, 7);
    prettyPrint(root, 0);
    return 0;
}

