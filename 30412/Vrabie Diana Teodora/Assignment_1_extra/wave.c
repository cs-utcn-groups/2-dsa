//
// Created by diana on 01/03/2020.
//

#include "wave.h"
#include <stdlib.h>


void initializeWaveList(Wave **first, Wave **last) {
    *first = NULL;
    *last = NULL;
}

void addWave(Wave **first, Wave **last, int data) {
    if (*first == NULL) {
        *first = (Wave *) malloc(sizeof(Wave));
        (*first)->damage = data;
        (*first)->next = *last;
        *last = *first;
    } else {
        Wave *newWave = (Wave *) malloc(sizeof(Wave));
        newWave->next = NULL;
        newWave->damage = data;
        (*last)->next = newWave;
        *last = newWave;
    }
}
