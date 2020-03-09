#include <stdio.h>
#include <stdlib.h>

#include "time.h"

#define INPUT_FILE_NAME "../input.dat"
#define OUTPUT_FILE_NAME "../output.dat"
#define ERR_FILE_OPEN "Error opening file"

FILE * openFile(char * name, char * mode);

int main() {

FILE * inFile = openFile(INPUT_FILE_NAME, "r");
FILE * outFile = openFile(OUTPUT_FILE_NAME, "w");

MomentT * myMoments= readTime(inFile); //time moments
QueueT * myQueue = readQueue(inFile); //queue of customers
fclose(inFile);

printSumAtEachMoment(outFile,myMoments,myQueue);

fclose(outFile);
//free the allocated memory
freeQueue(myQueue);
freeTime(myMoments);
    return 0;
}

FILE * openFile(char * name, char * mode) {
    FILE * fp = fopen(name, mode);
    if(fp == NULL) {
        perror(ERR_FILE_OPEN);
        exit(EXIT_FAILURE);
    }
    return fp;
}