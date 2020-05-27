#include"treeAVL.h"

int main()
{
    NodeAVL *root = NULL;
    root = insert(root, 9);
    root = insert(root, 5);
    root = insert(root, 10);
    root = insert(root, 0);
    root = insert(root, 6);
    root = insert(root, 11);
    root = insert(root, -1);
    root = insert(root, 1);
    root = insert(root, 2);

    printf("Preorder traversal of the constructed AVL "
           "tree is \n");
    prettyPrint(root,0);

    root = delete(root, 10);
    printf("The AVL Tree after deletion of 10 node is \n");

    prettyPrint(root,0);

    return 0;
}
