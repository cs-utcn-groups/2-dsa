//
// Created by Bori on 4/29/2020.
//

#ifndef ASSIGNMENT6_HT_CHAINING_IO_H
#define ASSIGNMENT6_HT_CHAINING_IO_H

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>


static const int MAX_STRING_LENGTH = 64;

char * randString();

void writeToFile(int N);

char ** readFromFile(int N);

FILE * getFileForInt(int N);

void printContentToConsole(char ** contents, int N);

#endif //ASSIGNMENT6_HT_CHAINING_IO_H
