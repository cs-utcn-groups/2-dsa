  
#ifndef ASSIGNMENT_8_ALG_H

int comparisions;
int assignmets;
int acces;
int size, *a;
int *frequencyArray;
int *table;

void allocate();
void insertionSort( int *a, int n);
int partition (int *a, int low, int high);
void quicksort(int *a, int low, int high);
void countingSort( int *a, int n);

#define ASSIGNMENT_8_ALG_H

#endif