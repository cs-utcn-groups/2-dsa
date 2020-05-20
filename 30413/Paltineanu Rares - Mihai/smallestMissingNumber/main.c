#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int minMissingNumber(int* array, int n, int left, int right) {

    if(left > right)
        return left;

    int mid = (left + right) / 2;

    if(array[mid] == mid)
        return minMissingNumber(array, n, mid + 1, right);
    else
        return minMissingNumber(array, n, left, mid - 1);

}

void read(int* array, int n, FILE* in) {

    for(int i = 0; i < n ;i++)
        fscanf(in, "%d", &array[i]);

    for(int i = 0 ; i < n; i++)
        printf("%d ", array[i]);
    printf("\n\n");

}

int main(int argc, char* argv[])
{
    FILE* in = fopen(argv[1], "r");
    int n;
    fscanf(in, "%d", &n);
    int* array = (int*)malloc(sizeof(int) * n);
    read(array, n, in);

    printf("%d", minMissingNumber(array, n, 0, n - 1));
    return 0;
}
