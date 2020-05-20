#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct pointStructure
{
    int x;
    int y;
}pointStructure;

pointStructure * point;
int nrPoints;

void read(FILE * in);
void sortByX(int left, int right);
void sortt(int left, int mid, int right);
double distance(pointStructure p0, pointStructure p1);
