//
// Created by csatl on 5/5/2020.
//

#ifndef OPEN_ADDRESSING_HASHTABLE_H
#define OPEN_ADDRESSING_HASHTABLE_H

#include <stdbool.h>

static const float INITIAL_HT_SIZE_FACTOR = .50;
static const float MAX_FILL_FACTOR =        .90;

char ** hashTable;
int size;
int numberOfResizes;

int hashFunction(char * content, int i);

void initHashTable(int N);
float getFillFactor();
void resizeHashTable();
int insertElement(char * element);



#endif //OPEN_ADDRESSING_HASHTABLE_H
