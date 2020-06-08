//
// Created by acer on 3/3/2020.
//

#ifndef ASSIGNMENT__1_2__HEAD_H
#define ASSIGNMENT__1_2__HEAD_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LIST 30

typedef struct _node {
    int damage;
    struct _node *next;
} Wave;

typedef struct _list {
    char *name;
    Wave *first, *last;
    int allDamage;
} Country;

FILE *input, *output;

Country *listOfCountries;

int *santinel;
int N, M;
int JimKongNuShield;
int maxDamage, minDamage, allDie;
char weakest[MAX_NAME_LIST], strongest[MAX_NAME_LIST], lastHit[MAX_NAME_LIST];

void printExtremasResult();
void verifyStrongestCountry(int copyJimKongShield);
void findExtremasLastHit();
void inputSentinels();
void inputCountriesWithWaves();
void addLastNode(int val, Wave **first, Wave **last);
void deleteFirstNode(Wave **first);
int waveExists();

#endif //ASSIGNMENT__1_2__HEAD_H
