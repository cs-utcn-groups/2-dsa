#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <ctype.h>
#include <string.h>
#include "customer.h"
#include "customerlist.h"
#include "timeList.h"

#define INPUT_PATH "../input.txt"
#define OUTPUT_PATH "../output.txt"

FILE *inputFile, *outputFile;

void parseFirstLine();

int main() {
    inputFile = fopen(INPUT_PATH, "r");
    outputFile = fopen(OUTPUT_PATH, "w");

    parseFirstLine();

    initializeCustomerList();

    while (1) {
        if (feof(inputFile)) {
            break;
        }
        readCustomer(inputFile);
    }

    printCustomerList();

    return 0;
}

void parseFirstLine() {
    initializeTimeList();
    char line[200], *parsePtr;
    fgets(line, 199, inputFile);
    fgetc(inputFile);
    parsePtr = strtok(line, " ");
    while (parsePtr != NULL) {
        addTimeToList(atoi(parsePtr));
        parsePtr = strtok(NULL, " ");
    }
    printTimeList();
}
