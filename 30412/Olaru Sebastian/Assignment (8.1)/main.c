#include "sortingAlgo.h"

int main() {

    FILE *fout = fopen("output.dat","w");
    int arr[10000];
    int n = 10000;
    int noOfActions;

    initializeArray(arr, n, 0);
    selectionSort(arr, n);
    noOfActions = comp + assign + access;
    fprintf(fout,"Selection sort: %d actions done\n", noOfActions);
    printArray(fout,arr, n);

    initializeArray(arr, n, 1);
    quickSort(arr, 0, n - 1);
    noOfActions = comp + assign + access;
    fprintf(fout,"Quick sort: %d actions done\n", noOfActions);
    printArray(fout,arr, n);

    initializeArray(arr, n, 2);
    radixSort(arr, n);
    noOfActions = comp + assign + access;
    fprintf(fout,"Radix sort: %d actions done\n", noOfActions);
    printArray(fout,arr, n);

    return 0;
}