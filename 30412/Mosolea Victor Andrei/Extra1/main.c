#include <stdio.h>
#include "countries.h"


int main() {
    FILE *f = fopen("../input.dat", "r");
    FILE *g = fopen("../output.dat", "w");
    int noOfSentinels;
    List sentinels = createList();
    readSentinelData(f, &noOfSentinels, &sentinels);
    int noOfCountries;
    fscanf(f, "%d", &noOfCountries);
    fgetc(f);
    Country *countries = (Country *) malloc(noOfCountries * sizeof(Country));
    readCountryData(f, noOfCountries, countries);
    for (int i = 0; i < noOfCountries; i++)
        countries[i].totalPower = totalPower(countries[i].waves);
    int totalSentinelPower = totalPower(sentinels);
    int successfulCountries = countriesByThemselves(noOfCountries, totalSentinelPower, countries, g);
    if (successfulCountries == 0) {
        fprintf(g, "No country could have defeated all the sentinels.\n");
        int mostPowerfulCountryIndex = mostPowerfulCountry(countries, noOfCountries);
        damageOfMostPowerfulCountry(sentinels, countries, mostPowerfulCountryIndex, g);
    }
    tyrantKilled(countries, sentinels, noOfCountries, g);
    int strongestIndex = strongestCountry(noOfCountries, countries);
    int weakestIndex = weakestCountry(noOfCountries, countries);
    fprintf(g, "The strongest country was: %s\n", countries[strongestIndex].name);
    fprintf(g, "The weakest country was: %s\n", countries[weakestIndex].name);

    return 0;
}


