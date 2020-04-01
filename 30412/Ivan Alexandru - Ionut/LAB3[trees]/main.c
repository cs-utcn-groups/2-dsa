#include <stdio.h>
#include <stdlib.h>
#include "func.h"

int main() {
    f = fopen("../dataIn.txt", "r");
    if(f == NULL)
    {
        perror("FILE NAH");
    }
    NodeT *root = createBinTree();
    head = NULL;    createListFromTree(root, &head);
    traverse(head);
    root = createTreeFromList(sizeOfDll(head));
    prettyPrint(root, 0);
}