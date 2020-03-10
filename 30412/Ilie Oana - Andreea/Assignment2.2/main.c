#include <stdio.h>
#include <stdlib.h>
#include "time.h"
#include "customer.h"
#include "queue.h"

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


    initializeTime();
    readTime(inputFile);

    initializeCustomer();
    readCustomer(inputFile);

    initializeQueue();
    createQueue();
    PRINT_ALL_Q(outputFile);

    return 0;
}
