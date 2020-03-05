//
// Created by diana on 02/03/2020.
//

#ifndef ASSIGNMENT_1_EXTRA_PARSE_VALUES_H
#define ASSIGNMENT_1_EXTRA_PARSE_VALUES_H

#include <stdio.h>
#include "wave.h"
#include "country.h"
#include "sentinel.h"

int isTyrantDead();

char *lastHitCountry();

Country * strongestCountry();

Country * weakestCountry();

int couldCountryDefeatAlone();

void printBestCountryStats(FILE *file);


#endif //ASSIGNMENT_1_EXTRA_PARSE_VALUES_H
