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

void solveRequest();

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

    solveRequest();

    return 0;
}

void solveRequest() {
    if (timeList->nrOfEntries > 0) {
        Node *currentTimeNode = timeList->first;
        for (int i = 0; i < timeList->nrOfEntries; ++i) {
            int time = currentTimeNode->time;
            int cash = 0;
            if (customerList->nrOfCustomers == 0) return;
            Customer *currentCustomer = customerList->first;
            while (currentCustomer != NULL && time - currentCustomer->time >= 0) {
                time -= currentCustomer->time;
                cash += currentCustomer->cash;
                currentCustomer = currentCustomer->next;
            }
            fprintf(outputFile, "After %d seconds: %d\n", currentTimeNode->time, cash);
            currentTimeNode=currentTimeNode->next;
        }
    }
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
}
