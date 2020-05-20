#include <stdio.h>
#include <stdlib.h>

int Max (int a, int b, int c)
{
    if (a>=b && a>=c) return a;
    if (b>=a && b>=c) return b;
    return c;
}

int MaximumCrossingSum(int Arr[], int low, int mid, int high)
{
    int sum = 0;
    int leftSum = -2147483648;

    for (int i=mid; i>=low; i--)
    {
        sum += Arr[i];
        if (sum > leftSum)
        {
            leftSum = sum;
        }
    }

    sum = 0;
    int rightSum = -2147483648;
    for (int i=mid+1; i<=high; i++)
    {
        sum += Arr[i];
        if (sum > rightSum)
        {
            rightSum = sum;
        }
    }

    return Max(leftSum + rightSum, leftSum, rightSum);
}

int MaximumSum(int Arr[], int low, int high)
{
    if (low == high)
    {
        return Arr[low];
    }

    int mid = (low + high)/2;

    return Max(MaximumSum(Arr, low, mid), MaximumSum(Arr, mid+1, high), MaximumCrossingSum(Arr, low, mid, high));

}

int main(int argc, char *argv[])
{
    FILE *f = fopen(argv[1], "r");
    FILE *g = fopen(argv[2], "w");

    int n;
    fscanf(f, "%d", &n);
    int *Array = (int*)malloc(sizeof(int)*n);
    for (int i=0; i<n; i++)
    {
        fscanf(f, "%d", &Array[i]);
    }

    int MaxSum = MaximumSum(Array, 0, n-1);
    fprintf(g, "%d", MaxSum);

    return 0;
}
