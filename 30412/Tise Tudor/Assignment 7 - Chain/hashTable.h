#include "list.h"
#include "stdlib.h"
#include <stdio.h>
#include <math.h>
#include <string.h>

static const float INITIAL_HT_SIZE_FACTOR = .85;

listT * hashTable;
int size;


int hash0(char *content);

int hash1(char * content);

int hash2(char * content);

int hash3(char * content);

void initHashTable(int N);

void insertElement(char * element);

void computeDistributionsPerBucket(int N);

float calculateSD(int N) ;


