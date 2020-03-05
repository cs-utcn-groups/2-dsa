//
// Created by Bori on 2/26/2020.
//

#include "countries.h"
#include <stdlib.h>

allCountries createAllCountries() {
    allCountries myCountries;
    return myCountries;
}

void readDataOfAllCountries(allCountries *myCountries, FILE *inFile) {
    fscanf(inFile, "%d", &myCountries->noCountries);
    myCountries->countries = (Country *) malloc(sizeof(Country) * myCountries->noCountries);
    char c;
    while ((c = fgetc(inFile)) && c != '\n' && c != EOF);
    for (int i = 0; i < myCountries->noCountries; i++) {
        myCountries->countries[i] = createCountry();
        readDataOfCountry(&myCountries->countries[i], inFile);
    }
}

void attackWhileNeeded(allCountries *myCountries, Bunker *myBunker) {
    int nextCountryIndex = 0;
    int noRemainingCountries = myCountries->noCountries;
    int defeatedBunker = 0;
    while (!defeatedBunker && noRemainingCountries > 0) {
        if (hasRemainingWaves(&myCountries->countries[nextCountryIndex])) {
            attackWithNextWave(&myCountries->countries[nextCountryIndex], myBunker);
            if (isDefeated(myBunker)) {
                defeatedBunker = 1;
                myCountries->countryWithHBlow = myCountries->countries[nextCountryIndex];
            }
            if (!hasRemainingWaves(&myCountries->countries[nextCountryIndex])) {
                noRemainingCountries--;
            }
        }
        nextCountryIndex++;
        if (nextCountryIndex == myCountries->noCountries) nextCountryIndex = 0;
    }
}

Country strongestCountry(allCountries *myCountries) {
    Country result = myCountries->countries[0];
    for (int i = 1; i < myCountries->noCountries; i++) {
        if (myCountries->countries[i].power > result.power) {
            result = myCountries->countries[i];
        }
    }
    return result;
}


Country weakestCountry(allCountries *myCountries) {
    Country result = myCountries->countries[0];
    for (int i = 1; i < myCountries->noCountries; i++) {
        if (myCountries->countries[i].power < result.power) {
            result = myCountries->countries[i];
        }
    }
    return result;
}


