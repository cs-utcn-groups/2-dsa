//
// Created by Alina Mihut on 5/2/20.
//

#ifndef HASH_TABLES__CHAINING_HASHTABLE_H

#include "list.h"
#include "math.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
static const float INITIAL_HT_SIZE_FACTOR = .50;

listT *hashTable;
int size;



        void initHashTable(int N);

void insertElement(char * element);

void computeDistributionsPerBucket(int N, char **content);

void computeStandardDeviation();

int hashFunction0();
int hashFunction1(char * content);
int hashFunction2 (char *content);
#define HASH_TABLES__CHAINING_HASHTABLE_H

#endif //HASH_TABLES__CHAINING_HASHTABLE_H
