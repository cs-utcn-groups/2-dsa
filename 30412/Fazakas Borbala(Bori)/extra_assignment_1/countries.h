//
// Created by Bori on 2/26/2020.
//

#ifndef EXTRA_ASSIGNMENT_1_COUNTRIES_H
#define EXTRA_ASSIGNMENT_1_COUNTRIES_H

#include "country.h"
#include "bunker.h"

typedef struct {
    int noCountries;
    Country *countries;
    Country countryWithHBlow;
} allCountries;

allCountries createAllCountries();

void readDataOfAllCountries(allCountries *myCountries, FILE *inFile);

void attackWhileNeeded(allCountries *myCountries, Bunker *myBunker);

Country strongestCountry(allCountries *myCountries);

Country weakestCountry(allCountries *myCountries);

#endif //EXTRA_ASSIGNMENT_1_COUNTRIES_H
