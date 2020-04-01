#include <stdio.h>
#include "header.h"
#include <stdlib.h>

int main() {

    doublyLinked *list;
    initialiseList(list);


    FILE *g;
    g = fopen("../out.dat", "w");


    NodeS *root = createBinaryTree();
    getListFromTree(root, 0, list);
    printAll(list,  g);
    root = traverseList(&list->sentinel->next);
    preorder(root, 0);

    return 0;
}
