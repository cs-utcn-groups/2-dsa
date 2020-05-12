#include <stdio.h>
#include <stdlib.h>
void bubbleSort(int *array, int length);
void printArray(int *array, int length);
void merge(int* array,int left,int middle,int right, int *actions);
void mergeSort(int *array, int left, int right, int *actions);
void countingSort(int *array, int length);
int main() {
    int nrOfElements;
    scanf("Enter number of elements:\n");
    scanf("%d",&nrOfElements);
    int *array=(int*)malloc(nrOfElements* sizeof(int));
    for(int i=0;i<nrOfElements;i++)
    {
        scanf("%d",&array[i]);
    }
    printArray(array,nrOfElements);
    bubbleSort(array,nrOfElements);
    printArray(array,nrOfElements);
    int actions=0;
    mergeSort(array,0,nrOfElements-1,&actions);
    printf("Merge sort actions: %d\n",actions);
    printArray(array,nrOfElements);
    countingSort(array,nrOfElements);
    printArray(array,nrOfElements);
    return 0;
}
void bubbleSort(int *array, int length)
{
    int actions=0;
    int aux;
    for(int i=0;i<length-1;i++)
    {
        for(int j=0;j<length-i-1;j++) {
            if (array[j] > array[j + 1]) {
                actions++;
                aux = array[j];
                array[j] = array[j + 1];
                actions++;
                array[j + 1] = aux;
                actions++;
            }

        }

    }
    printf("Bubble sort actions: %d\n",actions);
}
void mergeSort(int *array, int left, int right, int *actions)
{

    if(left<right)
    {
        int middle=left+(right-left)/2;
        mergeSort(array,left,middle,actions);
        mergeSort(array,middle+1,right,actions);
        merge(array,left,middle,right,actions);
    }

}
void merge(int* array,int left,int middle,int right,int *actions) {
    int index1 = middle - left + 1;
    int index2 = right - middle;
    int *leftArr, *rightArr;
    leftArr = (int *) malloc(index1 * sizeof(int));
    rightArr = (int *) malloc(index2 * sizeof(int));
    for (int i = 0; i < index1; i++)
        leftArr[i] = array[left + i];
    for (int j = 0; j < index2; j++)
        rightArr[j] = array[middle + j + 1];
    int i = 0, j = 0, k = left;
    while (i < index1 && j < index2) {
        if (leftArr[i] <= rightArr[j]) {
            (*actions)++;
            array[k] = leftArr[i];
            (*actions)++;
            i++;
        } else {
            array[k] = rightArr[j];
            (*actions)++;
            j++;
        }
        k++;
    }
    while (i < index1) {
        array[k] = leftArr[i];
        (*actions)++;
        i++;
        k++;
    }
    while (j < index2)
    {
        array[k]=rightArr[j];
        (*actions)++;
        j++;
        k++;
    }


}
void countingSort(int *array, int length)
{
    int actions=0;
    int* count,*outArray;
    int maxElement=0;
    for(int i=0;i<length;i++) {
        if (array[i] > maxElement) {
            actions++;
            maxElement = array[i];
        }
    }
    maxElement++;
    count=(int*)malloc(maxElement* sizeof(int));
    outArray=(int*)malloc(length* sizeof(int));
    for(int i=0;i<maxElement;i++)
        count[i]=0;
    for(int i=0;i<length;i++)
        count[array[i]]++;
    for(int i=1;i<=maxElement;i++)
    {
        count[i]=count[i]+count[i-1];
    }
    for (int i = length- 1; i >= 0; i--) {
        outArray[count[array[i]] - 1] = array[i];
        count[array[i]]--;
    }

    for (int i = 0; i < length; i++) {
        array[i] = outArray[i];
        count++;
    }
    printf("Counting sort actions: %d\n",actions);
}


void printArray(int *array, int length)
{
    for(int i=0;i<length;i++)
    {
        printf("%d ",array[i]);
    }
    printf("\n");
}