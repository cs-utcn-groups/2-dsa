#include "list.h"

static const double SIZE_FACTORS[]={
        .10,
        .20,
        .35,
        .50,
        .75,
        .85
};

double INITIAL_HT_SIZE_FACTOR;

listT * hashTable;
int size;

int hashFunction0(const char * content);
int hashFunction1(const char * content);
int hashFunction2(const char * content);
int hashFunction3(const char * content);

void initHashTable(int N);

void insertElement(char * element, int function);

void computeDistributionsPerBucket(int N);

void getStandardDeviation();
