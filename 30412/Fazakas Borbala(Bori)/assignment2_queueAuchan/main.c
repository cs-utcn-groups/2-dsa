#include <stdio.h>
#include <stdlib.h>
#include "list.h"

#define FILE_ERR_CODE 1
#define FILE_ERR_MESS "error opening file"

FILE *openFile(char *name, char *mode) {
    FILE *newFile = fopen(name, mode);
    if (newFile == NULL) {
        perror(FILE_ERR_MESS);
        exit(FILE_ERR_CODE);
    }
    return newFile;
}

int main() {
    FILE *inFile = openFile("input.dat", "r");
    FILE *outFile = openFile("output.dat", "w");

    return 0;
}