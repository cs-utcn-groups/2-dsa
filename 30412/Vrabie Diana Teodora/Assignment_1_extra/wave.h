//
// Created by diana on 01/03/2020.
//

#ifndef ASSIGNMENT_1_EXTRA_WAVE_H
#define ASSIGNMENT_1_EXTRA_WAVE_H

typedef struct _Wave {
    int damage;
    struct _Wave *next;
} Wave;

void initializeWaveList(Wave **first, Wave **last);

void addWave(Wave **first, Wave **last, int data);

#endif //ASSIGNMENT_1_EXTRA_WAVE_H
