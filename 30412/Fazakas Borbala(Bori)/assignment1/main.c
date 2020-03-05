#include <stdio.h>
#include <stdlib.h>
#include "list.h"
#include <string.h>

#define FILE_ERR_CODE 1
#define FILE_ERR_MESS "error opening file"
#define MAX_COMMAND_LENGTH 15

FILE *openFile(char *name, char *mode) {
    FILE *newFile = fopen(name, mode);
    if (newFile == NULL) {
        perror(FILE_ERR_MESS);
        exit(FILE_ERR_CODE);
    }
    return newFile;
}


int main() {
    list myList = createList();
    char *command = (char *) malloc(sizeof(char) * MAX_COMMAND_LENGTH);
    int x;

    FILE *inFile = openFile("input.dat", "r");
    FILE *outFile = openFile("output.dat", "w");

    while (!feof(inFile)) {
        fscanf(inFile, "%s", command);
        if (strcmp(command, "AF") == 0) {
            fscanf(inFile, "%d", &x);
            addFirst(&myList, x);
        } else if (strcmp(command, "AL") == 0) {
            fscanf(inFile, "%d", &x);
            addLast(&myList, x);
        } else if (strcmp(command, "DF") == 0) {
            deleteFirst(&myList);
        } else if (strcmp(command, "DL") == 0) {
            deleteLast(&myList);
        } else if (strcmp(command, "DOOM_THE_LIST") == 0) {
            deleteAll(&myList);
        } else if (strcmp(command, "DE") == 0) {
            fscanf(inFile, "%d", &x);
            deleteValue(&myList, x);
        } else if (strcmp(command, "PRINT_ALL") == 0) {
            printAll(&myList, outFile);
        } else if (strcmp(command, "PRINT_F") == 0) {
            fscanf(inFile, "%d", &x);
            printFirstX(&myList, x, outFile);
        } else if (strcmp(command, "PRINT_L") == 0) {
            fscanf(inFile, "%d", &x);
            printLastX(&myList, x, outFile);
        }

    }

    return 0;
}
