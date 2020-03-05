#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "list.h"

#define FILE_ERR_CODE 1
#define FILE_ERR_MESS "error opening file"
#define MAX_LINE_LENGTH 1000

FILE *openFile(char *name, char *mode) {
    FILE *newFile = fopen(name, mode);
    if (newFile == NULL) {
        perror(FILE_ERR_MESS);
        exit(FILE_ERR_CODE);
    }
    return newFile;
}

int main() {
    FILE *inFile = openFile("input.dat", "r");
    FILE *outFile = openFile("output.dat", "w");

    Queue moments = createQueue();


    char *line = (char *) malloc(sizeof(char) * MAX_LINE_LENGTH);
    fgets(line, MAX_LINE_LENGTH, inFile);
    const char s[1] = " ";
    char* nextMoment_string;

    nextMoment_string = strtok(line, s);
    push(&moments, atoi(nextMoment_string));
    while ((nextMoment_string = strtok(NULL, s)) != NULL) {
        push(&moments, atoi(nextMoment_string));
        printAll(&moments, stdout);
    }
    return 0;
}