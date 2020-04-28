//
// Created by Bori on 4/29/2020.
//

#ifndef ASSIGNMENT6_HT_CHAINING_HASHTABLE_H
#define ASSIGNMENT6_HT_CHAINING_HASHTABLE_H

#include "list.h"

static const float INITIAL_HT_SIZE_FACTOR = .33;

listT * hashTable;
int size;


int hashFunction(char * content, int i);

void initHashTable(int N);

void insertElement(char * element);

void computeDistributionsPerBucket();


#endif //ASSIGNMENT6_HT_CHAINING_HASHTABLE_H
