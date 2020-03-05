//
// Created by ileana on 3/2/2020.
//

#ifndef E1_FUNCTIONS_H
#define E1_FUNCTIONS_H

#include "sll.h"
#include <string.h>

void verifyIfKilled(int totalDamageNeeded, int noOfCountries,FILE * fptr);
void findLastHit(int noOfSentinels, int noOfCountries, FILE * fptr);
char * strongestCountry(int noOfCountries, int * position);
char * weakestCountry(int noOfCountries);
int verifyIfAllSentinels(int totalDamageNeeded, int noOfCountries);
int * bestCountryOverview(int noOfCountries, int position);



#endif //E1_FUNCTIONS_H
