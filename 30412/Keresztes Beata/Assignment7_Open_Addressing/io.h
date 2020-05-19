//
// Created by q on 5/1/2020.
//

#ifndef ASSIGNMENT7_OPEN_ADDRESSING_IO_H
#define ASSIGNMENT7_OPEN_ADDRESSING_IO_H
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

#endif //ASSIGNMENT7_OPEN_ADDRESSING_IO_H
