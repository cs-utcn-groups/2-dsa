//
// Created by Victor on 3/3/2020.
//

#ifndef EXTRA1_COUNTRIES_H
#define EXTRA1_COUNTRIES_H
#include "head.h"
#include <string.h>
#endif //EXTRA1_COUNTRIES_H

void readSentinelData(FILE *f, int *noOfSentinels, List *sentinels);

void readCountryData(FILE *f, int noOfCountries, Country *countries);

int totalPower(List waves);

int countriesByThemselves(int noOfCountries, int totalSentinelPower, Country *countries, FILE *g);

int mostPowerfulCountry(Country *countries, int noOfCountries);

void damageOfMostPowerfulCountry(List sentinels, Country *countries, int mostPowerfulCountryIndex, FILE *g);

void tyrantKilled(Country *countries, List sentinels, int noOfCountries, FILE *g);

int strongestCountry(int noOfCountries, Country *countries);

int weakestCountry(int noOfCountries, Country *countries);