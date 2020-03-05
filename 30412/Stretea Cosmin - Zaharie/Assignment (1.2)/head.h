//
// Created by Cosmin on 04-Mar-20.
//

#ifndef ASSIGNMENT__1_2__HEAD_H
#define ASSIGNMENT__1_2__HEAD_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME 30

typedef struct _wave {
    int damage;
    struct _wave *next;
} wave;
typedef struct _country {
    char *name;
    wave *firstWave, *lastWave;
    int totalDamage;
} country;

FILE *input, *output;

country *countryList;
int *sentinel;
int N, M;
int JimKongShield;
int maxDamage, minDamage, killEmAll;
char weakest[MAX_NAME], strongest[MAX_NAME], lastHit[MAX_NAME];

void printResultWeakestStrongest();
void verifyStrongestCountry(int copyJimKongShield);
void findStrongestWeakestLastHit();
void getSentinelsShield();
void getCountriesAndWaves();
void addLastNode(int val, wave **first, wave **last);
void deleteFirstNode(wave **first);
int thereIsAWave();
void printAll();

#endif //ASSIGNMENT__1_2__HEAD_H
