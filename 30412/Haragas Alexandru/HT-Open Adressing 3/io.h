//
// Created by Alex on 02.05.2020.
//

#ifndef HT_OPEN_ADRESSING_IO_H
#define HT_OPEN_ADRESSING_IO_H

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

#endif //HT_OPEN_ADRESSING_IO_H
