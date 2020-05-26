//
// Created by diana on 26/05/2020.
//

#ifndef ASSIGNMENT_7_2_HASHTABLE_H
#define ASSIGNMENT_7_2_HASHTABLE_H

#include "list.h"
#include "stdio.h"

static const float INITIAL_HT_SIZE_FACTOR = .33;

listT *hashTable;
int size;


int hashFunction(char *content, int i);

void initHashTable(int N);

void insertElement(char *element, int i);

void computeDistributionsPerBucket();


#endif //ASSIGNMENT_7_2_HASHTABLE_H
