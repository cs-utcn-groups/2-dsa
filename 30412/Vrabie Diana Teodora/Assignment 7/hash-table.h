//
// Created by diana on 26/05/2020.
//

#ifndef ASSIGNMENT_7_HASH_TABLE_H
#define ASSIGNMENT_7_HASH_TABLE_H

static const float INITIAL_HT_SIZE_FACTOR = .25;
static const float MAX_FILL_FACTOR = .80;

char ** hashTable;
int size;


int hashFunction(char * content, int i);

void initHashTable(int N);
float getFillFactor();
void resizeHashTable();
int insertElement(char * element);

#endif //ASSIGNMENT_7_HASH_TABLE_H
