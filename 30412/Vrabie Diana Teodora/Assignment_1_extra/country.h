//
// Created by diana on 01/03/2020.
//

#ifndef ASSIGNMENT_1_EXTRA_COUNTRY_H
#define ASSIGNMENT_1_EXTRA_COUNTRY_H

#include "wave.h"

typedef struct _Country {
    char name[20];
    int nrOfWaves;
    Wave *firstWave, *lastWave;
    struct _Country *next;
} Country;

Country *firstCountry, *lastCountry;

void initializeCountryList();

void addCountry(char name[20]);


#endif //ASSIGNMENT_1_EXTRA_COUNTRY_H
