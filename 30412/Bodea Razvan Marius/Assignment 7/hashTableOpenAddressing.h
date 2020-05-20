#ifndef HASH_TABLES_HASHTABLEOPENADDRESSING_H
#include "list.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <math.h>
#include <stdbool.h>

static const float INITIAL_HT_SIZE_FACTOR = .50;
static const float MAX_FILL_FACTOR = .90;

char ** hashTable;
int size;
int noOfResizes;

int hashFunction(char * content, int i);
void initHashTable(int N);
float getFillFactor();
void resizeHashTable();
int insertElement(char * element);
int getMax(int a,int b);

int H1C(char * content,int i);
int H2C(char * content,int i);
int H3C(char * content,int i);


#define HASH_TABLES_HASHTABLEOPENADDRESSING_H

#endif //HASH_TABLES_HASHTABLEOPENADDRESSING_H
