#include <stdio.h>
#include "node.h"

int main() {
    Node *root  = NULL;

    root = insertNode(root, 1);
    root = insertNode(root, 2);
    root = insertNode(root, 3);
    root = insertNode(root, 4);
    root = insertNode(root, 5);
    root = insertNode(root, 6);
    root = insertNode(root, 7);
    root = insertNode(root, 8);
    root = insertNode(root, 9);
    root = insertNode(root, 10);
    root = insertNode(root, 11);

    printTree(root, 0);

    return 0;
}