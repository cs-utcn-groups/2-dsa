#include <stdio.h>
#include <stdlib.h>

int BinarySearch(int *arr, int n, int x, int searchFirst)
{
    int low = 0, high = n-1;
    int result = -1;

    while (low <= high)
    {
        int mid = (low + high)/2;
        if (x == arr[mid])
        {
            result = mid;

            if (searchFirst == 1)
            {
                high = mid-1;
            }
            else
            {
                low = mid + 1;
            }
        }
        else if (x < arr[mid])
        {
            high = mid-1;
        }
        else
        {
            low = mid+1;
        }
    }

    return result;
}

int main(int argc, char *argv[])
{
    FILE *f = fopen(argv[1], "r");
    FILE *g = fopen(argv[2], "w");

    int n, target;
    fscanf(f, "%d%d", &n, &target);
    int *Array = (int*)malloc(sizeof(int*)*n);
    for (int i=0; i<n; i++)
    {
        fscanf(f, "%d", &Array[i]);
    }

    int first = BinarySearch(Array, n, target, 1);
    int last = BinarySearch(Array, n, target, 0);
    int count = last - first +1;

    if(first!=-1)
    {
        fprintf(g, "Element occurs %d times.\n", count);
    }
    else
    {
        fprintf(g, "Element not found!");
    }

    return 0;
}
