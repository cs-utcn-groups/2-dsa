#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define INPUT_FILE_PATH "../input.dat"
#define OUTPUT_FILE_PATH "../output.dat"

int noOfComparisons, noOfAssignments, noOfAccesses, noOfActions;

void initialize(){
    noOfComparisons=0, noOfAssignments=0, noOfAccesses=0, noOfActions=0;
}

void readArray(FILE *inputFile, int *array, int noOfElements){
    for(int i=0; i < noOfElements; i++)
    {
        fscanf(inputFile, "%d", &array[i]);
    }
}

void insertionSort(int *array, int noOfElements)
{
    int i, key, j;
    for (i = 1; i < noOfElements; i++) {
        key = array[i];
        noOfAccesses++;
        noOfAssignments++;
        j = i - 1;
        noOfAssignments++;
        while (j >= 0 && array[j] > key) {
            array[j + 1] = array[j];
            noOfComparisons++;
            noOfAccesses++;
            j = j - 1;
            noOfAssignments++;
        }
        array[j + 1] = key;
        noOfAssignments++;
    }
}

void swap(int* a, int* b)
{
    int t = *a;
    *a = *b;
    *b = t;
    noOfAssignments += 2;
}

int partition (int *array, int low, int high)
{
    int pivot = array[high];
    noOfAccesses++;
    int i = (low - 1);

    for (int j = low; j <= high- 1; j++)
    {
        if (array[j] < pivot)
        {
            noOfComparisons++;
            i++;
            swap(&array[i], &array[j]);
            noOfAccesses+=3;

        }
    }
    swap(&array[i + 1], &array[high]);
    noOfAccesses+=2;
    return (i + 1);
}

void quickSort(int *array, int low, int high)
{
    if (low < high)
    {
        noOfComparisons++;
        int pi = partition(array, low, high);

        quickSort(array, low, pi - 1);
        quickSort(array, pi + 1, high);
    }
}


int getMax(int *array, int noOfElements)
{
    int maximum = array[0];
    for (int i = 1; i < noOfElements; i++){
        if (array[i] > maximum){
            maximum = array[i];
            noOfAssignments++;
            noOfAccesses++;
        }
        noOfAccesses++;
    }
        noOfComparisons += (noOfElements-1);
    return maximum;
}


void countSort(int *array, int noOfElements, int exp)
{
    int *output = (int*)malloc(noOfElements * sizeof(int));
    int i, count[10] = {0};

    for (i = 0; i < noOfElements; i++)
        count[ (array[i]/exp)%10 ]++;
    noOfAccesses += (noOfElements+1);

    for (i = 1; i < 10; i++)
        count[i] += count[i - 1];
    noOfAccesses += (noOfElements+1);

    for (i = noOfElements - 1; i >= 0; i--)
    {
        output[count[ (array[i]/exp)%10 ] - 1] = array[i];
        count[ (array[i]/exp)%10 ]--;
    }
    noOfAccesses += (noOfElements) *2;

    memcpy(array, output, noOfElements);
}


void radixSort(int *array, int noOfElements)
{
    int m = getMax(array, noOfElements);

    for (int exp = 1; m/exp > 0; exp *= 10)
        countSort(array, noOfElements, exp);
}

void printArray(FILE *outputFile, int *array, int noOfElements)
{
    int i;
    for (i = 0; i < noOfElements; i++)
        fprintf(outputFile, "%d ", array[i]);
    fprintf(outputFile, "\n");
    fprintf(outputFile, "Number Of Comparisons: %d\nNumber Of Assignments: %d\nNumber Of Accesses: %d\nTotal number of actions: %d\n\n", noOfComparisons, noOfAssignments, noOfAccesses, noOfActions);
}

int main()
{
    FILE *inputFile = fopen(INPUT_FILE_PATH, "r");
    if(inputFile == NULL){
        perror("Error opening file");
        return(-1);
    }

    FILE *outputFile = fopen(OUTPUT_FILE_PATH, "w");


    int noOfElements;
    fscanf(inputFile, "%d", &noOfElements);
    int *array1 = (int *)malloc(noOfElements * sizeof(int));
    int *array2 = (int *)malloc(noOfElements * sizeof(int));
    int *array3 = (int *)malloc(noOfElements * sizeof(int));

    readArray(inputFile, array1, noOfElements);

    memcpy(array2, array1, noOfElements* sizeof(int));
    memcpy(array3, array1, noOfElements* sizeof(int));

    initialize();
    insertionSort(array1, noOfElements);
    noOfActions = noOfComparisons + noOfAccesses + noOfAssignments;
    fprintf(outputFile, "Insertion sort: ");
    printArray(outputFile,array1, noOfElements);

    initialize();
    quickSort(array2, 0, noOfElements - 1);
    noOfActions = noOfComparisons + noOfAccesses + noOfAssignments;
    fprintf(outputFile, "Quick sort: ");
    printArray(outputFile,array2, noOfElements);

    initialize();
    radixSort(array3, noOfElements);
    noOfActions = noOfComparisons + noOfAccesses + noOfAssignments;
    fprintf(outputFile, "Radix sort: ");
    printArray(outputFile,array3, noOfElements);

    return 0;
} 