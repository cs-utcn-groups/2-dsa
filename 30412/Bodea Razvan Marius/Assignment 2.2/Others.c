//
// Created by razvi on 3/9/2020.
//

#include "Others.h"
#include "Queue.h"
#include <stdio.h>
#include <stdlib.h>

FILE* openFile(char *name , char*mode){
    FILE *f=fopen(name,mode);
    if(f==NULL){
        perror("File could not be open");
        exit(EXIT_FAILURE);
    }
    return f;
}

void readTimes_AddList(FILE *f){
    int c;
    int counter=0;
    while ((c = fgetc(f)) != '\n') {
        if (c == ' ') {
            counter++;
        }
    }
    fseek(f, 0, SEEK_SET);
    for (int i = 0; i <= counter; i++) {
        fscanf(f, "%d", &c);
        Add_Last(c);   //insert the times in a Sll
    }
}

void printAndDelete(FILE *fptr,int M){
    fprintf(fptr,"After %d seconds: %d\n", first->data, M);
    Delete_First();
}