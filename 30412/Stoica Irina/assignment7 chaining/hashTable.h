#include "list.h"

static const float INITIAL_HT_SIZE_FACTOR = .35;

listT ** hashTable;
int sizeTable;

int H0();

int H1(char * content);

int H2(char * content);

int H3(char * content);

void initHashTable(int N);

void insertElement(char * element);

void computeDistributionsPerBucket(int N);

double computeStandardDeviation();

