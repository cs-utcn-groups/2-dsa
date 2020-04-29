#include <stdio.h>
#include <stdlib.h>

void mergeSort(int left, int mid, int right, int* array, int n) {

    int*aux = (int*)malloc(sizeof(int) * n);

    int i = left;
    int j = mid + 1;
    int index = i;

    while(i <= mid && j <= right) {

        if(array[i] < array[j]) {

            aux[index++] = array[i++];

        } else {

            aux[index++] = array[j++];

        }

    }

    for(int l = i; l <= mid; l++)
        aux[index++] = array[l];

    for(int l = j; l <= right; l++)
        aux[index++] = array[l];

    for(int l = left; l <= right; l++)
        array[l] = aux[l];

}

void merge(int left, int right, int* array, int n) {

    //printf("%d %d", left, right);
    int mid;

    if(left < right) {

        mid = (left + right) / 2;
        merge(left, mid, array, n);
        merge(mid + 1, right, array, n);
        mergeSort(left, mid, right, array, n);

    }
}

void read(int n, int* array, FILE* in) {

    for(int i = 0; i < n; i++) {

        fscanf(in, "%d", &array[i]);

    }
}

void printArray(int* array, int n) {

    for(int i = 0; i < n; i++)
        printf("%d ", array[i]);


}

int main(int argc, char* argv[])
{
    FILE* in = fopen(argv[1], "r");
    int n;

    fscanf(in, "%d", &n);
    printf("%d\n", n);
    int* array = (int*)malloc(sizeof(int) * n);

    read(n, array, in);

    merge(0, n - 1, array, n);

    printArray(array, n);
    return 0;
}
