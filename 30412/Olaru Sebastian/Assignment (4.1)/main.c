#include "treeAVL.h"

int main()
{
    NodeAVL *root = NULL;

    root = insert(root, 10);
    root = insert(root, 3);
    root = insert(root, 23);
    root = insert(root, 4);
    root = insert(root, 9);
    root = insert(root, 19);
    root = insert(root, 46);
    root = insert(root, 16);
    root = insert(root, 25);
    root = insert(root, 32);

    prettyPrint(root,0);

    return 0;
}
