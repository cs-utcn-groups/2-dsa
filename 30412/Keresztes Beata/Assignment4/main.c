#include <stdio.h>

#include "delete.h"

#define INPUT_FILE_NAME "../in.dat"
#define ERR_OPEN_FILE "Error opening file"

FILE * openFile(char * name, char * mode);

int main() {

    FILE * inFile = openFile(INPUT_FILE_NAME,"r");
    // create BST
    BSTNodeT * rootBST = constructBST(inFile);
    // close input file
    fclose(inFile);
    // print BST
    printBST(rootBST,0);
    // find node by key
    printFound(rootBST,4);
    // delete node by key
    rootBST = deleteNode(rootBST, 8);
    // free BST
    freeBST(rootBST);
    return 0;
}

FILE * openFile(char * name, char * mode) {
    // function that opens a file, and returns a pointer to that file
    FILE *fp = fopen(name, mode);
    if (fp == NULL) {
    perror(ERR_OPEN_FILE);
    exit(EXIT_FAILURE);
    }
    return fp;
}