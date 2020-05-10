//
// Created by Diana on 07/05/2020.
//

#ifndef ASSIGNMENT_7_1_HASHTABLE_H

#include "io.h"
#include "list.h"
#include "stdlib.h"
#include "string.h"
#include "math.h"
#include "files.h"

float INITIAL_HT_SIZE_FACTOR;

listT * hashTable;
int sizeHashTable;
int state;

int hashFunction0(const char *content);
int hashFunction1(char * content);
int hashFunction2(char * content);
int hashFunction3(char * content);

listT * initHashTable(int N);

void insertElement(char * element);

void computeDistributionsPerBucket(int N);

double calculateStandardDeviation ();

#define ASSIGNMENT_7_1_HASHTABLE_H

#endif //ASSIGNMENT_7_1_HASHTABLE_H
