#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LENGTH 200
#define A 17
#define B 20

typedef struct cell
{
    char key[60];
    struct cell *next;
} CellT;
CellT *bucketTable[B];

void initializeBucket(CellT *bucketTable[B]);
int f(char *key);
CellT *create(char *key);
void insertKey(char *key);
void listTable(FILE *g);
char *findKey(char *key);
void deleteKey(char *key, FILE *g);
void processCommandsFromInputData(char **inputData, int *n, FILE *g);
char **initializeBuffer();
char **readFile(FILE *f, int *n);
