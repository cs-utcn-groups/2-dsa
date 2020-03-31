
#include "header.h"

int main() {

    NodeT *root = NULL;

    root = insert(root, 15);
    root = insert(root, 13);
    root = insert(root, 9);
    root = insert(root, 1);
    root = insert(root, 6);
    root = insert(root, 5);

    preorder(root, 0);

}

