#include <stdio.h>
#include "tree.h"

int main() {
    tree *root = NULL;
    root = balancedInsert(root, 10);
    root = balancedInsert(root, 20);
    root = balancedInsert(root, 30);
    root = balancedInsert(root, 40);
    root = balancedInsert(root, 50);
    root = balancedInsert(root, 25);
    root = balancedDelete(root, 20);
    root = balancedDelete(root, 40);
    root = balancedDelete(root, 30);
    printTree(root, 0);
    return 0;
}
