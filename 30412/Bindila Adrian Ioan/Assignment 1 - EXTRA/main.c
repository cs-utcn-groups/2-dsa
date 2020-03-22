#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "list.h"

#define INPUT "../input.dat"
#define OUTPUT "../output.dat"
#define MAX_LINE_LENGTH 64

int main() {
    FILE *input = fopen(INPUT, "r");
    FILE *output = fopen(OUTPUT, "w");
    initCountryList();
    initSentinelList();
    char *buffer = (char *) malloc(MAX_LINE_LENGTH * sizeof(char));
    char *ptr;
    fgets(buffer, MAX_LINE_LENGTH, input);
    int noOfSentinels = strtol(buffer, &ptr, 10);
    fgets(buffer, MAX_LINE_LENGTH, input);
    char *token = strtok(buffer, " \n");

    for (int i = 0; i < noOfSentinels; i++) {
        int x = strtol(token, &ptr, 10);
        addSentinelLast(x);
        token = strtok(NULL, " \n");
    }
    fgets(buffer, MAX_LINE_LENGTH, input);
    int noOfCountries = strtol(buffer, &ptr, 10);
    for (int j = 0; j < noOfCountries; ++j) {
        fgets(buffer, MAX_LINE_LENGTH, input);
        token = strtok(buffer, " \n");
        addCountryLast(token);
        token = strtok(NULL, " \n");
        while (token != NULL) {
            int waveDamage = strtol(token, &ptr, 10);
            addWaveLast(waveDamage);
            token = strtok(NULL, " \n");
        }
    }
    computeBattle(output);
    free(buffer);
    fclose(input);
    fclose(output);
    return 0;
}
