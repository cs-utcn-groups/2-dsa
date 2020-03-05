#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "sll.h"

#define FILE_PATH_INPUT "../input.dat"
#define FILE_PATH_OUTPUT "../output.dat"
#define MAX_LINE 20

int main() {
    FILE *inputFile;
    inputFile = fopen(FILE_PATH_INPUT, "r");
    if (inputFile == NULL) {
        perror("Error opening file");
        return (-1);
    }

    FILE *outputFile;
    outputFile = fopen(FILE_PATH_OUTPUT, "w");

    initializeSLL();

    char *line, *p, *operation;
    int x;
    line = (char *) malloc(MAX_LINE * sizeof(char));
    operation = (char *) malloc(MAX_LINE * sizeof(char));
    while (!feof(inputFile)) {
        fgets(line, MAX_LINE, inputFile);
        p = strtok(line, " ");
        strcpy(operation, p);
        p = strtok(0, " ");
        if (p)
            x = atoi(p);
        if (strcmp(operation, "AF") == 0) {
            AF(x);
        } else if (strcmp(operation, "AL") == 0) {
            AL(x);
        } else if (strcmp(operation, "DF") == 0) {
            DF();
        } else if (strcmp(operation, "DL") == 0) {
            DL();
        } else if (strcmp(operation, "DOOM_THE_LIST") == 0) {
            DOOM_THE_LIST();
        } else if (strcmp(operation, "DE") == 0) {
            DE_x(x);
        } else if (strcmp(operation, "PRINT_ALL") == 0) {
            PRINT_ALL(outputFile);
        } else if (strcmp(operation, "PRINT_F") == 0) {
            PRINT_F(x, outputFile);
        } else if (strcmp(operation, "PRINT_ALL") == 0) {
            PRINT_L(x, outputFile);
        }
    }
    free(line);
    return 0;
}
