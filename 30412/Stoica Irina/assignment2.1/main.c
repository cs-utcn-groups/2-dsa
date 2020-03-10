#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "operations.h"
#include "head.h"

#define MAX_LENGTH 15

void openFile(FILE * file);

int main() {
    FILE * input = fopen("..//input.dat", "r");
    openFile(input);
    FILE * output = fopen("..//output.dat", "w");
    openFile(output);
    initialiseList();
    node * sentinel = getSentinel();
    char * operation = (char*)malloc(MAX_LENGTH);
    int number;
    while (!feof(input)){
        fscanf(input, "%s", operation);
        if(strcmp(operation, "AF")==0){
            fscanf(input, "%d", &number);
            addFirst(number, sentinel);
        }
        if(strcmp(operation, "AL")==0){
            fscanf(input, "%d", &number);
            addLast(number);
        }
        if(strcmp(operation, "DF")==0) {
            deleteFirst(sentinel);
        }
        if(strcmp(operation, "DL")==0){
            deleteLast();
        }
        if(strcmp(operation, "DE")==0){
            fscanf(input, "%d", &number);
            deleteElement(number);
        }
        if(strcmp(operation, "PRINT_ALL")==0){
            printAll(output);
        }
        if(strcmp(operation, "PRINT_F")==0){
            fscanf(input, "%d", &number);
            printFirstNumbers(number, output);
        }
        if(strcmp(operation, "PRINT_L")==0){
            fscanf(input, "%d", &number);
            printLastNumbers(number, output);
        }
        if(strcmp(operation, "DOOM_THE_LIST")==0){
            deleteAll();
        }
    }
    return 0;
}
void openFile(FILE * file){
    if (file == NULL){
        perror("File could not be opened");
        exit(-1);
    }
}