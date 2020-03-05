#include <stdio.h>
#include <stdlib.h>
#include "alloc.h"
#include <string.h>

#define file_in "../input.dat"
#define file_out "../output.dat"


int main() {
    FILE *outputFile, *inputFile;
    outputFile = fopen(file_out, "w");
    if (outputFile == NULL) {
        perror("File could not be open");
        exit(-1);
    }
    inputFile = fopen(file_in, "r");
    if (inputFile == NULL) {
        perror("File could not be open");
        exit(-1);
    }
    startSll();
    int data, k = 0;
    char command[10];
    while (fscanf(inputFile, "%s %d", command, &data) != EOF) {
        if (strcmp(command, "AF") == 0)
            af(data);
        if (strcmp(command, "AL") == 0)
            al(data);
        if (strcmp(command, "DF") == 0)
            df();
        if (strcmp(command, "DL") == 0)
            dl();
        if (strcmp(command, "DOOM_THE_LIST") == 0)
            doom();
        if (strcmp(command, "DE") == 0)
            d_spec(data);
        if (strcmp(command, "PRINT_F") == 0)
            print_f_x(outputFile, data);
        if (strcmp(command, "PRINT_L") == 0) {
            k = 0;
            nr_of_items(outputFile, data, &k, first);
            print_l_x(outputFile, data, k);
        }
        if (strcmp(command, "PRINT_ALL") == 0)
            print_all(outputFile);
    }


    return 0;
}