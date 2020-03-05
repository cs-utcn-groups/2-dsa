//
// Created by Victor on 3/3/2020.
//
#include "countries.h"
void readSentinelData(FILE *f, int *noOfSentinels, List *sentinels) {
    fscanf(f, "%d", noOfSentinels);
    for (int i = 0; i < *noOfSentinels; i++) {
        int sentinelLife;
        fscanf(f, "%d", &sentinelLife);
        addElementLast(sentinelLife, sentinels);
    }
}

void readCountryData(FILE *f, int noOfCountries, Country *countries) {
    char aux[MAX_LINE];
    for (int i = 0; i < noOfCountries; i++) {
        countries[i].totalDamage = 0;
        fgets(aux, MAX_LINE, f);
        char *pch = strtok(aux, " ");
        sscanf(pch, "%s", countries[i].name);
        pch = strtok(NULL, " ");
        countries[i].waves = createList();
        while (pch != NULL) {
            int wave;
            sscanf(pch, "%d", &wave);
            addElementLast(wave, &countries[i].waves);
            pch = strtok(NULL, " ");
        }
    }
}

int totalPower(List waves) {
    int totalPower = 0;
    Node *currentNode = waves.first;
    while (currentNode != NULL) {
        totalPower = totalPower + currentNode->data;
        currentNode = currentNode->next;
    }
    return totalPower;
}

int countriesByThemselves(int noOfCountries, int totalSentinelPower, Country *countries, FILE *g) {
    int successfulCountries = 0;
    for (int i = 0; i < noOfCountries; i++) {
        if (countries[i].totalPower > totalSentinelPower) {
            fprintf(g, "%s could have defeated all the sentinels\n", countries[i].name);
            successfulCountries++;
        }
    }
    return successfulCountries;
}

int mostPowerfulCountry(Country *countries, int noOfCountries) {
    int mostPowerfulCountryIndex = 0;
    for (int i = 1; i < noOfCountries; i++) {
        if (countries[i].totalPower > countries[mostPowerfulCountryIndex].totalPower)
            mostPowerfulCountryIndex = i;
    }
    return mostPowerfulCountryIndex;
}

void damageOfMostPowerfulCountry(List sentinels, Country *countries, int mostPowerfulCountryIndex, FILE *g) {
    int noOfDestroyedSentinels = 0;
    Node *currentNode = sentinels.first;
    int totalDamage = countries[mostPowerfulCountryIndex].totalPower;
    while (currentNode->data <= totalDamage) {
        totalDamage = totalDamage - currentNode->data;
        currentNode = currentNode->next;
        noOfDestroyedSentinels++;
    }
    fprintf(g,
            "%s could have brought down the first %d sentinels and would have had chipped off %d life points from sentinel %d.\n",
            countries[mostPowerfulCountryIndex].name, noOfDestroyedSentinels, totalDamage,
            noOfDestroyedSentinels + 1);
}

void tyrantKilled(Country *countries, List sentinels, int noOfCountries, FILE *g) {
    Node *currentNode = countries[0].waves.first;
    int currentCountry = 0;
    Node *currentSentinel = sentinels.first;
    while (currentSentinel != NULL && currentNode != NULL) {
        currentSentinel->data = currentSentinel->data - currentNode->data;
        if (currentSentinel->data < 0) {
            countries[currentCountry].totalDamage =
                    countries[currentCountry].totalDamage + currentSentinel->data + currentNode->data;
            currentNode->data = abs(currentSentinel->data);
            currentSentinel = currentSentinel->next;
        } else if (currentSentinel->data == 0) {
            countries[currentCountry].totalDamage = countries[currentCountry].totalDamage + currentNode->data;
            deleteFirst(&countries[currentCountry].waves);
            int noOfIterations = 0;
            do {
                if (currentCountry < noOfCountries - 1)
                    currentCountry++;
                else if (currentCountry == noOfCountries - 1)
                    currentCountry = 0;
                currentNode = countries[currentCountry].waves.first;
                noOfIterations++;
            } while (countries[currentCountry].waves.first == NULL && noOfIterations <= noOfCountries);
            currentSentinel = currentSentinel->next;
        } else if (currentSentinel->data > 0) {
            countries[currentCountry].totalDamage = countries[currentCountry].totalDamage + currentNode->data;
            deleteFirst(&countries[currentCountry].waves);
            int noOfIterations = 0;
            do {
                if (currentCountry < noOfCountries - 1)
                    currentCountry++;
                else if (currentCountry == noOfCountries - 1)
                    currentCountry = 0;
                currentNode = countries[currentCountry].waves.first;
                noOfIterations++;
            } while (countries[currentCountry].waves.first == NULL && noOfIterations < noOfCountries);
        }
    }
    if (currentSentinel == NULL && currentNode != NULL && currentNode->data >= 1)
        fprintf(g, "The tyrant was killed!\nThe last hit was done by %s!\n", countries[currentCountry].name);
    else fprintf(g, "The tyrant was not killed\n");
}

int strongestCountry(int noOfCountries, Country *countries) {
    int strongestIndex = 0;
    for (int i = 1; i < noOfCountries; i++)
        if (countries[i].totalDamage > countries[strongestIndex].totalDamage)
            strongestIndex = i;
    return strongestIndex;
}

int weakestCountry(int noOfCountries, Country *countries) {
    int weakestIndex = 0;
    for (int i = 1; i < noOfCountries; i++)
        if (countries[i].totalDamage < countries[weakestIndex].totalDamage)
            weakestIndex = i;
    return weakestIndex;
}

