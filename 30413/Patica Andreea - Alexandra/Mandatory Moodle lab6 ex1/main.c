#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "header.h"

int main()
{
    FILE *f = fopen("input.in", "r");
    FILE *g = fopen("output.out", "w");

    Initialize();

    char function;
    while (fscanf(f, "%c", &function)>0)
    {
        if (function=='\n') break;
        char *strBuf = (char*)malloc(sizeof(char)*100);
        char aux, *token;

        switch(function)
        {
            case 'i':
                fgets(strBuf,100,f);
                token = strtok(strBuf, "\n");
                Insert(token);
                break;
            case 'd':
                fgets(strBuf,100,f);
                token = strtok(strBuf, "\n");
                Delete(strBuf);
                break;
            case 'f':
                fgets(strBuf,100,f);
                token = strtok(strBuf, "\n");
                int index = Find(token);
                if (index != -1)
                        fprintf(g, "Yes %d\n", index);
                else fprintf(g, "No\n");
                break;
            case 'l':
                fscanf(f, "%c", &aux);
                Print(g);
                fprintf(g, "\n");
                break;
            default: fprintf(g, "Invalid call for function!\n");
                break;
        }
    }

    fclose(f);
    fclose(g);

    return 0;
}
