#include <stdio.h>
#include "io.h"
#include "bad_algorithms.h"
#include "good_algorithms.h"
#include "great_algorithms.h"
#define new_line printf("\n");

#define INPUT_FILE_NAME "../in.dat"

int main() {

    int N = 2000; // nr of elements
    FILE * inFile = openFile(INPUT_FILE_NAME, "w");
    createFile(N,inFile);
    inFile = openFile(INPUT_FILE_NAME, "r");
    int * array = readArray(inFile, &N);
    /*
     * measure how much time does the program take to run
     */
    clock_t start, stop;
    double elapsedTime;

    comparison = 0; assignment = 0; access = 0;

   printf("bubble sort:\n");
    start = clock();
    bubble_sort(N,array,ascending);
    stop = clock();
    printf("ascending order:");
    printArray(N,array);
    elapsedTime = (double) (stop - start) / CLOCKS_PER_SEC;
    printf("\nTime elapsed while performing bubble sort: %.8f\n", elapsedTime);

    printf("number of comparisons: %d\n",comparison);
    printf("number of accesses: %d\n",access);
    printf("number of assignments: %d\n",assignment);
    new_line

  /* comparison = 0; assignment = 0; access = 0;

    printf("selection sort:\n");
    start = clock();
    selection_sort(N,array,ascending);
    stop = clock();
    printf("ascending order:");
    printArray(N,array);
    elapsedTime = (double) (stop - start) / CLOCKS_PER_SEC;
    printf("\nTime elapsed while performing selection sort: %.5f\n", elapsedTime);

    printf("number of comparisons: %d\n",comparison);
    printf("number of accesses: %d\n",access);
    printf("number of assignments: %d\n",assignment);
    new_line

   comparison = 0; assignment = 0; access = 0;

    printf("insertion sort:\n");
    start = clock();
    insertion_sort(N,array,ascending);
    stop = clock();
    printf("ascending order:");
    printArray(N,array);
    elapsedTime = (double) (stop - start) / CLOCKS_PER_SEC;
    printf("\nTime elapsed while performing insertion sort: %.5f\n", elapsedTime);

    printf("number of comparisons: %d\n",comparison);
    printf("number of accesses: %d\n",access);
    printf("number of assignments: %d\n",assignment);
    new_line

   comparison = 0; assignment = 0; access = 0;

    printf("merge sort:\n");
    start = clock();
    merge_sort(array,0,N-1);
    stop = clock();
    printf("ascending order:");
    printArray(N,array);
    elapsedTime = (double) (stop - start) / CLOCKS_PER_SEC;
    printf("\nTime elapsed while performing merge sort: %.5f\n", elapsedTime);

    printf("number of comparisons: %d\n",comparison);
    printf("number of accesses: %d\n",access);
    printf("number of assignments: %d\n",assignment);
    new_line

   comparison = 0; assignment = 0; access = 0;

    printf("quick sort:\n");
    start = clock();
    quick_sort(array,0,N-1);
    stop = clock();
    printf("ascending order:");
    printArray(N,array);
    elapsedTime = (double) (stop - start) / CLOCKS_PER_SEC;
    printf("\nTime elapsed while performing quick sort: %.5f\n", elapsedTime);

    printf("number of comparisons: %d\n",comparison);
    printf("number of accesses: %d\n",access);
    printf("number of assignments: %d\n",assignment);
    new_line

   comparison = 0; assignment = 0; access = 0;

    printf("counting sort:\n");
    start = clock();
    counting_sort(N,array);
    stop = clock();
    printf("ascending order:");
    printArray(N,array);
    elapsedTime = (double) (stop - start) / CLOCKS_PER_SEC;
    printf("\nTime elapsed while performing counting sort: %.5f\n", elapsedTime);

    printf("number of comparisons: %d\n",comparison);
    printf("number of accesses: %d\n",access);
    printf("number of assignments: %d\n",assignment);
    new_line

    comparison = 0; assignment = 0; access = 0;

    printf("radix sort:\n");
    start = clock();
    radix_sort(N,array);
    stop = clock();
    printf("ascending order:");
    printArray(N,array);
    elapsedTime = (double) (stop - start) / CLOCKS_PER_SEC;
    printf("\nTime elapsed while performing radix sort: %.5f\n", elapsedTime);

    printf("number of comparisons: %d\n",comparison);
    printf("number of accesses: %d\n",access);
    printf("number of assignments: %d\n",assignment);
    new_line

*/
    return 0;
}