//
// Created by razvi on 3/9/2020.
//

#ifndef NEW_FOLDER_OTHERS_H
#define NEW_FOLDER_OTHERS_H

#include <ctype.h>
#include <stdio.h>

FILE* openFile(char *name , char*mode);
void readTimes_AddList(FILE *f);
void printAndDelete(FILE *fptr,int M);

#endif //NEW_FOLDER_OTHERS_H
