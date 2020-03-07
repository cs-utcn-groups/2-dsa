#include <stdio.h>
#include "DLL.h"
#include <string.h>

int main() {

    LIST = createEmptyList();
    f = fopen("../dataIn.txt", "r");
    g = fopen("../dataOut.txt", "w");
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
            addFirst(x);
        }
        else if(!strcmp(line, "AL"))
        {
            fscanf(f, "%d", &x);
            addLast(x);
        }
        else if(!strcmp(line, "DF"))
        {
            deleteFirst();
        }
        else if(!strcmp(line, "DL"))
        {
            deleteLast();
        }
        else if(!strcmp(line, "DE"))
        {
            fscanf(f, "%d", &x);
            deleteElement(x);
        }
        else if(!strcmp(line, "DOOM_THE_LIST"))
        {
            deleteAll();
        }
        else if(!strcmp(line, "PRINT_ALL"))
        {
            printAll();
        }
        else if(!strcmp(line, "PRINT_F"))
        {
            fscanf(f, "%d", &x);
            printFirst(x);
        }
        else if(!strcmp(line, "PRINT_L"))
        {
            fscanf(f, "%d", &x);
            printLast(x);
        }
    }
}