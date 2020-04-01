#include <stdio.h>
#include <stdlib.h>
#define MAX_LENGTH 100

typedef struct cell
{
    char *Key;
}NodeT;

NodeT *BucketTable[MAX_LENGTH];

void Initialize();
void Insert(char *Key);
void Delete(char *Key);
int Find(char *Key);
void Print(FILE *g);
