#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "list.h"

#define in "../input.dat"
#define out "../output.dat"


int main() {
    FILE *output, *input;
    output = fopen(out, "w");
    if (output == NULL) {
        perror("ERROR");
        exit(-1);
    }
    input = fopen(in, "r");
    if (input == NULL) {
        perror("ERROR");
        exit(-1);
    }
    startSLL();
    int data, k = 0;
    char command[10];
    while (fscanf(input, "%s %d", command, &data) != EOF) {
        if (strcmp(command, "AF") == 0)
            AF(data);
        if (strcmp(command, "AL") == 0)
            AL(data);
        if (strcmp(command, "DF") == 0)
            DF();
        if (strcmp(command, "DL") == 0)
            DL();
        if (strcmp(command, "DOOM_THE_LIST") == 0)
            DOOM();
        if (strcmp(command, "DE") == 0)
            DE(data);
        if (strcmp(command, "PRINT_F") == 0)
            printF(output, data);
        if (strcmp(command, "PRINT_L") == 0) {
            k = 0;
            noOfItems(output, data, &k, first);
            printL(output, data, k);
        }
        if (strcmp(command, "PRINT_ALL") == 0)
            printALL(output);
    }


    return 0;
}