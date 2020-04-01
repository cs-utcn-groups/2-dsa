
#include <stdio.h>
#include "header.h"
#include <stdlib.h>
#include <string.h>
#define MAX_LINE 100

int main() {

    FILE *f;
    f = fopen("../in.dat", "r");

    FILE *g;
    g = fopen("../out.dat", "w");

    NodeS *binaryTree = buildTree(f);
    preorder(binaryTree, 0);
}
