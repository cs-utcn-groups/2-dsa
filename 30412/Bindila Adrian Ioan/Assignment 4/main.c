#include <stdio.h>
#include "tree.h"

int main() {
    tree *root = NULL;
    root = balancedInsert(root, 11);
    root = balancedInsert(root, 24);
    root = balancedInsert(root, 2.4);
    root = balancedInsert(root, 46);
    root = balancedInsert(root, 5.6);
    root = balancedInsert(root, 2.5);
    root = balancedInsert(root, 9.6);
    root = balancedInsert(root, 2.67);
    root = balancedInsert(root, 3.67);
    root = balancedInsert(root, 4.67);
    root = balancedInsert(root, 5.67);
    root = balancedInsert(root, 6.67);
    printTree(root, 0);
    return 0;
}
