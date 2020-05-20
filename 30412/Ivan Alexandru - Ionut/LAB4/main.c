#include <stdio.h>
#include <stdlib.h>
#include "node.h"

int main() {
    struct Node *root = NULL;

    root = insert(root, 1);
    root = insert(root, 2);
    root = insert(root, 3);
    root = insert(root, 7);
    root = insert(root, 6);
    root = insert(root, 4);

    printf("Preorder traversal of the constructed AVL tree is \n");
    preord(root);

    return 0;
}