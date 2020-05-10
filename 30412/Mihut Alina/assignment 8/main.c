#include <stdio.h>
#include "array.h"
#include "sortingAlgorithms.h"
int main() {

    FILE *fin;
    fin=fopen("../input.txt", "r");
    readArray(fin);
    char choice;
    printf("Please choose the sorting algorithm you wish for the program to execute \n");
    printf (" B - Bubble sort \n M - Merge sort \n R - Radix sort \n");
    choice=getchar();
    switch(choice)
    {
        case 'B':
            bubbleSort();
            break;
        case 'M':
            mergeSort();
            break;
        case 'R':
            radixSort();
            break;
    }
    return 0;

}


