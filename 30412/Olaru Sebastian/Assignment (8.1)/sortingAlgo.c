//
// Created by acer on 6/2/2020.
//

#include "sortingAlgo.h"

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int partition(int arr[], int low, int high) {
    int pivot = arr[high];    // pivot
    int i = (low - 1);  // Index of smaller element
    assign += 2;

    for (int j = low; j <= high - 1; j++) {
        // If current element is smaller than the pivot
        if (arr[j] < pivot) {
            i++;    // increment index of smaller element
            swap(&arr[i], &arr[j]);
            assign += 3;
            access += 4;
        }
        comp++;
        access++;
    }
    swap(&arr[i + 1], &arr[high]);
    access += 4;
    assign += 3;
    return (i + 1);
}

int getMax(int arr[], int n) {
    int mx = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] > mx) {
            mx = arr[i];
            access++;
            assign++;
        }
        comp++;
        access++;
    }
    return mx;
}

void selectionSort(int arr[], int n) {
    int i, j, min_idx;
    // One by one move boundary of unsorted subarray
    for (i = 0; i < n - 1; i++) {
        // Find the minimum element in unsorted array
        min_idx = i;
        for (j = i + 1; j < n; j++) {
            if (arr[j] < arr[min_idx]) {
                min_idx = j;
            }
            comp++;
            access += 2;
        }
        // Swap the found minimum element with the first element
        swap(&arr[min_idx], &arr[i]);
        assign += 3;
        access += 4;
    }
}

void quickSort(int arr[], int low, int high) {
    if (low < high) {
        /* pi is partitioning index, arr[p] is now
           at right place */
        int pi = partition(arr, low, high);

        // Separately sort elements before
        // partition and after partition
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

// A function to do counting sort of arr[] according to
// the digit represented by exp.
void countSort(int arr[], int n, int exp) {
    int output[n]; // output array
    int i, count[10] = {0};

    // Store count of occurrences in count[]
    for (i = 0; i < n; i++) {
        count[(arr[i] / exp) % 10]++;
        access++;
    }

    // Change count[i] so that count[i] now contains actual
    //  position of this digit in output[]
    for (i = 1; i < 10; i++)
        count[i] += count[i - 1];

    // Build the output array
    for (i = n - 1; i >= 0; i--) {
        output[count[(arr[i] / exp) % 10] - 1] = arr[i];
        count[(arr[i] / exp) % 10]--;
        access += 3;
    }

    // Copy the output array to arr[], so that arr[] now
    // contains sorted numbers according to current digit
    for (i = 0; i < n; i++) {
        arr[i] = output[i];
        access++;
        assign++;
    }
}


void radixSort(int arr[], int n) {
    // Find the maximum number to know number of digits
    int m = getMax(arr, n);

    // Do counting sort for every digit. Note that instead
    // of passing digit number, exp is passed. exp is 10^i
    // where i is current digit number
    for (int exp = 1; m / exp > 0; exp *= 10)
        countSort(arr, n, exp);
}

void printArray(FILE *f, int arr[], int size) {
    int i;
    for (i = 0; i < size; i++)
        fprintf(f, "%d ", arr[i]);
    fprintf(f, "\n");
}

void randomNumberArray(int arr[], int n, int seed) {
    srand(seed);
    for (int i = 0; i < n; i++) {
        arr[i] = rand();
    }
}

void initializeArray(int arr[], int n, int seed) {
    randomNumberArray(arr, n, seed);
    comp = assign = access = 0;
}