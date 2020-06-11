#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

static const int MAX_STRING_LENGTH = 64;

char *randString();

char **readFromFile(int N);

FILE *getFileForInt(int N);
