//
// Created by Bori on 2/26/2020.
//

#ifndef EXTRA_ASSIGNMENT_1_COUNTRY_H
#define EXTRA_ASSIGNMENT_1_COUNTRY_H

#include "list.h"
#include "bunker.h"

#define MAX_NAME_LENGTH 100

typedef struct {
    char *name;
    list waves;
    int power;
} Country;

Country createCountry();

void readDataOfCountry(Country *myCountry, FILE *inFile);

void attackWithNextWave(Country *myCountry, Bunker *myBunker);

int hasRemainingWaves(Country *thisCountry);

int
canDefeatAlone(Country *myCountry, Bunker *myBunker, int *remainingPower); //nr of sentinels that he can defeat alone


#endif //EXTRA_ASSIGNMENT_1_COUNTRY_H
