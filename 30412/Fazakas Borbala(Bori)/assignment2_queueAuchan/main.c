#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "costumerQueue.h"
#include "intQueue.h"

#define FILE_ERR_CODE 1
#define FILE_ERR_MESS "error opening file"
#define MAX_LINE_LENGTH 1000

FILE *openFile(char *name, char *mode);

void readMoments(intQueue *moments, FILE *inFile);

void readCostumersData(costumerQueue *costumers, FILE *inFile);

void simulateQueue(costumerQueue *costumers, intQueue *moments, FILE *outFile);

int main() {
    FILE *inFile = openFile("input.dat", "r");
    FILE *outFile = openFile("output.dat", "w");

    intQueue moments = createIntQueue();
    readMoments(&moments, inFile);

    costumerQueue costumers = createCostumerQueue();
    readCostumersData(&costumers, inFile);

    simulateQueue(&costumers, &moments, outFile);
    fclose(inFile);
    fclose(outFile);
    return 0;
}

FILE *openFile(char *name, char *mode) {
    FILE *newFile = fopen(name, mode);
    if (newFile == NULL) {
        perror(FILE_ERR_MESS);
        exit(FILE_ERR_CODE);
    }
    return newFile;
}

void readMoments(intQueue *moments, FILE *inFile) {
    char *line = (char *) malloc(sizeof(char) * MAX_LINE_LENGTH);
    fgets(line, MAX_LINE_LENGTH, inFile);
    char *nextMoment_string;

    if (strlen(line) > 1) {
        nextMoment_string = strtok(line, " ");
        pushInt(moments, atoi(nextMoment_string));
        while ((nextMoment_string = strtok(NULL, " ")) != NULL) {
            pushInt(moments, atoi(nextMoment_string));
        }
    }
    free(line);
}

void readCostumersData(costumerQueue *costumers, FILE *inFile) {
    char *name = (char *) malloc(sizeof(char) * MAX_LINE_LENGTH);
    while (!feof(inFile)) {
        costumer newCostumer;
        fscanf(inFile, "%s %d %d", name, &newCostumer.amount, &newCostumer.time);
        pushCostumer(costumers, &newCostumer);
    }
    free(name);
}

void simulateQueue(costumerQueue *costumers, intQueue *moments, FILE *outFile) {
    int elapsedTime = 0;
    int ownedAmount = 0;
    costumer curFrontCostumer;
    while (!intQueueIsEmpty(moments)) {
        while (!costumerQueueIsEmpty(costumers) && elapsedTime + frontCostumer(costumers).time <= frontInt(moments)) {
            curFrontCostumer = popCostumer(costumers);
            elapsedTime += curFrontCostumer.time;
            ownedAmount += curFrontCostumer.amount;
        }
        fprintf(outFile, "After %d seconds: %d\n", frontInt(moments), ownedAmount);
        popInt(moments);
    }
    while (!costumerQueueIsEmpty(costumers)) {
        popCostumer(costumers);
    }
}