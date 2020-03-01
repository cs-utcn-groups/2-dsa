#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "SLL.h"

int main()
{
    FILE *ifptr, *ofptr;
    ifptr = fopen("input.dat", "r");
    ofptr = fopen("output.dat", "w");
    char line[20], *instruction, *param;
    int x;
    initializeList();
    while(fgets(line, 20, ifptr) != NULL)
    {
        instruction = strtok(line, " \n");
        param = strtok(NULL, " ");
        x = atoi(param);
        //x = atoi(strtok(NULL, ' '));
        if(stricmp(instruction, "AF") == 0)
            addFirst(x);
        else
            if(stricmp(instruction, "AL") == 0)
                addLast(x);
            else
                if(stricmp(instruction, "DF") == 0)
                    deleteFirst();
                else
                    if(stricmp(instruction, "DL") == 0)
                        deleteLast();
                    else
                        if(stricmp(instruction, "DOOM_THE_LIST") == 0)
                            doomTheList();
                        else
                            if(stricmp(instruction, "DE") == 0)
                                deleteElement(x);
                            else
                                if(stricmp(instruction, "PRINT_ALL") == 0)
                                    printAll(ofptr);
                                else
                                    if(stricmp(instruction, "PRINT_F") == 0)
                                        printFirstXValues(ofptr, x);
                                    else
                                        if(stricmp(instruction, "PRINT_L") == 0)
                                            printLastXValues(ofptr, x);
    }

    return 0;
}