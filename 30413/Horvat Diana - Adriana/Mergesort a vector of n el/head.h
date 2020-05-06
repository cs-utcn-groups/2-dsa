#include <stdio.h>
#include <stdlib.h>
#define MAX_LENGTH 100

void readFile(FILE *f,int *n);
void merge(int *n,int lBound,int mid,int rBound);
void mergesort(int *n,int lBound,int rBound);
void printArray(int *n);
