//
// Created by q on 5/7/2020.
//

#include "good_algorithms.h"
#include "io.h"
#include "bad_algorithms.h"

void merge_sort(int * array, int left, int right) {
    /*
     * divide the array in sub_arrays which will be sorted separately and merged in the end
     * sorting in ascending order
     */
    if(left < right) {
        int middle = (right + left) / 2;
        if(left < middle) {
            merge_sort(array, left, middle);
            comparison++;
        }
        if(middle + 1 < right) {
            merge_sort(array, middle + 1, right);
            comparison++;
        }
        merge(array,left,middle,right);
    }
}

void merge(int * array, int left, int middle, int right) {
    // copy the contents of the sub arrays, then merge them in order back in the initial array
    int size1 = middle - left + 1;
    int * l = (int*)malloc(sizeof(int) * size1);    // left sub array
    for(int i = 0; i < size1; i++) {
        l[i] = array[left + i];
        access++;
        assignment++;
    }
    int size2 = right - middle;
    int * r = (int*)malloc(sizeof(int) * size2);    // right sub array
    for(int i = 0; i < size2; i++) {
        r[i] = array[middle + 1 + i];
        access++;
        assignment++;
    }
    int i1 = 0, i2 = 0, i = left;   // i = index of the array from which the merge is performed
    while(i1 < size1 && i2 < size2) {
        if(l[i1] < r[i2]) {
            array[i] = l[i1]; i1++;
        }
        else {
            if(l[i1] > r[i2]) {
                array[i] = r[i2]; i2++;
            }
            else {
               array[i] = l[i1]; i1++; i2++;
            }
        }
        i++;
        comparison++;
        access++;
        assignment++;
    }
    while(i1 < size1) {
        array[i] = l[i1]; i1++; i++;
        assignment++;
        access++;
    }
    while(i2 < size2) {
        array[i] = r[i2]; i2++; i++;
        assignment++;
        access++;
    }
    free(l);
    free(r);
}

void quick_sort(int * array, int left, int right) {
    if(left < right) {
        int pivot = partition_last(array, left, right);
        if (left < pivot - 1) {
            quick_sort(array, left, pivot - 1);
            comparison++;
        }
        if (pivot + 1 < right) {
            quick_sort(array, pivot + 1, right);
            comparison++;
        }
    }
}

int partition_last(int * array, int left, int right) {
    // pick pivot as last element
    int pivot = array[right];
    int i = left;
    for(int j = left; j < right; j++) {
        if(array[j] < pivot) {
            swap(&array[i],&array[j]);
            i++;
            comparison++;
            assignment++;
            access++;
        }
    }
    swap(&array[i],&array[right]);
    assignment++;
    access++;
    return i;
}

int partition_middle(int * array, int left, int right) {
    // pick pivot as middle element
    int pi = (left + right) / 2;
    int pivot = array[pi];
    access++;
    int i = left, j = right;
    while(i <= j) {
        while(array[i] < pivot) {
            i++;
            comparison++;
            assignment++;
        }
        while(array[j] > pivot) {
            j--;
            comparison++;
            assignment++;
        }
        if(i <= j) {
            swap(&array[i],&array[j]);
            i++; j--;
            comparison++;
            assignment++;
        }
    }
    return i;
}