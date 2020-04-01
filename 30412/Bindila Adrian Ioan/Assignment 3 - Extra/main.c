#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tree.h"

int main() {
    ///did not use the queue, as I found a simpler fix
    ///if the queue needs to be used, tell me and i will have it done
    tree *root = createBinaryTree();
    printTree(root,0);
    return 0;
}
