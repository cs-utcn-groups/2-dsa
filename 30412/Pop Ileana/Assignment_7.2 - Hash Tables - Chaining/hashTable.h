#include "list.h"

static const float INITIAL_HT_SIZE_FACTOR = .85;

listT * hashTable;
int size;


int hashFunction1(char * content);

int hashFunction0(char * content);

int hashFunction2(char * content);

int hashFunction3(char * content);

int hashFunction3r(char * content);

int hashFunction4(char * content);

int hashFunction5(char * content);

void initHashTable(int N);

void insertElement(char * element,int (*hashFunction)(char *));

void computeDistributionsPerBucket(int N);

void computeStandardDeviation(int N);


