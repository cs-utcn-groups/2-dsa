#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define B 50
#define MAX_LENGTH 100
#define A 17


typedef struct cell
{
    char key[60];
    struct cell *next;
} CellT;
CellT *HashTable[B];

int f(char *key);
void initializeHash(CellT *HashTable[B]);
CellT *create(char *key);
void insertKey(char *key);
char *findKey(char *key);
void deleteKey(char *key, FILE *g);
void listTable(FILE *g);
char **readFile(FILE *f, int *n);
char **initializeBuffer();
void processCommandsFromInputData(char **buffer,int *n,FILE *g);
