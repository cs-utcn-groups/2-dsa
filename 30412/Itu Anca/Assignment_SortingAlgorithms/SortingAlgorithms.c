//
// Created by Anca on 5/10/2020.
//
#include <stdio.h>
#include "SortingAlgorithms.h"

void swap(int *x, int *y){
    int temp = *x;
    *x = *y;
    *y = temp;
}

void printArray(int arr[], int size){
    int i;
    for(i = 0; i < size; i++){
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void bubbleSort(int arr[], int n){
    int i, j, nr=1;
    for(i = 0; i < n-1; i++){
        for(j = 0; j < n-i-1; j++){
            nr++;
            if(arr[j] > arr[j+1])
                swap(&arr[j], &arr[j+1]);
        }
    }
    printf("Number of comparisons: %d\n", --nr);
    printf("Number of iterations: %d\n", n-1);
}

void merge(int arr[], int p1, int m, int p2){
    int i, j, k;
    int n1 = m - p1 + 1;
    int n2 = p2 - m;

    int P1[n1], P2[n2];

    for(i = 0; i < n1; i++){
        P1[i] = arr[p1 + i];
        nrP1++;
    }
    for(j = 0; j < n2; j++){
        P2[j] = arr[m + 1 + j];
        nrP2++;
    }
    i = 0;
    j = 0;
    k = p1;
    while(i < n1 && j < n2){
        if(P1[i] <= P2[j]){
            arr[k] = P1[i];
            i++;
        }
        else{
            arr[k] = P2[j];
            j++;
        }
        k++;
        count1++;
    }

    while(i < n1){
        arr[k] = P1[i];
        i++;
        k++;
    }
    while(j < n2){
        arr[k] = P2[j];
        j++;
        k++;
    }
}

void mergeSort(int arr[], int p1, int p2){
    if(p1 < p2){
        int m = p1 + (p2 - p1)/2;

        mergeSort(arr, p1, m);
        mergeSort(arr, m + 1, p2);

        merge(arr, p1, m, p2);
    }
}

void countingSort(int arr[], int n) {
    int count[10];
    int nr=0, nr1 = 0;

    int max = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] > max)
            max = arr[i];
    }
    nr++;

    for (int i = 0; i <= max; i++) {
        count[i] = 0;
    }

    for (int i = 0; i < n; i++) {
        count[arr[i]]++;
    }
    nr++;

    int k = 0;
    for (int i = 0; i <= max; i++) {
        for (int j=1; j<=count[i]; ++j)
            arr[k++] = i;
    }
    nr1++;

    printf ("There are no comparisons. \n");
    printf ("Number of passes over the array: %d\n", nr);
    printf ("Number of passes over the frequency array: %d\n", nr1);
}

