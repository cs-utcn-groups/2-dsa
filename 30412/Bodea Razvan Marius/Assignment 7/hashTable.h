#ifndef HASH_TABLES_HASHTABLE_H
#include "list.h"
#include <stdlib.h>
#include <string.h>

static const float INITIAL_HT_SIZE_FACTOR = .33;
listT * hashTable;
int size;
int hashFunction(char * content, int i);
void initHashTable(int N);
void insertElement(char * element);
void computeDistributionsPerBucket();
int H1(char *content);
int H2(char *content);
int H3(char *content);

#define HASH_TABLES_HASHTABLE_H

#endif //HASH_TABLES_HASHTABLE_H
