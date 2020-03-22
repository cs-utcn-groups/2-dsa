//
// Created by bindi on 3/8/2020.
//

#ifndef ASSIGNMENT_1___EXTRA_LIST_H
#define ASSIGNMENT_1___EXTRA_LIST_H

typedef struct _sentinelList {
    int data;
    struct _sentinelList *next;
} sentinelList, waveList;

typedef struct _countryList {///each country list element points to the beginning of the country's damage waves
    char *name;
    int totalStrength;
    struct _countryList *nextCountry;
    waveList *firstWave;
    waveList *lastWave;
} countryList;

void initSentinelList(void);

void initCountryList(void);

void addSentinelLast(int x);

void addCountryLast(char *buffer);

void addWaveLast(int waveDamage);

void computeBattle(FILE *output);

int isSuccessful(FILE *output);

void findLastBlow(FILE *output);

countryList *findStrongest(FILE *output);

void findWeakest(FILE *output);

void findAlmostWon(FILE *output, countryList *bestCountry);

void findSuccessfulCountries(FILE *output, int sentinelTotalHealth);

int calculateTotalEnemyHealth(void);

int calculateTotalDamage(void);

#endif //ASSIGNMENT_1___EXTRA_LIST_H
