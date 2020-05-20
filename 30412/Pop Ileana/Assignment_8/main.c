#include "generateArray.h"
#include "sortingAlgorithms.h"

int main() {

    int count = 10;
    srand(time(0));
    int * array = generateArrayOfNumbers(10,100,count);
    printf("Initial Array:");
    printArray(array,count);

    int * auxArray = copyArray(array,count);

    insertionSort(auxArray,count);

    auxArray = copyArray(array,count);

    mergeSort(auxArray,count);

    auxArray = copyArray(array,count);

    countingSort(auxArray,count);

    quickSort(array,count);


    return 0;
}