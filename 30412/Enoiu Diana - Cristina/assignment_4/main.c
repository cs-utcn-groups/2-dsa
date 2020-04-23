#include <stdio.h>
#include "head.h"

int main () {
    FILE * out;
    out = fopen("../out.txt","a");
    NodeT *root = createNode(10);
    insertNode(root, 1);
    insertNode(root, 19);
    insertNode(root, 5);
    insertNode(root, 8);
    insertNode(root, 99);
    insertNode(root, 4);
    insertNode(root, 3);
    insertNode(root, 3);
    insertNode(root, 2);
    insertNode(root, 1);
    insertNode(root, 0);
    prettyPrint(root, 0, out);
    fprintf(out,"\n");
    deleteNode(root,4);
    prettyPrint(root,0,out);
    fprintf(out,"\n");
    return 0;
}
