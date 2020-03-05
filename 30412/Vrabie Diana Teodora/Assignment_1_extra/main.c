#include <stdio.h>
#include <stdlib.h>
#include "country.h"
#include "wave.h"
#include "sentinel.h"
#include "parse-values.h"

#define INPUT_PATH "../input.dat"
#define OUTPUT_PATH "../output.dat"

FILE *inputFile;
FILE *outputFile;

int main() {
    inputFile = fopen(INPUT_PATH, "r");
    outputFile = fopen(OUTPUT_PATH, "w");

    int nrOfSentinels = 0, nrOfCountries = 0;

    char read[20], *p;

    fscanf(inputFile, "%s", read);
    nrOfSentinels = strtol(read, &p, 10);

    for (int i = 0; i < nrOfSentinels; ++i) {
        fscanf(inputFile, "%s", read);
        int data = 0;
        data = strtol(read, &p, 10);
        addSentinel(data);
    }

    fscanf(inputFile, "%s", read);
    nrOfCountries = strtol(read, &p, 10);
    initializeCountryList();
    getc(inputFile);

    for (int j = 0; j < nrOfCountries; ++j) {
        char line[100];
        fgets(line, 100, inputFile);
        addCountry(line);
    }

    if (isTyrantDead()) {
        fprintf(outputFile, "The tyrant was killed!\n");
        fprintf(outputFile, "The last hit was done by: %s\n", lastHitCountry());
    } else fprintf(outputFile, "The tyrant wasn't killed.\n");
    fprintf(outputFile, "The strongest country was: %s\n", strongestCountry()->name);
    fprintf(outputFile, "The weakest country was: %s\n", weakestCountry()->name);
    if (couldCountryDefeatAlone() == 1) {
        fprintf(outputFile, "%s could have defeated all the sentinels.\n", strongestCountry()->name);
    } else {
        fprintf(outputFile, "No country could have defeated all the sentinels alone.\n");
        printBestCountryStats(outputFile);
    }

    fclose(inputFile);
    fclose(outputFile);

    return 0;
}