//
// Created by Alex on 28.02.2020.
//

#ifndef EXTRA_ASIGMENT_1_COUNTRY_H
#define EXTRA_ASIGMENT_1_COUNTRY_H

#include <stdio.h>

typedef struct node {
    int val;
    struct node *next;
} waves;
typedef struct country {
    char *name;
    int nowaves;
    waves *first, *last;
}Country;

void createCountry(Country c);
void addwave(Country c, int x);


#endif //EXTRA_ASIGMENT_1_COUNTRY_H
