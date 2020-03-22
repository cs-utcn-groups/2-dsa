#include <stdio.h>
#include "tree.h"
#define ERR_OPEN_FILE "Error opening file"
#define INPUT_FILE_NAME "../input.dat"

FILE * openFile(char * name, char * mode);

int main() {

    FILE * fIn = openFile(INPUT_FILE_NAME,"r");

    NodeT * root = createBinTree(fIn);

    fclose(fIn);

    NodeT * sentinel= getListFromTree(root);
    traverseList(sentinel);
    root = getTreeFromList(sentinel);
    printPretty(root,0);

    return 0;
}

FILE * openFile(char * name, char * mode) {
    FILE * fp = fopen(name, mode);
    if(fp == NULL) {
        perror(ERR_OPEN_FILE);
        exit(EXIT_FAILURE);
    }
    return fp;
}