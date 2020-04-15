#include <stdio.h>
#include <stdlib.h>

typedef struct objectStructure{

    int weight;
    int value;
    float dividedValue;

}objectStructure;

int capacity,totalWeight;
int newNrItems;

void read(FILE * in);
float maxi(float a, float b);
void dynamicProgramming(objectStructure * item,int nrItems,int capacity);
void outputMatrix(float ** matrix, int rows, int collumns);
objectStructure * splitIntoPieces(objectStructure * item, int nrItems);
