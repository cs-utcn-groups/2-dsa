//
// Created by Ivan on 5/11/2020.
//

#include "sortingFunctions.h"
#include <stdbool.h>
#include <stdio.h>

///set t 'true' if you want the array to be sorted in ascending order and 'false' otherwise
//taken from the first set of sorting algorithms
//O(N^2) complexity
void bubbleSort(int arr[], int N, bool t)
{
    int n = 0;
    for(int i = 0; i < N; i++)
        for(int j = i; j < N; j++)
        {
            if((arr[i] > arr[j]) == t)
            {
                int aux = arr[i];
                arr[i] = arr[j];
                arr[j] = aux;
                n += 5;
            }
        }
    printf("Number of actions for bubbleSort: %d\n", n);
}

//utility function for quickSort algorithm
int partition (int arr[], int L, int H)
{
    int piv = arr[H];
    int i = (L - 1);

    for (int j = L; j <= H - 1; j++)
    {
        if (arr[j] < piv)
        {
            i++;
            int aux = arr[i];
            arr[i] = arr[j];
            arr[j] = aux;
        }
    }
    int aux = arr[i+1];
    arr[i+1] = arr[H];
    arr[H] = aux;
    return (i + 1);
}

//quickSort sorts the array in ascending order
//taken from the second set of sorting algorithms
//O(N*log(N)) complexity
int quickSort(int arr[], int L, int H)
{
    int static n = 0;
    if (L < H)
    {
        int q = partition(arr, L, H);
        quickSort(arr, L, q - 1);
        quickSort(arr, q + 1, H);
        n += 14;
    }
    return n;
}

//counting sort sorts the array in asceding order
//taken from the third set of sorting algorithms
//O(N+k) complexity
void countingSort(int arr[], int N) {
    int clone[10], n = 0;

    // Find the largest element of the arr
    int M = arr[0];
    for (int i = 1; i < N; i++) {
        if (arr[i] > M)
            M = arr[i];
        n++;
    }

    int count[10];

    for (int i = 0; i <= M; ++i) {
        count[i] = 0;
        n++;
    }

    for (int i = 0; i < N; i++) {
        count[arr[i]]++;
        n++;
    }

    for (int i = 1; i <= M; i++) {
        count[i] += count[i - 1];
        n++;
    }

    for (int i = N - 1; i >= 0; i--) {
        clone[count[arr[i]] - 1] = arr[i];
        count[arr[i]]--;
        n += 2;
    }

    for (int i = 0; i < N; i++) {
        arr[i] = clone[i];
        n++;
    }
    printf("Number of actions for countSort: %d\n", n);
}

void printArray(int arr[], int N)
{
    for(int i = 0; i < N; i++)
        printf("%d ", arr[i]);
}
