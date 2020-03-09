#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "list.h"
#include "command.h"

#define MAX_LINE_LENGTH 64

int main() {
    FILE *input = fopen("../input.dat", "r");
    FILE *output = fopen("../output.dat", "w");
    initTimeList();
    initCashierList();

    char *buffer = (char *) malloc(MAX_LINE_LENGTH * sizeof(char));
    fgets(buffer, MAX_LINE_LENGTH, input);
    readTime(buffer);
    while (fgets(buffer, MAX_LINE_LENGTH, input)) {
        char *ptr;
        strtok(buffer," ");
        buffer=strtok(NULL," ");
        int money = strtol(buffer, &ptr, 10);
        buffer=strtok(NULL," ");
        int time = strtol(buffer, &ptr, 10);
        cashierAddLast(money, time);
    }
    printTimeAndMoney(output);
    free(buffer);
    fclose(input);
    fclose(output);
    return 0;
}
