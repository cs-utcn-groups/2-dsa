#include <stdio.h>
#include "list.h"
#include "node.h"
#include <string.h>

#define INPUT_PATH "../input.dat"
#define OUTPUT_PATH "../output.dat"

enum instructionList {AF, AL, DF, DL, DOOM_THE_LIST, DE, PRINT_ALL, PRINT_F, PRINT_L, INVALID};

FILE *inputFile;
FILE *outputFile;

void readFromFile();

int getInstructionValue(char *instruction);

int main() {
    inputFile = fopen(INPUT_PATH, "r");
    outputFile = fopen(OUTPUT_PATH, "w");

    initializeList();

    while (1) {
        if (feof(inputFile))
            break;
        readFromFile();
    }

    return 0;
}

void readFromFile() {
    char instruction[8];
    fscanf(inputFile, "%s", instruction);
    switch (getInstructionValue(instruction)) {
        case AF: {
            int value;
            fscanf(inputFile, "%d", &value);
            addElementToFront(value);
            break;
        }
        case AL: {
            int value;
            fscanf(inputFile, "%d", &value);
            addElementToEnd(value);
            break;
        }
        case DF: {
            deleteFirstElement();
            break;
        }
        case DL: {
            deleteLastElement();
            break;
        }
        case DOOM_THE_LIST: {
            deleteList();
            break;
        }
        case DE: {
            int value;
            fscanf(inputFile, "%d", &value);
            deleteElement(value);
            break;
        }
        case PRINT_ALL: {
            printAll(outputFile);
            break;
        }/*
        case PRINT_F: {
            int value;
            fscanf(inputFile, "%d", &value);
            printFirst(value, outputFile);
            break;
        }
        case PRINT_L: {
            int value;
            fscanf(inputFile, "%d", &value);
            printLast(value, outputFile);
            break;
        }*/
    }
}

int getInstructionValue(char *instruction) {
    if (strcmp(instruction, "AF") == 0) return AF;
    if (strcmp(instruction, "AL") == 0) return AL;
    if (strcmp(instruction, "DF") == 0) return DF;
    if (strcmp(instruction, "DL") == 0) return DL;
    if (strcmp(instruction, "DOOM_THE_LIST") == 0) return DOOM_THE_LIST;
    if (strcmp(instruction, "DE") == 0) return DE;
    if (strcmp(instruction, "PRINT_ALL") == 0) return PRINT_ALL;
    if (strcmp(instruction, "PRINT_F") == 0) return PRINT_F;
    if (strcmp(instruction, "PRINT_L") == 0) return PRINT_L;
    return INVALID;
}
