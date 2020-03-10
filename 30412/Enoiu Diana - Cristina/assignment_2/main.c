#include <stdio.h>
#include "head.h"
#include "stdlib.h"
#include "string.h"
#include "dll.h"
int main() {
    initialize();
    if (fp_input == NULL) {
        perror("NO_FILE_FOUND");
        exit(1);
    }
    initializeDll();
    while(fscanf(fp_input,"%s",command)!=EOF) {
        if(strcmp(command,"AF") == 0) {
            element = readElement();
            addFirst(element);
        } else
        if(strcmp(command,"AL") == 0) {
            element = readElement();
            addLast(element);
        } else
        if(strcmp(command,"DF") == 0) {
            deleteFirst();
        } else
        if(strcmp(command,"DL") == 0) {
            deleteLast();
        } else
        if(strcmp(command,"PRINT_ALL") == 0) {
            printAll(fp_output);
        } else
        if(strcmp(command,"DOOM_THE_LIST") == 0) {
            doomTheList();
        } else
        if(strcmp(command,"DE") == 0) {
            element = readElement();
            deleteElement(element);
        } else
        if(strcmp(command,"PRINT_F") == 0) {
            element = readElement();
            printFirstElements(fp_output,element);
        } else
        if(strcmp(command,"PRINT_L") == 0) {
            element = readElement();
            printLastElements(fp_output,element);
        }
    }
    freeMemory();
    return 0;
}
void initialize() {
    command = (char *)malloc(100 * sizeof(char));
    data = (char *)malloc(100 * sizeof(char));
    fp_input = fopen("../input.dat","r");
    fp_output = fopen("../output.dat","a");
}
int readElement() {
    fscanf(fp_input,"%s",data);
    char * ptr;
    return strtol(data,&ptr,10);
}
void freeMemory() {
    doomTheList();
    free(sentinel);
    free(current);
}