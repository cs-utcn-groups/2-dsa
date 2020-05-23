#ifndef CHAINING_HASHTABLE_H
#define CHAINING_HASHTABLE_H

#include "io.h"
#include "stdlib.h"
#include "string.h"
#include "math.h"
#include "files.h"
static const float INITIAL_HT_SIZE_FACTOR = .50;
static const float MAX_FILL_FACTOR = .90;

typedef struct _hash {
    char **hashTable;
    int size;
    int nrElements; // nr of elements already added to the table
}hashT;

int maxCollisions; // max nr of collisions
int nrResize;   // nr of times a resize was needed

int getInitialSize(int N);
hashT * initHashTable(int N);

float getFillFactor(hashT * h);

hashT * resizeHashTable(hashT * oldH);

int insertElement(char * element, hashT * hashTable);

typedef enum hash_fct {hash1 = 1,hash2,hash3} hashF;
typedef int (fnp)(char *, int, int);

fnp * chooseFunction(hashF);
// hash functions
int h1(char * content, int i, int size);
int h2(char * content, int i, int size);
int h3(char * content, int i, int size);

// auxiliary functions
int isPrime(int n);

int getNewSize(int size);

void printHashTable(hashT * h);



#endif //CHAINING_HASHTABLE_H
