#ifndef CHAINING_HASHTABLE_H
#define CHAINING_HASHTABLE_H

#include "io.h"
#include "list.h"
#include "stdlib.h"
#include "string.h"
#include "math.h"
#include "files.h"

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



#endif //CHAINING_HASHTABLE_H
