//
// Created by Denisa on 3/1/2020.
//

#include "extraFunctions.h"

void parseFromFile(char **nameOfFunction, int *key, char *line) {
    char *p = strtok(line, " \n");
    strcpy(*nameOfFunction, p);
    p = strtok(NULL, " \n");
    if (p != NULL) {
        sscanf(p, "%d", &(*key));
    } else {
        *key = 0;
    }
}

void callingTheFunction(FILE *input, FILE *output) {
    int key = 0;
    char *nameOfFunction = (char *) malloc(MAX_LINE * sizeof(char));
    char *line = (char *) malloc(MAX_LINE * sizeof(char));
    while (fgets(line, MAX_LINE, input)) {
        parseFromFile(&nameOfFunction, &key, line);
        if (strcmp(nameOfFunction, "AF") == 0) {
            AF(key);
        } else if (strcmp(nameOfFunction, "AL") == 0) {
            AL(key);
        } else if (strcmp(nameOfFunction, "DF") == 0) {
            DF();
        } else if (strcmp(nameOfFunction, "DL") == 0) {
            DL();
        } else if (strcmp(nameOfFunction, "DOOM_THE_LIST") == 0) {
            DOOM_THE_LIST();
        } else if (strcmp(nameOfFunction, "DE") == 0) {
            DE(key);
        } else if (strcmp(nameOfFunction, "PRINT_ALL") == 0) {
            PRINT_ALL(output);
        } else if (strcmp(nameOfFunction, "PRINT_F") == 0) {
            PRINT_F(output, key);
        } else if (strcmp(nameOfFunction, "PRINT_L") == 0) {
            PRINT_L(output, key);
        }
    }
}