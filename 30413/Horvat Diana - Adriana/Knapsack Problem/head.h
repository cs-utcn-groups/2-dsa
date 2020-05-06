#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_LENGTH 100

int *initializeArray();
float *initializeFloatArray();
void readFile(int *nrOfObjects, int *maxWeight, int *weight, int *value, FILE *f);
void valuePerWeightArray(float *valuePerWeight, int *weight, int *value, int *nrOfObjects);
float *initializeQuantity(float *quantity, int *nrOfObjects);
void quantityArray(int *nrOfObjects, int *maxWeight, int *valuePerWeightArray, int *weight, int *value, float *quantity);
void computeTheProfit(float *profit,float *quantity,int *nrOfObjects, int *value);
void computeTheWeight(int *weightSack, float *quantity, int *nrOfObjects, int *weight);
void print(FILE *g,int *weightSack, float *profit, float *quantity, int *nrOfObjects);
