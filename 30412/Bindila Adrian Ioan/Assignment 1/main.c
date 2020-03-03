#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "list.h"
#include "commands.h"

#define MAX_LINE_LENGTH 32

int main() {
    FILE *fin = fopen("../input.dat", "r");
    initList();
    printAll();
    char *buffer = (char *) malloc(MAX_LINE_LENGTH * sizeof(char));
    while (fgets(buffer, MAX_LINE_LENGTH, fin)) {
        int x = 0;
        char *ptr,*number;
        strtok_r(buffer," ",&number);
        x=strtol(number,&ptr,10);///data
        int command = readCommand(buffer);
        executeCommand(command, x);
        printDebugList();
    }
    fclose(fin);
    return 0;
}
