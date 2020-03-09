#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "list.h"
#include "commands.h"

#define IN_FILE "../input.dat"
#define OUT_FILE "../output.dat"
#define MAX_LINE_LENGTH 32

int main() {
    FILE *input = fopen(IN_FILE, "r");
    FILE *output = fopen(OUT_FILE, "w");
    initList();
    char *buffer = (char *) malloc(MAX_LINE_LENGTH * sizeof(char));
    while (fgets(buffer, MAX_LINE_LENGTH, input)) {
        char *ptr, *number;
        strtok_r(buffer, " \n", &number);///Commands without a number next to them have a \n as delimiter
        int x = strtol(number, &ptr, 10);///data
        doCommand(buffer, x, output);
    }
    free(buffer);
    fclose(input);
    fclose(output);
    return 0;
}
