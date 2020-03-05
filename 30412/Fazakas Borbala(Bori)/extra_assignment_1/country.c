//
// Created by Bori on 2/26/2020.
//

#include "country.h"
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1000

Country createCountry() {
    Country newCountry;
    newCountry.name = (char *) malloc(sizeof(char) * MAX_NAME_LENGTH);
    newCountry.waves = createList();
    return newCountry;
}

void readDataOfCountry(Country *myCountry, FILE *inFile) {
    char *line = (char *) malloc(sizeof(char) * MAX_LINE_LENGTH);
    fgets(line, MAX_LINE_LENGTH, inFile);
    const char s[1] = " ";
    char *token;

    /* get the first token */
    myCountry->name = strtok(line, s);

    /* walk through other tokens */
    while ((token = strtok(NULL, s)) != NULL) {
        addLast(&myCountry->waves, atoi(token));
    }

    myCountry->power = sumOfElements(&myCountry->waves);
}

int hasRemainingWaves(Country *thisCountry) {
    if (isEmpty(&thisCountry->waves))
    {
        return 0;
    }
    return 1;
}


static int min(int a, int b) {
    return a < b ? a : b;
}

void attackWithNextWave(Country *myCountry, Bunker *myBunker) {
    int nextPower = firstValue(&myCountry->waves);
    deleteFirst(&myCountry->waves);
    int usablePower;
    while (!isDefeated(myBunker) && nextPower > 0) {
        usablePower = min(nextPower, firstValue(&myBunker->sentinels));
        nextPower -= usablePower;
        if (usablePower >= firstValue(&myBunker->sentinels))
        {
            deleteFirst(&myBunker->sentinels);
        }
        else{
            subtractFromFirstValue(&myBunker->sentinels, usablePower);
        }
    }
}

int canDefeatAlone(Country *myCountry, Bunker *myBunker, int *remainingpower) {
    return noElementsWithSumSmallerOrEqual(&myBunker->sentinels, myCountry->power, remainingpower);
}