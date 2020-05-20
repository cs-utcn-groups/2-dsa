#include <stdio.h>
#include <stdlib.h>

void merge(int *arr, int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;

    //create temporary arrays
    int L[n1], R[n2];
    //copy data into them
    for (int i = 0; i < n1; i++)
        L[i] = arr[left + i];
    for (int j = 0; j < n2; j++)
        R[j] = arr[mid + 1 + j];
    int i = 0, j = 0;
    int k = left;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }
    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }

}

void prettyPrint(int *array, int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");
}

void mergeSort(int *arr, int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);

        merge(arr, left, mid, right);
    }

}

int main() {
    int *initialArray = (int *) malloc(sizeof(int) * 25);
    int nrOfElements;
    printf("Enter the number of elements in the array:");
    scanf("%d", &nrOfElements);
    for (int i = 0; i < nrOfElements; i++) {
        printf("Array[%d] = ", i + 1);
        scanf("%d", &initialArray[i]);
    }
    prettyPrint(initialArray, nrOfElements);
    mergeSort(initialArray, 0, nrOfElements-1);
    prettyPrint(initialArray, nrOfElements);

    return 0;
}
