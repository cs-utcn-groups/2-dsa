//
// Created by ileana on 5/8/2020.
//

#include "generateArray.h"

int * generateArrayOfNumbers(int lower, int upper, int count)
{
    int * array = (int *)malloc(sizeof(int)*count);
    for(int i=0; i<count; i++)
    {
        int randomNumber = (rand() %(upper - lower + 1)) + lower;
        array[i]=randomNumber;
    }
    return array;
}

int * copyArray(const int * a, int n)
{
    int * b= (int *)malloc(n* sizeof(int));
    for(int i=0;i<n;i++)
        b[i]=a[i];
    return b;
}