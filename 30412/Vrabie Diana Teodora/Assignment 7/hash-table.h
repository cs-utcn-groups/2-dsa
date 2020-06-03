//
// Created by diana on 26/05/2020.
//

#ifndef ASSIGNMENT_7_HASH_TABLE_H
#define ASSIGNMENT_7_HASH_TABLE_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "io.h"

static const float INITIAL_HT_SIZE_FACTOR = .25;
static const float MAX_FILL_FACTOR = .80;

typedef struct _hashTable {
    char **hashT;
    int size;
    int nrOfElements;
} HashTable;

int nrOfResize;
int maxNrOfCollisions;

int hashFunction(char *content, int i, int size);

HashTable *initHashTable(int size);

float getFillFactor(HashTable *hashTable);

HashTable *resizeHashTable(HashTable *oldHashTable);

int insertElement(char *element, HashTable *hashTable);

#endif //ASSIGNMENT_7_HASH_TABLE_H
