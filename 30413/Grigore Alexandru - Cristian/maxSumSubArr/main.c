#include <stdio.h>
#include <stdlib.h>
#include <limits.h>


int max(int x,int y)
{
    if(x>y)
        return x;
    else
        return y;
}

int maxSum(int arr[],int bot,int top)
{
    if(bot==top)
    {
        return arr[bot];
    }
    int mid=(top+bot)/2;
    int left=INT_MIN;
    int sum=0;
    for(int i=mid;i>=bot;i--)
    {
        sum+=arr[i];
        if(sum>left)
        {
            left=sum;
        }
    }
    int right=INT_MIN;
    sum=0;
    for(int i=mid;i<=top;i++)
    {
        sum+=arr[i];
        if(sum>right)
        {
            right=sum;
        }
    }
    int maxLeftRight=max(maxSum(arr,bot,mid),maxSum(arr,mid+1,top));
    return max(maxLeftRight,left+right);
}

int main()
{
    int i,n;
    printf("Enter numner of elements of the array: ");
    scanf("%d",&n);
    int arr[n];
    for(i=0;i<n;i++)
    {
        printf("arr[%d]=",i);
        scanf("%d",&arr[i]);
    }
    int x=sizeof(arr)/sizeof(arr[0]);
    printf("Max sum is:%d",maxSum(arr,0,x-1));
    return 0;
}
