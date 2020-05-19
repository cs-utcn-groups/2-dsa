#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define MAX_STRING_LENGTH 128

char * randString();

void writeToFile(int N);

char ** readFromFile(int N);

FILE * getFileForInt(int N);

void printContentToConsole(char ** contents, int N);
