#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "list.h"

#define INPUT_FILE_PATH "input.dat"
#define OUTPUT_FILE_PATH "output.dat"

FILE *outputFile, *inputFile;
enum instructionList {AF, AL, DF, DL, DOOM_THE_LIST, DE, PRINT_ALL, PRINT_F, PRINT_L};
enum errorList {ERROR_FILE_NOT_OPEN, ERROR_INSTR_NOT_DETERMINED, ERROR_INVALID_INSTR};

void readFromFile();
int parseInstruction(char text[10]);

int main() {
    inputFile = fopen(INPUT_FILE_PATH, "r");
    outputFile = fopen(OUTPUT_FILE_PATH, "w");

    if (inputFile == NULL) {
        perror("Input file could not be opened, exiting...");
        exit(ERROR_FILE_NOT_OPEN);
    }

    initializeList();

    while (1) {
        if (feof(inputFile))
            break;
        readFromFile();
    }
    return 0;
}

void readFromFile() {
    char instructionText[10];
    fscanf(inputFile, "%s", instructionText);
    int instruction = parseInstruction(instructionText);
    char valueString[5];
    int value = 0;
    switch (instruction) {
        case AF: {
            fscanf(inputFile, "%s", valueString);
            char *p = NULL;
            value = strtol(valueString, &p, value);
            addElementToFront(value);
            break;
        }
        case AL: {
            fscanf(inputFile, "%s", valueString);
            char *p = NULL;
            value = strtol(valueString, &p, value);
            addElementToEnd(value);
            break;
        }
        case DE: {
            fscanf(inputFile, "%s", valueString);
            char *p = NULL;
            value = strtol(valueString, &p, value);
            removeElement(value);
            break;
        }
        case PRINT_F: {
            fscanf(inputFile, "%s", valueString);
            char *p = NULL;
            value = strtol(valueString, &p, value);
            printFirstNElements(value, outputFile);
            break;
        }
        case PRINT_L: {
            fscanf(inputFile, "%s", valueString);
            char *p = NULL;
            value = strtol(valueString, &p, value);
            printLastNElements(value, outputFile);
            break;
        }
        case DF: {
            removeFirstElement();
            break;
        }
        case DL: {
            removeLastElement();
            break;
        }
        case DOOM_THE_LIST: {
            deleteList();
            break;
        }
        case PRINT_ALL: {
            printAll(outputFile);
            break;
        }
        default: {
            perror("Something went wrong when determining the instruction, exiting...");
            exit(ERROR_INSTR_NOT_DETERMINED);
        }
    }
}

int parseInstruction(char text[10]) {
    if (strcmp(text, "AF") == 0) return AF;
    if (strcmp(text, "AL") == 0) return AL;
    if (strcmp(text, "DF") == 0) return DF;
    if (strcmp(text, "DL") == 0) return DL;
    if (strcmp(text, "DOOM_THE_LIST") == 0) return DOOM_THE_LIST;
    if (strcmp(text, "DE") == 0) return DE;
    if (strcmp(text, "PRINT_ALL") == 0) return PRINT_ALL;
    if (strcmp(text, "PRINT_F") == 0) return PRINT_F;
    if (strcmp(text, "PRINT_L") == 0) return PRINT_L;
    perror("Invalid instruction, exiting..."); exit(ERROR_INVALID_INSTR);
}
