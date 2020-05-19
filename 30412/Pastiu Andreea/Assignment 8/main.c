#include <stdio.h>

void bubbleSort(int *array, int length);
void quickSort(int array[], int low, int high);
void countSort(int *arr, int n, int exp);
int getMax(int *arr, int n);
void radixsort(int *arr, int n);
int noOfActions, noOfComparisons = 0, noOfAssignments = 0, noOfAccesses = 0;
int main()
{
    int array[] = {17, 26, 5, 11, 3, 220, 8}, length = 7;
    bubbleSort(array, length);
    printf("Bubble sort:\n");
    for(int i = 0; i < length; i++)
    {
        printf("%d ", array[i]);
    }
    printf("\n");
    noOfActions = noOfComparisons + noOfAssignments + noOfAccesses;
    printf("No of comparisons: %d\n", noOfComparisons);
    printf("No of assignments: %d\n", noOfAssignments);
    printf("No of accesses: %d\n", noOfAccesses);
    printf("No of actions: %d\n", noOfActions);
    noOfComparisons = 0; noOfAssignments = 0; noOfAccesses = 0;
    int array2[] = {17, 26, 5, 11, 3, 220, 8};
    quickSort(array2, 0, length - 1);
    printf("Quick sort:\n");
    for(int i = 0; i < length; i++)
    {
        printf("%d ", array2[i]);
    }
    printf("\n");
    noOfActions = noOfComparisons + noOfAssignments + noOfAccesses;
    printf("No of comparisons: %d\n", noOfComparisons);
    printf("No of assignments: %d\n", noOfAssignments);
    printf("No of accesses: %d\n", noOfAccesses);
    printf("No of actions: %d\n", noOfActions);
    noOfComparisons = 0; noOfAssignments = 0; noOfAccesses = 0;
    int array3[] = {17, 26, 5, 11, 3, 220, 8};
    radixsort(array3, length);
    printf("Quick sort:\n");
    for(int i = 0; i < length; i++)
    {
        printf("%d ", array2[i]);
    }
    printf("\n");
    noOfActions = noOfComparisons + noOfAssignments + noOfAccesses;
    printf("No of comparisons: %d\n", noOfComparisons);
    printf("No of assignments: %d\n", noOfAssignments);
    printf("No of accesses: %d\n", noOfAccesses);
    printf("No of actions: %d\n", noOfActions);

    return 0;
}

void bubbleSort(int *array, int length)
{
    int ready = 0, aux;
    while (ready == 0)
    {
        ready = 1;
        for(int i = 0; i < length-1; i++)
        {
            noOfComparisons++;
            if (array[i] > array[i+1])
            {
                aux = array[i];
                array[i] = array[i+1];
                array[i+1] = aux;
                ready = 0;
                noOfAssignments += 3;
                noOfAccesses += 6;
            }
        }
    }
}

int partition (int array[], int low, int high)
{
    int pivot = array[high], aux;
    int i = (low - 1);
    for (int j = low; j <= high- 1; j++)
    {
        noOfComparisons++;
        if (array[j] < pivot)
        {
            i++;
            aux = array[i];
            array[i] = array[j];
            array[j] = aux;
            noOfAccesses += 5;
            noOfAssignments += 3;
        }
    }
    aux = array[i+1];
    array[i+1] = array[high];
    array[high] = aux;
    noOfAccesses += 4;
    noOfAssignments += 3;
    return (i + 1);
}
void quickSort(int arr[], int low, int high)
{
    if (low < high)
    {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

void countSort(int *arr, int n, int exp)
{
    int output[n];
    int i, count[10] = {0};

    for (i = 0; i < n; i++)
        count[ (arr[i]/exp)%10 ]++;
    noOfAssignments += n; noOfAccesses += 2*n;

    for (i = 1; i < 10; i++)
        count[i] += count[i - 1];
    noOfAssignments += 9; noOfAccesses += 18;

    for (i = n - 1; i >= 0; i--)
    {
        output[count[(arr[i] / exp) % 10] - 1] = arr[i];
        count[(arr[i] / exp) % 10]--;
        noOfAssignments += 2;
        noOfAccesses += 5;
    }

    for (i = 0; i < n; i++)
        arr[i] = output[i];
    noOfAccesses += 2*n;
    noOfAssignments += n;
}

void radixsort(int *arr, int n)
{
    int m = getMax(arr, n);
    for (int exp = 1; m/exp > 0; exp *= 10)
        countSort(arr, n, exp);
}

int getMax(int *arr, int n)
{
    int mx = arr[0];
    noOfAccesses += n-1;
    noOfComparisons += n-1;
    for (int i = 1; i < n; i++)
    {
        if (arr[i] > mx)
        {
            mx = arr[i];
            noOfAssignments++;
        }
    }
    return mx;
}
