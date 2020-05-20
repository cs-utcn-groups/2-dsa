#include <stdio.h>
#include <stdlib.h>

int comparisons, assignments, accesses;
void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void selectionSort(int arr[], int n)
{
    int i, j, min_idx;
    // One by one move boundary of unsorted subarray
    for (i = 0; i < n-1; i++)
    {
        // Find the minimum element in unsorted array
        min_idx = i;
        for (j = i+1; j < n; j++) {
            if (arr[j] < arr[min_idx]) {
                min_idx = j;
            }
            comparisons++;
            accesses+= 2;
        }
        // Swap the found minimum element with the first element
        swap(&arr[min_idx], &arr[i]);
        assignments+= 3;
        accesses+= 4;
    }
}
int partition (int arr[], int low, int high)
{
    int pivot = arr[high];    // pivot
    int i = (low - 1);  // Index of smaller element
    assignments+= 2;

    for (int j = low; j <= high- 1; j++)
    {
        // If current element is smaller than the pivot
        if (arr[j] < pivot)
        {
            i++;    // increment index of smaller element
            swap(&arr[i], &arr[j]);
            assignments+= 3;
            accesses+= 4;
        }
        comparisons++;
        accesses++;
    }
    swap(&arr[i + 1], &arr[high]);
    accesses+= 4;
    assignments+= 3;
    return (i + 1);
}

void quickSort(int arr[], int low, int high)
{
    if (low < high)
    {
        /* pi is partitioning index, arr[p] is now
           at right place */
        int pi = partition(arr, low, high);

        // Separately sort elements before
        // partition and after partition
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}
int getMax(int arr[], int n)
{
    int mx = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] > mx) {
            mx = arr[i];
            accesses++;
            assignments++;
        }
        comparisons++;
        accesses++;
    }
    return mx;
}

// A function to do counting sort of arr[] according to
// the digit represented by exp.
void countSort(int arr[], int n, int exp)
{
    int output[n]; // output array
    int i, count[10] = {0};

    // Store count of occurrences in count[]
    for (i = 0; i < n; i++) {
        count[(arr[i] / exp) % 10]++;
        accesses++;
    }

    // Change count[i] so that count[i] now contains actual
    //  position of this digit in output[]
    for (i = 1; i < 10; i++)
        count[i] += count[i - 1];

    // Build the output array
    for (i = n - 1; i >= 0; i--)
    {
        output[count[ (arr[i]/exp)%10 ] - 1] = arr[i];
        count[ (arr[i]/exp)%10 ]--;
        accesses+= 3;
    }

    // Copy the output array to arr[], so that arr[] now
    // contains sorted numbers according to current digit
    for (i = 0; i < n; i++) {
        arr[i] = output[i];
        accesses++;
        assignments++;
    }
}

void radixSort(int arr[], int n)
{
    // Find the maximum number to know number of digits
    int m = getMax(arr, n);

    // Do counting sort for every digit. Note that instead
    // of passing digit number, exp is passed. exp is 10^i
    // where i is current digit number
    for (int exp = 1; m/exp > 0; exp *= 10)
        countSort(arr, n, exp);
}

void printArray(int arr[], int size)
{
    int i;
    for (i=0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

int main()
{
    int arr1[] = {58, 22, 71, 28, 11};
    int n1 = sizeof(arr1)/sizeof(arr1[0]);
    comparisons = assignments = accesses = 0;
    selectionSort(arr1, n1);
    printf("Selection sort: %d comparisons, %d assignments, %d accesses\n", comparisons, assignments, accesses);
    printArray(arr1, n1);

    int arr2[] = {58, 22, 71, 28, 11};
    int n2 = sizeof(arr2)/sizeof(arr2[0]);
    comparisons = assignments = accesses = 0;
    quickSort(arr2, 0, n2-1);
    printf("Quick sort: %d comparisons, %d assignments, %d accesses\n", comparisons, assignments, accesses);
    printArray(arr2, n2);

    int arr3[] = {58, 22, 71, 28, 11};
    int n3 = sizeof(arr3)/sizeof(arr3[0]);
    comparisons = assignments = accesses = 0;
    radixSort(arr3, n3);
    printf("Radix sort: %d comparisons, %d assignments, %d accesses\n", comparisons, assignments, accesses);
    printArray(arr3, n3);

    return 0;
}