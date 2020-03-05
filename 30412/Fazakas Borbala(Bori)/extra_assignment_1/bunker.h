//
// Created by Bori on 2/26/2020.
//

#ifndef EXTRA_ASSIGNMENT_1_BUNKER_H
#define EXTRA_ASSIGNMENT_1_BUNKER_H

#include "list.h"

typedef struct {
    list sentinels; //stores the remaining sentinels remaining power
    int jimKongNuPower;
} Bunker;

Bunker createBunker();

void readDataOfBunker(Bunker *myBunker, FILE *inFile);

int isDefeated(Bunker *thisBunker);


#endif //EXTRA_ASSIGNMENT_1_BUNKER_H
