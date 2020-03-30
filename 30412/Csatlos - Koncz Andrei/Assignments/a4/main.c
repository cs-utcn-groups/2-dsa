#include <stdio.h>
#include "binary_tree.h"

int main()
{
    tree *root = NULL;

    root = Insert(root,10);
    root = Insert(root,8);
    root = Insert(root,14);
    root = Insert(root,9);
    root = Insert(root,4);
    root = Insert(root,1);
    root = Insert(root,6);
    root = Insert(root,2);
    root = Insert(root,0);
    root = Insert(root,7);

    PrettyPrint(root,0);
    return 0;
}