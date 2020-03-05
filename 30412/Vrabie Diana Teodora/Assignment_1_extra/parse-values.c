//
// Created by diana on 02/03/2020.
//

#include "parse-values.h"
#include <stdlib.h>
#include <stdio.h>

#define TYRANT_HP 1

int countTotalDamage();

int countCountryMight(Country *country);

int countTotalHitPoints();

int isTyrantDead() {
    int totalDamage = countTotalDamage();
    int totalHitPoints = countTotalHitPoints();
    if (totalDamage >= totalHitPoints) return 1;
    return 0;
}

int countTotalHitPoints() {
    int totalHP = 0;
    Sentinel *sentinel = firstSentinel;
    while (sentinel != NULL) {
        totalHP += sentinel->hitPoints;
        sentinel = sentinel->next;
    }
    return totalHP + TYRANT_HP;
}

char *lastHitCountry() {
    Country *country = firstCountry;
    int wavesToSkip = 0;
    int totalHitPoints = countTotalHitPoints();
    while (1) {
        Wave *wave = country->firstWave;
        for (int i = 0; i < wavesToSkip; ++i) {
            if (wave != NULL) {
                wave = wave->next;
            }
        }
        if (wave != NULL) {
            totalHitPoints -= wave->damage;
            if (totalHitPoints <= 0) {
                //isThisHitTheLast = 1;
                return country->name;
            }
        }
        if (country == lastCountry) {
            wavesToSkip++;
            country = firstCountry;
        } else {
            country = country->next;
        }
    }
}

Country *strongestCountry() {
    Country *country = firstCountry;
    Country *strongestCountry = firstCountry;
    int maxMight = 0;
    while (country != NULL) {
        int might = countCountryMight(country);
        if (might >= maxMight) {
            maxMight = might;
            strongestCountry = country;
        }
        country = country->next;
    }
    return strongestCountry;
}

int couldCountryDefeatAlone() {
    int totalHitPoints = countTotalHitPoints();
    Country *country = firstCountry;
    while (country != NULL) {
        int might = countCountryMight(country);
        if (might - totalHitPoints + TYRANT_HP >= 0) {
            return 1;
        }
        country = country->next;
    }
    return 0;
}

void printBestCountryStats(FILE *file) {
    Country *bestCountry = strongestCountry();
    Wave *wave = bestCountry->firstWave;
    int totalDamage = 0, chippedDamage = 0, chippedSentinelIndex = 0, destroyedSentinelNr = 0, currentSentinelIndex = 1;
    while (wave != NULL) {
        totalDamage += wave->damage;
        wave = wave->next;
    }
    Sentinel *sentinel = firstSentinel;
    while (totalDamage > 0) {
        totalDamage -= sentinel->hitPoints;
        if (totalDamage < 0) {
            chippedDamage = sentinel->hitPoints + totalDamage;
            chippedSentinelIndex = currentSentinelIndex;
        } else {
            destroyedSentinelNr++;
        }
        currentSentinelIndex++;
        sentinel = sentinel->next;
    }
    if (destroyedSentinelNr > 0) {
        if (chippedDamage > 0) {
            fprintf(file,
                    "%s could have brought down the first %d sentinels and would have chipped off %d life points from sentinel %d.\n",
                    bestCountry->name, destroyedSentinelNr, chippedDamage, chippedSentinelIndex);
        } else {
            fprintf(file, "%s could have brought down the first %d sentinels.\n", bestCountry->name,
                    destroyedSentinelNr);
        }
    } else {
        if (chippedDamage > 0) {
            fprintf(file, "%s could have chipped off %d life points from sentinel %d.\n", bestCountry->name,
                    chippedDamage,
                    chippedSentinelIndex);
        } else {
            fprintf(file, "%s could have done nothing.\n", bestCountry->name);
        }
    }
}

Country *weakestCountry() {
    Country *country = firstCountry;
    Country *weakestCountry = firstCountry;
    int minMight = 9999999;
    while (country != NULL) {
        int might = countCountryMight(country);
        if (might <= minMight) {
            minMight = might;
            weakestCountry = country;
        }
        country = country->next;
    }
    return weakestCountry;
}

int countTotalDamage() {
    int totalDamage = 0;
    Country *country = firstCountry;
    while (country != NULL) {
        Wave *wave = country->firstWave;
        while (wave != NULL) {
            totalDamage += wave->damage;
            wave = wave->next;
        }
        country = country->next;
    }
    return totalDamage;
}

int countCountryMight(Country *country) {
    Wave *wave = country->firstWave;
    int might = 0;
    while (wave != NULL) {
        might += wave->damage;
        wave = wave->next;
    }
    return might;
}

