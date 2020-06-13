#ifndef CHAINING_HASHTABLE_H
#define CHAINING_HASHTABLE_H

#include "list.h"

static const float INITIAL_HT_SIZE_FACTOR = .85;

listT * hashTable;
int size;


int hashFunction(char * content);

void initHashTable(int N);

void insertElement(char * element);

void computeDistributionsPerBucket(int N);

#endif //CHAINING_HASHTABLE_H
