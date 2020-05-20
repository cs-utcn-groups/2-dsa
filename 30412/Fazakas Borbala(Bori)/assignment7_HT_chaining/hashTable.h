//
// Created by Bori on 4/29/2020.
//

#ifndef ASSIGNMENT6_HT_CHAINING_HASHTABLE_H
#define ASSIGNMENT6_HT_CHAINING_HASHTABLE_H

#include "list.h"

static float INITIAL_HT_SIZE_FACTOR=100;

listT * hashTable;
int size;
int hashFunctionNr;

void setInitialSizeFactor(float factor);

int hashFunction0(char * content);

int hashFunction1(char * content);

int hashFunction2(char * content);

int hashFunction3(char * content);

int hashFunction4(char * content);

void initHashTable(int N, int functionNr);

void insertElement(char * element);

void computeDistributionsPerBucket(int n);

double standartDeviationOfBucketLengths();


#endif //ASSIGNMENT6_HT_CHAINING_HASHTABLE_H
