#include "io.h"

char ** readFromFile(int N)
{
    char **contents = (char **) malloc(sizeof(char *) * N);
    int i;

    for (i = 0; i < N; i++) {
        contents[i] = (char *) malloc(sizeof(char) * (MAX_STRING_LENGTH + 1));
    }

    FILE *f = getFileForInt(N);

    for (i = 0; i < N; i++) {
        fgets(contents[i], (MAX_STRING_LENGTH + 2), f);
    }

    return contents;
}

FILE * getFileForInt(int N)
{
    char *filename = (char *) malloc(sizeof(char) * 32);
    strcpy(filename, "../");
    itoa(N, filename + 3, 10);
    return fopen(strcat(filename, ".data"), "rw");
}
