//
// Created by Diana on 10/05/2020.
//

#ifndef ASSIGNMENT_7_2_HASHTABLE_H
#include "stdlib.h"
#include "io.h"
#include "string.h"

float INITIAL_HT_SIZE_FACTOR;
float MAX_FILL_FACTOR;

char ** hashTable;
int sizeHashTable;
int noOfResizes;
int state;

int hashFunction1(char * content, int i);
int hashFunction2(char * content, int i);
int hashFunction3(char * content, int i);
void initHashTable(int N);
float getFillFactor();
void resizeHashTable();
int insertElement(char * element);
#define ASSIGNMENT_7_2_HASHTABLE_H

#endif //ASSIGNMENT_7_2_HASHTABLE_H
