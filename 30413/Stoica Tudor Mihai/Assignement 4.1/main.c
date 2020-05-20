#include "header.h"

int main()
{
    NodeT *root = NULL;

    root = insertNode(root, 2312);
    root = insertNode(root, 12);
    root = insertNode(root, 123);
    root = insertNode(root, 987);
    root = insertNode(root, 4);
    root = insertNode(root, 4);
    root = insertNode(root, 4);

    preOrder(root);

    return 0;
}
