#include "list.h"
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdio.h>

static const float INITIAL_HT_SIZE_FACTOR = .85;

listT ** hashTable;
int size;


int hashFunction(char * content);

void initHashTable(int N);

void insertElement(char * element);

double computeDistributionsPerBucket();


