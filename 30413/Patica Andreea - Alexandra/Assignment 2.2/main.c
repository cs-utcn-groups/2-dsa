#include <stdio.h>
#include <stdlib.h>
#include "header.h"

#define MAX_LENGTH 100

int main()
{
    FILE *f = fopen("input.dat", "r");
    Initialize();

    char *strBuf = (char*)malloc(sizeof(char)*MAX_LENGTH);

    fgets(strBuf, MAX_LENGTH, f);
    ParseList(strBuf);

    FILE *g = fopen("output.dat", "w");
    ComputeMoney(f, g);

    fclose(f);
    fclose(g);

    return 0;
}
