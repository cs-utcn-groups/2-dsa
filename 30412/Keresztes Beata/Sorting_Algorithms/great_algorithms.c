//
// Created by q on 5/7/2020.
//

#include "great_algorithms.h"
#include "io.h"


void radix_sort(int N, int * array) {
    int div = 1;
    int maxNumber = findGreatestNumber(N,array);
    while((maxNumber/div) > 0) {
        comparison++;
    sort_by_digit(N,div,array);
    div *= 10;
    }
}

void sort_by_digit(int N, int div, int * array) {
    int count[10]; // array for the digits
    // initialize count array
    for (int i = 0; i < 10; i++) {
        count[i] = 0;
        assignment++;
    }
    // calculate frequency of digits
    for (int i = 0; i < N; i++) {
        int index = (array[i] / div) % 10;
        count[index]++;
        access++;
        assignment++;
    }
    // update count array => each element holds the number of elements included so far => useful when sorting
    for (int i = 1; i < 10; i++) {
        count[i] += count[i - 1];
        assignment++;
        access++;
    }
    // new array in which the sorted elements are saved
    int * newArray = (int *) malloc(sizeof(int) * N);
    // sort the array
    for (int i = N-1; i >= 0; i--) {
        int index = (array[i] / div) % 10;
        count[index]--;
        newArray[count[index]] = array[i];
        assignment++;
        access++;
    }
   // update original array
   for(int i = 0; i < N; i++) {
       array[i] = newArray[i];
       assignment++;
       access++;
   }
   free(newArray);
}

int findGreatestNumber(int N, int * array) {
    // find the greatest element in the array
    int max = 0;
    for(int i = 0; i < N; i++) {
        if(array[i] > max) {
            max = array[i];
            assignment++;
        }
        comparison++;
        access++;
    }
    return max;
}

int getNumberOfDigits(int N) {
    // compute the number of digits
    int noOfDigits = 0;
    while(N) {
        N /= 10;
        noOfDigits++;
    }
    return noOfDigits;
}

int getMaxNumber(int N) {
    // calculate the greatest number of given digits
    int noOfDigits = getNumberOfDigits(N);
    int n = 0;
    for(int i = 0; i < noOfDigits;i++) {
       n = n*10 + 9;
    }
    return n;
}

void counting_sort(int N, int * array) {
    /*
     * counts the frequency of the elements which appear in the array
     */
     int max = getMaxNumber(N);
    int * count = (int *)malloc(max * sizeof(int));
    // initialize count array
    for(int i = 0; i < max;i++) {
        count[i] = 0;
        assignment++;
    }
    for(int i = 0; i < N; i++) {
        // count the occurrences of a number
        count[array[i]]++;
        access++;
        assignment++;
    }
    // reconstruct the array with the correct order of the elements
    int j = 0;
    for(int i = 0; i < max; i++) {
        while (count[i]) {
            array[j] = i;
            j++;
            count[i]--;
            comparison++;
            assignment++;
            access++;
        }
        access++;
    }
}