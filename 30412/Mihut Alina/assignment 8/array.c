//
// Created by Alina Mihut on 5/10/20.
//
#include "array.h"
void readArray (FILE *fin)
{
    int n;
    fscanf(fin, "%d",  &n);
    sizeOfArray=n;
    array=(int*) malloc(n*sizeof(int));

    for(int i=0;i<n;i++)
        fscanf(fin, "%d", &array[i]);

}
void printArray()
{
    for (int i=0; i < sizeOfArray; i++)
        printf("%d ", array[i]);
    printf("\n");
}
