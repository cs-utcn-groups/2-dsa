#include "head.h"

int main() {

    NodeT * root = createNode(10);
    insertNode(root, 3);
    insertNode(root, 4);
    insertNode(root, 9);
    insertNode(root, 15);
    insertNode(root, 5);
    insertNode(root, 20);
    insertNode(root, 14);
    insertNode(root, 16);
    insertNode(root, 50);
    insertNode(root, 31);
    prettyPrint(root, 0);
    return 0;
}