#include <stdio.h>
#include "tree.h"

#define OUTPUT_FILE_PATH "../output.dat"

int main() {
    FILE *outputFile = fopen(OUTPUT_FILE_PATH, "w");

    nodeT *root = NULL;
    root = insertNode(root, 10);
    root = insertNode(root, 20);
    root = insertNode(root, 30);
    root = insertNode(root, 40);
    root = insertNode(root, 50);
    root = insertNode(root, 25);
    prettyPrint(root, 0, outputFile);
    fprintf(outputFile, "\n");

    deleteNode(root, 10);
    prettyPrint(root, 0, outputFile);

    return 0;

}