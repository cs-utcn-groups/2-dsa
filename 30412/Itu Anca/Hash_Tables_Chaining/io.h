//
// Created by Anca on 5/2/2020.
//

#ifndef HASH_TABLES_CHAINING_IO_H

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <math.h>

static const int MAX_STRING_LENGTH = 64;

char * randString();

void writeToFile(int N);

char ** readFromFile(int N);

FILE * getFileForInt(int N);

void printContentToConsole(char ** contents, int N);

#define HASH_TABLES_CHAINING_IO_H

#endif //HASH_TABLES_CHAINING_IO_H
