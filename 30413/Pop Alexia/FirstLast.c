#include <stdio.h>
#include <stdlib.h>

int FirstOccurance(int arr[],int n,int x)
{
    int left=0,right=n-1,mid=0,found=-1;
    while(left<=right)
    {
        mid=(left+right)/2;
        if(x==arr[mid])
        {
            found=mid;
            right=mid-1;
        }
        else if(x<arr[mid]) right=mid-1;
        else if(x>arr[mid]) left=mid+1;

    }
    return found;
}
int LastOc(int arr[],int n,int x)
{
    int left=0,right=n-1,mid;
    int found2=-1;
    while(left<=right)
    {
        mid=(left+right)/2;
        if(x==arr[mid])
        {
            found2=mid;
            left=mid+1;
        }
        else if(x<arr[mid]) right=mid-1;
        else  left=mid+1;

    }
    return found2;
}
int main()
{
    int arr[]= {1,1,2,2,3,3,3,5,6};
    int n,x;
    scanf("%d",&x);
    n=sizeof(arr)/sizeof(*arr);
    int found=FirstOccurance(arr,n,x);
    if(found!=-1) printf("The first occurance of %d is at index %d\n",x,found);
    else printf("Element is not part of the array !\n");
    int found2=LastOc(arr,n,x);
    if(found2!=-1) printf("The last occurance of %d is at index %d\n",x,found2);
    else printf("Element is not part of the array !\n");


    return 0;
}
