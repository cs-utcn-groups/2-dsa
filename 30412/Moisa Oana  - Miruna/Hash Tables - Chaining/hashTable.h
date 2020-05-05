#include "list.h"

static const float INITIAL_HT_SIZE_FACTOR = .10;
listT *hashTable;
int size;


int hashFunction(char * content);
int badHashFunction(char * content);

void initHashTable(int N);

void insertElement(char * element);

void computeDistributionsPerBucket(int N);

void standardDeviation();




