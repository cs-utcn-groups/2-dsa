#include <stdio.h>
#include <stdlib.h>
#include "list.h"
#define MAX_LENGTH 50

int main()
{
    FILE *f = fopen("input.dat", "r");
    Initialize();

    char *strBuf = (char*)malloc(sizeof(char)*MAX_LENGTH);

    while (fgets(strBuf, MAX_LENGTH, f)!=NULL)
    {
        ParseString(strBuf);
    }

    fclose(f);
    return 0;
}
