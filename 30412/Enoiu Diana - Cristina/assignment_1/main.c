#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "head.h"
#include "sll.h"
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
int main() {
    initialize();
    if (fp_input == NULL) {
        perror("NO_FILE_FOUND");
        exit(1);
    }
    initializeSll();
    while(fscanf(fp_input,"%s",command)!=EOF) {
        if(strcmp(command,"AF") == 0) {
            element = readElement();
            addFirst(element);
        }
        if(strcmp(command,"AL") == 0) {
            element = readElement();
            addLast(element);
        }
        if(strcmp(command,"DF") == 0) {
            deleteFirst();
        }
        if(strcmp(command,"DL") == 0) {
            deleteLast();
        }
        if(strcmp(command,"PRINT_ALL") == 0) {
            printAll(fp_output);
        }
        if(strcmp(command,"DOOM_THE_LIST") == 0) {
            doomTheList();
        }
        if(strcmp(command,"DE") == 0) {
            element = readElement();
            deleteElement(element);
        }
        if(strcmp(command,"PRINT_F") == 0) {
            element = readElement();
            printFirst(fp_output, element);
        }
        if(strcmp(command,"PRINT_L") == 0) {
            element = readElement();
            printLast(fp_output, element);
        }
    }

    return 0;
}