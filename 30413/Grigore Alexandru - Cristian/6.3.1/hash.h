#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define B 100

typedef struct cell{
    char name[30];
    struct cell *next;
}NodeT;

NodeT *Table[B];

int f(char *key);
NodeT *findNode(char *key);
NodeT *insertNode(char *key);
void deleteNode(char *key);
void printBucket();
