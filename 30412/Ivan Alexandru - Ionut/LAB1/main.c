#include <stdio.h>
#include <stdlib.h>
#include "linkedList.h"

int main()
{
    f = fopen("../dataIN.txt", "r");
    g = fopen("../dataOut.txt", "w");
    initList();

    char *line = (char*)malloc(MAX_LEN*sizeof(char));

    for( ;; )
    {
        int x;
        fscanf(f, "%s", line);

        ///verification of EOF
        if (feof( f ))
            break;

        if(!strcmp(line, "AF"))
        {
            fscanf(f, "%d", &x);
            AF(x);
        }
        else if(!strcmp(line, "AL"))
        {
            fscanf(f, "%d", &x);
            AL(x);
        }
        else if(!strcmp(line, "DF"))
        {
            DF();
        }
        else if(!strcmp(line, "DL"))
        {
            DL();
        }
        else if(!strcmp(line, "DE"))
        {
            fscanf(f, "%d", &x);
            DE(x);
        }
        else if(!strcmp(line, "DOOM_THE_LIST"))
        {
            DOOM_THE_LIST();
        }
        else if(!strcmp(line, "PRINT_ALL"))
        {
            PRINT_ALL();
        }
        else if(!strcmp(line, "PRINT_F"))
        {
            fscanf(f, "%d", &x);
            PRINT_F(x);
        }
        else if(!strcmp(line, "PRINT_L"))
        {
            fscanf(f, "%d", &x);
            PRINT_L(x);
        }
    }
}
