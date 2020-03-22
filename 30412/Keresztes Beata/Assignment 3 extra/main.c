#include <stdio.h>
#include "tree.h"
#define INPUT_FILE_NAME "../in.dat"
#define ERR_OPEN_FILE "Error opening file"

FILE * openFile(char * name, char * mode);

int main() {

    FILE * fIn = openFile(INPUT_FILE_NAME,"r");

    NodeT * sentinel = createSentinel();
    int depth = enQueue(fIn, sentinel);

    fclose(fIn);

    NodeT * root = createTree(sentinel);
    printTree(root,depth);

    freeTree(&root);
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