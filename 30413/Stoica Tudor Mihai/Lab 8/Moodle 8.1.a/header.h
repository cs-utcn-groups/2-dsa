#include <stdio.h>
#include <stdlib.h>

typedef struct objectStructure{

    int weight;
    int value;

}objectStructure;

int nrItems,capacity;

void read(FILE * in);
objectStructure * sortt(objectStructure * item,int nrItems);
void greedy(objectStructure * item,int nrItems,int capacity);
int maxi(int a, int b);
void dynamicProgramming(objectStructure * item,int nrItems,int capacity);
void outputMatrix(int ** matrix, int rows, int collumns);
