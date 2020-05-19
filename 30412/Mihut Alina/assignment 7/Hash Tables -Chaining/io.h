//
// Created by Alina Mihut on 5/2/20.
//

#ifndef HASH_TABLES__CHAINING_IO_H

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
#define HASH_TABLES__CHAINING_IO_H

#endif //HASH_TABLES__CHAINING_IO_H
