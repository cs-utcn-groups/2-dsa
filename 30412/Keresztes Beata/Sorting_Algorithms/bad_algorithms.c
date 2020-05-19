//
// Created by q on 5/7/2020.
//

#include "bad_algorithms.h"

void swap(int * a, int * b) {
    int aux = *a;
    *a = *b;
    *b = aux;
}

void bubble_sort(int N, int * array, comp_fct compare) {
    /*
     * compare and swap consecutive elements
     * each time the largest / smallest element bubbles up, and next time, we only need to check the remaining ones
     */

    for(int k = N-1 ; k > 0; k--) {
        for (int i = 0; i < k; i++) {
            if (compare(array[i], array[i + 1])) {
               swap(&array[i],&array[i+1]);
               assignment++;
            }
            comparison++;
            access++;
        }
    }
}

bool ascending(int a, int b) {
    return a>b;
}
bool descending(int a, int b) {
    return a<b;
}

void selection_sort(int N, int * array, comp_fct compare) {
    /*
     * always select the min / max element and move it to the front => first k elements are sorted
     */
    for(int k = 0; k < N - 1; k++) {
        for(int i = k+1; i < N; i++) {
            if (compare(array[k], array[i])) {
                swap(&array[k],&array[i]);
                assignment++;
            }
            comparison++;
            access++;
        }
    }
}

void insertion_sort(int N, int * array, comp_fct compare) {
    /*
     * compare value with its previous elements and swap until found a smaller(ascending)/ greater(descending) one
     */
    for(int k = 1; k < N; k++) {
        int value = array[k];
        access++;
        int i = k;
        while(compare(array[i-1],value) && i > 0) {
            array[i] = array[i-1];
            i--;
            comparison++;
            assignment++;
            access++;
        }
        array[i] = value;
        assignment++;
        access++;
    }
}