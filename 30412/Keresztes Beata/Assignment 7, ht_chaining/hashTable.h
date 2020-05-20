//
// Created by q on 5/1/2020.
//

#ifndef ASSIGNMENT_7__HT_CHAINING_HASHTABLE_H
#define ASSIGNMENT_7__HT_CHAINING_HASHTABLE_H
#include "list.h"
#include <math.h>

static const float INITIAL_HT_SIZE_FACTOR = .75;

listT * hashTable;
int size;

typedef enum hash_fct {hash0,hash1,hash2,hash3} hashF;

int hashFunction(char * content, hashF h);

int h0(char * content);  // bad hash function
int h1(char * content); // example
int h2(char * content);
int h3(char * content);

void initHashTable(int N);

void insertElement(char * element);

void computeDistributionsPerBucket(int N);

void printHashTable();

double calculateStandardDeviation(int N);

long int calculateAverage(int N);

#endif //ASSIGNMENT_7__HT_CHAINING_HASHTABLE_H
