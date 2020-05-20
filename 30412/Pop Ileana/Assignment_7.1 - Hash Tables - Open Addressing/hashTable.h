#include"io.h"
#include<stdlib.h>
#include<stdio.h>


static const float INITIAL_HT_SIZE_FACTOR = .50;
static const float MAX_FILL_FACTOR = .80;

char ** hashTable;
int size;
int maxNumberOfCollisions,resizes;

int hashFunction1(char * content, int i);

int hashFunction2(char * content, int i);

int hashFunction3(char * content, int i);

void initHashTable(int N);
float getFillFactor();
void resizeHashTable(int (*hash)(char*,int));
int insertElement(char * element,int (*hash)(char*,int));
