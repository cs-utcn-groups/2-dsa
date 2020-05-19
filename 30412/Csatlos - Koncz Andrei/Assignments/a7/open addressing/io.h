//
// Created by csatl on 5/5/2020.
//

#ifndef OPEN_ADDRESSING_IO_H
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#define OPEN_ADDRESSING_IO_H

static const int MAX_STRING_LENGTH = 100;

char * randString();

void writeToFile(int N);

char ** readFromFile(int N);

FILE * getFileForInt(int N);

void printContentToConsole(char ** contents, int N);
#endif //OPEN_ADDRESSING_IO_H
