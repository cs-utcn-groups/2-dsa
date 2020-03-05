#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "operations.h"

#define MAX_LENGTH 20

int main() {
    int number;
    char * operation = (char*)malloc(MAX_LENGTH * sizeof(char));
    FILE * inputFile = fopen("../input.dat", "r");
    FILE * outputFile = fopen("../output.dat", "w");
    if (inputFile == NULL){
        perror("File could not be opened");
        exit(-1);
    }
    if (outputFile == NULL){
        perror("File could not be opened");
        exit(-1);
    }
    initializeList();
    while(!feof(inputFile)){
        fscanf(inputFile, "%s", operation);
        if(strcmp(operation, "AF")==0){
            fscanf(inputFile, "%d", &number);
            addFirst(number);
        }
        else if(strcmp(operation, "AL")==0){
            fscanf(inputFile, "%d", &number);
            addLast(number);
        }
        else if (strcmp(operation, "DF")==0){
            deleteFirst();
        }
        else if (strcmp(operation, "DL")==0){
            deleteLast();
        }
        else if (strcmp(operation, "PRINT_ALL")==0){
            printList(outputFile);
        }
        else if (strcmp(operation, "DE")==0){
            fscanf(inputFile, "%d", &number);
            deleteElement(number);
        }
        else if (strcmp(operation, "DOOM_THE_LIST")==0){
            deleteAll();
        }
        else if (strcmp(operation, "PRINT_F")==0){
            fscanf(inputFile, "%d", &number);
            printFirst(number, outputFile);
        }
        else if (strcmp(operation, "PRINT_L")==0){
            fscanf(inputFile, "%d", &number);
            printLast(number, outputFile);
        }
    }
    return 0;
}