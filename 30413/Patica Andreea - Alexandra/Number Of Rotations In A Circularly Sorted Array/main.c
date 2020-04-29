#include <stdio.h>
#include <stdlib.h>

int FindRotationCount(int *arr, int n)
{
    int low = 0;
    int high = n-1;

    while (low <= high)
    {
        if (arr[low] <= arr[high])
        {
            return low;
        }
        int mid = (low + high)/2;

        int next = (mid + 1)%n;
        int prev = (mid - 1 + n)%n;

        if (arr[mid] <= arr[next] && arr[mid] <= arr[prev])
        {
            return mid;
        }
        else if (arr[mid] <= arr[high])
        {
            high = mid-1;
        }
        else if (arr[mid] >= arr[low])
        {
            low = mid+1;
        }
    }
    return -1;
}

int main(int argc, char *argv[])
{

    FILE *f = fopen(argv[1],"r");
    FILE *g = fopen(argv[2], "w");

    int n;
    fscanf(f, "%d", &n);
    int *Array = (int*)malloc(sizeof(int)*n);
    for (int i=0; i<n; i++)
    {
        fscanf(f, "%d", &Array[i]);
    }

    int nrOfRotations = FindRotationCount(Array, n);
    if (nrOfRotations == -1)
    {
        fprintf(g, "Invalid input\n");
    }
    else
    {
        fprintf(g, "%d", nrOfRotations);
    }

    return 0;
}
