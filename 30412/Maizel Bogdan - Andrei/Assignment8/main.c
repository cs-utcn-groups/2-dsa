#include <stdio.h>
#include <stdlib.h>

int noOfComp, noOfAssign, noOfAccess;

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void selectionSort(int arr[], int n) {
    int i, j, min_idx;
    for (i = 0; i < n - 1; i++) {
        min_idx = i;
        for (j = i + 1; j < n; j++) {
            if (arr[j] < arr[min_idx]) {
                min_idx = j;
            }
            noOfComp++;
            noOfAccess += 2;
        }
        swap(&arr[min_idx], &arr[i]);
        noOfAssign += 3;
        noOfAccess += 4;
    }
}

int partition(int arr[], int low, int high) {
    int pivot = arr[high];
    int i = (low - 1);
    noOfAssign += 2;

    for (int j = low; j <= high - 1; j++) {
        if (arr[j] < pivot) {
            i++;
            swap(&arr[i], &arr[j]);
            noOfAssign += 3;
            noOfAccess += 4;
        }
        noOfComp++;
        noOfAccess++;
    }
    swap(&arr[i + 1], &arr[high]);
    noOfAccess += 4;
    noOfAssign += 3;
    return (i + 1);
}

void quickSort(int arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

int getMax(int arr[], int n) {
    int mx = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] > mx) {
            mx = arr[i];
            noOfAccess++;
            noOfAssign++;
        }
        noOfComp++;
        noOfAccess++;
    }
    return mx;
}

void countSort(int arr[], int n, int exp) {
    int output[n];
    int i, count[10] = {0};
    for (i = 0; i < n; i++) {
        count[(arr[i] / exp) % 10]++;
        noOfAccess++;
    }
    for (i = 1; i < 10; i++)
        count[i] += count[i - 1];
    for (i = n - 1; i >= 0; i--) {
        output[count[(arr[i] / exp) % 10] - 1] = arr[i];
        count[(arr[i] / exp) % 10]--;
        noOfAccess += 3;
    }
    for (i = 0; i < n; i++) {
        arr[i] = output[i];
        noOfAccess++;
        noOfAssign++;
    }
}

void radixSort(int arr[], int n) {
    int m = getMax(arr, n);
    for (int exp = 1; m / exp > 0; exp *= 10)
        countSort(arr, n, exp);
}

void printArray(int arr[], int size) {
    int i;
    for (i = 0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

int main() {
    int arr1[] = {40, 42, 77, 74, 20};
    int n1 = sizeof(arr1) / sizeof(arr1[0]);
    noOfComp = noOfAssign = noOfAccess = 0;
    selectionSort(arr1, n1);
    printf("Selection sort:\n%d comparisons\n%d assignments\n%d acceses\n", noOfComp, noOfAssign, noOfAccess);
    printArray(arr1, n1);

    int arr2[] = {40, 42, 77, 74, 20};
    int n2 = sizeof(arr2) / sizeof(arr2[0]);
    noOfComp = noOfAssign = noOfAccess = 0;
    quickSort(arr2, 0, n2 - 1);
    printf("Quick sort:\n%d comparisons\n%d assignments\n%d acceses\n", noOfComp, noOfAssign, noOfAccess);
    printArray(arr2, n2);

    int arr3[] = {40, 42, 77, 74, 20};
    int n3 = sizeof(arr3) / sizeof(arr3[0]);
    noOfComp = noOfAssign = noOfAccess = 0;
    radixSort(arr3, n3);
    printf("Radix sort:\n%d comparisons\n%d assignments\n%d acceses\n", noOfComp, noOfAssign, noOfAccess);
    printArray(arr3, n3);
    return 0;
}