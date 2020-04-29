#include <stdio.h>
#include <stdlib.h>

int firstOccurence(int number, int n, int* array, int left, int right) {

    if(left > right)
        return -1;

    int mid = (left + right) / 2;

    if(array[mid] > number)
        return firstOccurence(number, n, array, left, mid - 1);
    else if(array[mid] < number)
        return firstOccurence(number, n, array, mid + 1, right);

    if(array[mid - 1] != number)
        return mid;
    else
        return firstOccurence(number, n, array, left, mid - 1);

}

int lastOccurence(int number, int n, int* array, int left, int right) {

    if(left > right)
        return -1;

    int mid = (left + right) / 2;

    if(array[mid] < number)
        return lastOccurence(number, n, array, mid + 1, right);
    else if(array[mid] > number)
        return lastOccurence(number, n, array, left, mid - 1);

    if(array[mid + 1] != number)
        return mid;
    else
        return lastOccurence(number, n, array, mid + 1, right);
}
void read(int* number, int* n, int* array, FILE* in) {

    fscanf(in, "%d %d", n, number);

    for(int i = 0; i < *n; i++)
        fscanf(in, "%d", &array[i]);

}

int main(int argc, char* argv[])
{
    FILE* in = fopen(argv[1], "r");

    int n;
    int number;
    int* array = (int*)malloc(sizeof(int) * n);
    read(&number, &n, array, in);
    int first, last;

    first = firstOccurence(number, n, array, 0, n - 1);

    if(first == -1)
        printf("Number %d does not exist in the array.\n", number);
    else
        printf("First occurence for the number %d is on position %d.\n", number, first);

        last = lastOccurence(number, n, array, 0, n - 1);

    if(last == -1)
        printf("Number %d does not exist in the array.\n", number);
    else
        printf("Last occurence for the number %d is on position %d", number, last);
    return 0;
}
