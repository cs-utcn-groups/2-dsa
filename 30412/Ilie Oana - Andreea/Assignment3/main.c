#include <stdio.h>
#include <stdlib.h>
#include "tree.h"
#include "dll.h"

#define INPUT_FILE_PATH "../input.dat"
#define OUTPUT_FILE_PATH "../output.dat"

int main() {
    FILE *inputFile = fopen(INPUT_FILE_PATH, "r");
    if (inputFile == NULL) {
        perror("Error open file");
        return (-1);
    }

    FILE *outputFile = fopen(OUTPUT_FILE_PATH, "w");

    nodeT *root = createBinaryTree(inputFile);
    fprintf(outputFile, "Initial Tree:\n");
    prettyPrint(root, 0, outputFile);
    fprintf(outputFile, "\n");

    getListFromTree(root);
    fprintf(outputFile, "Doubly-linked list:\n");
    traverseList(outputFile);
    fprintf(outputFile, "\n");

    root = getTreeFromList();
    fprintf(outputFile, "New Tree:\n");
    prettyPrint(root, 0, outputFile);
    return 0;
}