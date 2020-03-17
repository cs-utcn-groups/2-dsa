#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void initializeSll();
void readSentinels(FILE *f,int *cts);
void addElement(int key);
void printSllData();


typedef struct node {
    int data;
    struct node * next;
} NodeT;

NodeT * firstS, * lastS ;

typedef struct cnrty{
    char *name;
    struct node * Fattack,*Lattack;
    struct cntry * next;
} Country;

Country *firstC,*lastC;
