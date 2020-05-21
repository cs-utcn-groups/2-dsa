#include <stdio.h>
#include <stdlib.h>

int * bubbleSort(int * array, int nrOfElements);
int * quickSort(int * array, int left, int right);
int * countingSort(int * array, int nrOfElements);
void printArray(int * array, int nrOfElements);
void printDetails();

int nrOfAssignments = 0;
int nrOfAccesses = 0;
int nrOfComparisons = 0;

int main(){
    FILE * f = fopen("..//input.txt", "r");
    int nrOfElements;
    fscanf(f, "%d", &nrOfElements);
    int * array = (int*)malloc(nrOfElements * sizeof(int));
    for(int i=0; i<nrOfElements; i++){
        fscanf(f,"%d", &array[i]);
    }
    int * sortedArray;

    sortedArray = bubbleSort(array, nrOfElements);
    printArray(sortedArray, nrOfElements);
    printDetails();

    nrOfAssignments = nrOfAccesses = nrOfComparisons = 0;
    printf("\nQuick sort started\n");
    sortedArray = quickSort(array, 0, nrOfElements-1);
    printArray(sortedArray, nrOfElements);
    printDetails();

    nrOfAssignments = nrOfAccesses = nrOfComparisons = 0;
    sortedArray = countingSort(array, nrOfElements);
    printArray(sortedArray, nrOfElements);
    printDetails();


    return 0;
}
void swap(int * x, int * y){
    int temp = *x;
    *x = *y;
    *y = temp;
}
int * bubbleSort(int * array, int nrOfElements){
    printf("\nBubble sort started\n");
    for(int i=0; i<nrOfElements-1; i++){
        for(int j=0; j<nrOfElements-i-1; j++){
            nrOfComparisons++;
            if(array[j] > array[j+1]){
                swap(&array[j],&array[j+1]);
                nrOfAccesses += 4;
                nrOfAssignments+= 2;
            }
        }
    }
    return array;
}
void printArray(int * array, int nrOfElements){
    for(int i=0; i<nrOfElements; i++){
        printf("%d ", array[i]);
    }
    printf("\n");
}
void printDetails(){
    printf("Number of Comparisons: %d\nNumber of Accesses: %d\nNumber of Assignments: %d\n", nrOfComparisons, nrOfAccesses, nrOfAssignments);
}
int partition (int * array, int left, int right)
{
    int pivot = array[right];
    nrOfAccesses++;
    int i=(left - 1);
    for (int j=left; j <= right-1; j++){
        nrOfComparisons++;
        if (array[j] < pivot){
            i++;
            swap(&array[i], &array[j]);
            nrOfAccesses += 4;
            nrOfAssignments+= 2;
        }
    }
    swap(&array[i+1], &array[right]);
    nrOfAccesses += 4;
    nrOfAssignments+= 2;
    return (i + 1);
}
int * quickSort(int * array, int left, int right){
    nrOfComparisons++;
    if (left < right)
    {
        int index = partition(array, left, right);
        quickSort(array, left, index - 1);
        quickSort(array, index + 1, right);
    }
    return array;
}
int * countingSort(int * array, int nrOfElements){
    printf("\nCounting sort started\n");
    int * newArray = (int*)malloc(nrOfElements * sizeof(int));
    int max = 0;
    for (int i=0; i<nrOfElements; i++) {
        nrOfComparisons++;
        if (array[i] > max) {
            max = array[i];
            nrOfAccesses++;
        }
    }
    int * count = (int*)malloc(max * sizeof(int));
    for(int i=0; i<=max; i++){
        count[i]=0;
    }
    for (int i=0; i<nrOfElements; i++) {
        count[array[i]]++;
        nrOfAccesses++;
    }
    for (int i=1; i<=max; i++) {
        count[i] += count[i-1];
    }
    for (int i=nrOfElements-1; i>=0; i--) {
        newArray[count[array[i]]-1] = array[i];
        count[array[i]]--;
        nrOfAccesses += 3;
    }
    for (int i=0; i<nrOfElements; i++) {
        array[i] = newArray[i];
        nrOfAssignments++;
    }
    return newArray;
}