//
// Created by bindi on 3/8/2020.
//
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "list.h"

#define MAX_WORD_LENGTH 64
sentinelList *firstSentinel, *lastSentinel;
countryList *firstCountry, *lastCountry;

void initSentinelList(void) {
    firstSentinel = NULL;
    lastSentinel = NULL;
}

void initCountryList(void) {
    firstCountry = NULL;
    lastCountry = NULL;
}

void addSentinelLast(int x) {
    sentinelList *newSentinel = (sentinelList *) malloc(sizeof(sentinelList));
    newSentinel->data = x;
    newSentinel->next = NULL;
    if (firstSentinel == NULL) {
        ///list is empty
        firstSentinel = newSentinel;
        lastSentinel = newSentinel;
    } else {
        lastSentinel->next = newSentinel;
        lastSentinel = newSentinel;
    }
}

void addCountryLast(char *buffer) {
    countryList *newCountry = (countryList *) malloc(sizeof(countryList));
    newCountry->name = (char *) malloc(MAX_WORD_LENGTH * sizeof(char));
    strcpy(newCountry->name, buffer);
    newCountry->totalStrength = 0;
    newCountry->firstWave = NULL;///basically we initialize the wave list here
    newCountry->lastWave = NULL;
    newCountry->nextCountry = NULL;
    if (firstCountry == NULL) {
        ///countryList is empty
        firstCountry = newCountry;
        lastCountry = newCountry;
    } else {
        lastCountry->nextCountry = newCountry;
        lastCountry = newCountry;
    }
}

void addWaveLast(int waveDamage) {
    ///adds wave to the current(last added) country
    waveList *newWave = (waveList *) malloc(sizeof(waveList));
    newWave->data = waveDamage;
    newWave->next = NULL;
    if (lastCountry->firstWave == NULL) {
        ///list is empty
        lastCountry->firstWave = newWave;
        lastCountry->lastWave = newWave;
        lastCountry->totalStrength += newWave->data;
    } else {
        ///list not empty
        lastCountry->lastWave->next = newWave;
        lastCountry->lastWave = newWave;
        lastCountry->totalStrength += newWave->data;
    }
}

void computeBattle(FILE *output) {
    if (isSuccessful(output)) {
        findLastBlow(output);
    } else {
        fprintf(output, "No last hit was possible!\n");
    }
    countryList *bestCountry = findStrongest(output);
    findWeakest(output);
    int sentinelTotalHealth = calculateTotalEnemyHealth();
    if (bestCountry->totalStrength < sentinelTotalHealth) {
        ///we assume that the sentinels' strength is in ascending order
        findAlmostWon(output, bestCountry);
    } else {
        ///print every county that could've defeated the sentinels
        findSuccessfulCountries(output, sentinelTotalHealth);

    }
}

int isSuccessful(FILE *output) {
    int totalDamage = calculateTotalDamage();
    int sentinelTotalHealth = calculateTotalEnemyHealth();
    if (sentinelTotalHealth < totalDamage) {
        fprintf(output, "The tyrant was killed!\n");
        return 1;
    } else {
        fprintf(output, "The tyrant wasn't killed\n");
        return 0;
    }
}

void findLastBlow(FILE *output) {
    int totalSentinelHealth = calculateTotalEnemyHealth();
    char *lastBlowCountry = NULL;
    int wave = 0;
    while (totalSentinelHealth > 0) {
        countryList *currentCountry = firstCountry;
        waveList *currentWave = firstCountry->firstWave;
        while (totalSentinelHealth > 0 && currentCountry != NULL) {
            int auxWave = wave;
            while (auxWave) {
                ///get to the current wave
                ///countries may have a differing number of waves
                currentWave = currentWave->next;
                auxWave--;
            }
            if (currentWave != NULL) {
                totalSentinelHealth -= currentWave->data;
            }
            if (totalSentinelHealth <= 0) {
                lastBlowCountry = currentCountry->name;
            }
            currentCountry = currentCountry->nextCountry;///switch to next country
            if (currentCountry != NULL) {
                currentWave = currentCountry->firstWave;///switch to next country's first wave
            }
        }
        wave++;
    }
    fprintf(output, "The last hit was done by: %s\n", lastBlowCountry);
}

countryList *findStrongest(FILE *output) {
    countryList *currentCountry = firstCountry;
    int max = firstCountry->totalStrength;
    countryList *bestCountry = (countryList *) malloc(sizeof(countryList));
    while (currentCountry != NULL) {
        if (max < currentCountry->totalStrength) {
            max = currentCountry->totalStrength;
            (*bestCountry) = (*currentCountry);///make a copy of the best country
        }
        currentCountry = currentCountry->nextCountry;
    }
    fprintf(output, "The strongest country was: %s\n", bestCountry->name);
    return bestCountry;
}

void findWeakest(FILE *output) {
    countryList *currentCountry = firstCountry;
    int min = firstCountry->totalStrength;
    char *worstCountry = (char *) malloc(MAX_WORD_LENGTH * sizeof(char));
    while (currentCountry != NULL) {
        if (min > currentCountry->totalStrength) {
            min = currentCountry->totalStrength;
            strcpy(worstCountry, currentCountry->name);
        }
        currentCountry = currentCountry->nextCountry;
    }
    fprintf(output, "The weakest country was: %s\n", worstCountry);
}

void findAlmostWon(FILE *output, countryList *bestCountry) {
    fprintf(output, "No country could have defeated all the sentinels.\n");
    sentinelList *currentSentinel = firstSentinel;
    int countDefeated = 0;
    int remainingDamage = bestCountry->totalStrength;
    int lastDamage = 0;
    while (remainingDamage - (currentSentinel->data) > 0) {
        remainingDamage -= currentSentinel->data;
        countDefeated++;
        if (currentSentinel->next != NULL)currentSentinel = currentSentinel->next;
    }
    lastDamage = remainingDamage;
    fprintf(output, "%s could have brought down the first %d "
                    "sentinels\nand would have chipped off"
                    " %d life points from sentinel %d.", bestCountry->name,
            countDefeated, lastDamage, countDefeated + 1);
}

void findSuccessfulCountries(FILE *output, int sentinelTotalHealth) {
    fprintf(output, "Best Korea would have been single-handedly defeated by: ");
    countryList *currentCountry = firstCountry;
    while (currentCountry != NULL) {
        if (currentCountry->totalStrength > sentinelTotalHealth) {
            fprintf(output, "%s ", currentCountry->name);
        }
        currentCountry = currentCountry->nextCountry;
    }
}

int calculateTotalEnemyHealth(void) {
    sentinelList *currentSentinel = firstSentinel;
    int totalHealth = 0;
    while (currentSentinel != NULL) {
        totalHealth += currentSentinel->data;
        currentSentinel = currentSentinel->next;
    }
    return totalHealth;
}

int calculateTotalDamage(void) {
    countryList *currentCountry = firstCountry;
    int totalDamage = 0;
    while (currentCountry != NULL) {
        totalDamage += currentCountry->totalStrength;
        currentCountry = currentCountry->nextCountry;
    }
    return totalDamage;
}