//
// Created by diana on 01/03/2020.
//

#include "country.h"
#include <stdlib.h>
#include <string.h>

void initializeCountryList() {
    firstCountry = NULL;
    lastCountry = NULL;
}

void addCountry(char line[100]) {
    if (firstCountry == NULL) {
        firstCountry = (Country *) malloc(sizeof(Country));
        strcpy(firstCountry->name, strtok(line, " "));
        initializeWaveList(&firstCountry->firstWave, &firstCountry->lastWave);
        char *p = strtok(NULL, "");
        firstCountry->nrOfWaves = 0;
        while (p != NULL) {
            char *nrPtr = strtok(p, " "), *aux;
            p = strtok(NULL, "");
            addWave(&firstCountry->firstWave, &firstCountry->lastWave, strtol(nrPtr, &aux, 10));
            firstCountry->nrOfWaves++;
        }
        firstCountry->next = lastCountry;
        lastCountry = firstCountry;
    } else {
        Country *newCountry = (Country *) malloc(sizeof(Country));
        lastCountry->next = newCountry;
        newCountry->next = NULL;
        strcpy(newCountry->name, strtok(line, " "));
        initializeWaveList(&newCountry->firstWave, &newCountry->lastWave);
        char *p = strtok(NULL, "");
        newCountry->nrOfWaves = 0;
        while (p != NULL) {
            char *nrPtr = strtok(p, " "), *aux;
            p = strtok(NULL, "");
            addWave(&newCountry->firstWave, &newCountry->lastWave, strtol(nrPtr, &aux, 10));
            newCountry->nrOfWaves++;
        }
        lastCountry = newCountry;
    }
}
