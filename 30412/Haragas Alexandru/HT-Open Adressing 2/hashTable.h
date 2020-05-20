//
// Created by Alex on 02.05.2020.
//

#ifndef HT_OPEN_ADRESSING_HASHTABLE_H
#define HT_OPEN_ADRESSING_HASHTABLE_H

#include <stdlib.h>
#include <string.h>
#include "io.h"

static const float INITIAL_HT_SIZE_FACTOR = 0.50;
static const float MAX_FILL_FACTOR = 0.90;

char ** hashTable;
long unsigned int size,maxcol;

int hashFunction(char * content, int i);

void initHashTable(int N);
float getFillFactor(int size);
void resizeHashTable();
int insertElement(char * element);



#endif //HT_OPEN_ADRESSING_HASHTABLE_H
