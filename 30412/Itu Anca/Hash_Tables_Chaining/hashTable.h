//
// Created by Anca on 5/2/2020.
//

#ifndef HASH_TABLES_CHAINING_HASHTABLE_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "list.c"

static const float INITIAL_HT_SIZE_FACTOR = .33;

listT * hashTable;
int size;

int hashFunction0(char * content);

int hashFunction1(char * content);

int hashFunction2(char * content);

int hashFunction3(char * content);

int hashFunction4(char * content);

void initHashTable(int N);

void insertElement(char * element);

void computeDistributionsPerBucket(int N);

double standardDeviation(int N);

#define HASH_TABLES_CHAINING_HASHTABLE_H

#endif //HASH_TABLES_CHAINING_HASHTABLE_H
