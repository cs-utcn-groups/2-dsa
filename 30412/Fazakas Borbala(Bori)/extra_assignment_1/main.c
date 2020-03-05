#include <stdio.h>
#include <stdlib.h>
#include "bunker.h"
#include "country.h"
#include "countries.h"

#define FILE_ERR_CODE 1
#define FILE_ERR_MESS "Error opening file"

FILE *openFile(char *name, char *mode) {
    FILE *newFile = fopen(name, mode);
    if (newFile == NULL) {
        perror(FILE_ERR_MESS);
        exit(FILE_ERR_CODE);
    }
    return newFile;
}

int main() {
    FILE *inFile = openFile("input.dat", "r");
    FILE *outFile = openFile("output.dat", "w");

    Bunker myBunker = createBunker();
    readDataOfBunker(&myBunker, inFile);
    allCountries myCountries = createAllCountries();
    readDataOfAllCountries(&myCountries, inFile);

    Country strongestC = strongestCountry(&myCountries);
    int remainingPowerOfStrongest; //the power that remains after defeating the last sentinel that he can defeat completely
    int strongestCanDefeatAlone = canDefeatAlone(&strongestC, &myBunker,
                                                 &remainingPowerOfStrongest); //number of sentinels that he can defeat completely alone
    int sizeOfBunker = size(
            &myBunker.sentinels); //number of sentinels in the bunker + 1 (Jim Kong-nu is stored as if he were a sentinel too, because logically there's no difference)

    attackWhileNeeded(&myCountries,
                      &myBunker); //simulates the attack as long as the bunker is not defeated and the countries have remaining waves

    if (isDefeated(&myBunker)) {
        fprintf(outFile, "The tyrant was killed!\n");
        fprintf(outFile, "The last hit was done by %s\n", myCountries.countryWithHBlow.name);
    } else {
        fprintf(outFile, "The tyrant was NOT killed!\n");
    }

    fprintf(outFile, "The strongest country was: %s\n", strongestC.name);
    fprintf(outFile, "The weakest country was: %s\n", weakestCountry(&myCountries).name);


    if (strongestCanDefeatAlone + 1 >=
        sizeOfBunker) {// +1 because he doesn't necessarily need to defeat Jim Kong-nu too, just the sentinels.
        // Obviously, if the strongest country can't defeat the bunker, thancountries with less power can't defeat it either --> it's eneugh to test it whether the strongest country can defeat it or not{
        fprintf(outFile, "The strongest country(%s) could have defeated all the sentinels alone\n", strongestC.name);
    } else {
        fprintf(outFile, "No country could have defeated all the sentinels.\n");
        fprintf(outFile,
                "%s could have brought down the first %d sentinels and would have had chipped off %d life points from sentinel %d.",
                strongestC.name, strongestCanDefeatAlone, remainingPowerOfStrongest, strongestCanDefeatAlone + 1);
    }

    return 0;
}