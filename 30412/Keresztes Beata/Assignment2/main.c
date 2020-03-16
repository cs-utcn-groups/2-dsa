#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "dll.h"
#define INPUT_FILE_NAME "../input.dat"
#define OUTPUT_FILE_NAME "../output.dat"
#define ERR_FILE_OPEN "Error opening file"
#define MAX_SIZE_INSTRUCT 30

FILE * openFile(char * name, char * mode);

int main() {

FILE * inFile = openFile(INPUT_FILE_NAME, "r");
FILE * outFile = openFile(OUTPUT_FILE_NAME, "w");

DLListT * myList = createEmptyList();

while(!feof(inFile)) {
    char * instruction = (char *)malloc(MAX_SIZE_INSTRUCT*sizeof(char));
    fscanf(inFile,"%s",instruction);
    int x;
    if(strcmp(instruction,"AF")==0) {
        fscanf(inFile,"%d",&x);
        addFirst(myList,x);
    }
    else if(strcmp(instruction,"AL")==0) {
        fscanf(inFile,"%d",&x);
        addLast(myList,x);
    }
    else if(strcmp(instruction,"DF")==0) {
        deleteFirst(myList);
    }
    else if(strcmp(instruction,"DL")==0) {
        deleteLast(myList);
    }
    else if(strcmp(instruction,"DOOM_THE_LIST")==0) {
        doomTheList(myList);
    }
    else if(strcmp(instruction,"DE")==0) {
        fscanf(inFile,"%d",&x);
        deleteByKey(myList, x);
    }
    else if(strcmp(instruction,"PRINT_ALL")==0) {
        printList(outFile,myList);
    }
    else if(strcmp(instruction,"PRINT_F")==0) {
        fscanf(inFile,"%d",&x);
        printFirst(outFile,myList,x);
    }
    else if(strcmp(instruction,"PRINT_L")==0) {
        fscanf(inFile,"%d",&x);
        printLast(outFile,myList,x);
    }
    free(instruction);
}
    fclose(inFile);
    fclose(outFile);
    freeList(myList);
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