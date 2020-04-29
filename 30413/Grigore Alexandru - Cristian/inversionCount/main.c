#include <stdio.h>
#include <stdlib.h>

int merge(int *arr,int *aux,int bot,int mid,int top)
{
    int k=bot;
    int i=bot;
    int j=mid+1;
    int invCount=0;
    while(i<=mid && j<=top)
    {
        if(arr[i]<=aux[j])
        {
            aux[k++]=arr[i++];
        }
        else
        {
            aux[k++]=arr[j++];
            invCount+=(mid-i+1);
        }
    }
    while(i<=mid)
    {
        aux[k++]=arr[i++];
    }
    for(int p=bot;p<=top;p++)
    {
        arr[p]=aux[p];
    }
    return invCount;
}

int mergeSort(int *arr,int *aux,int bot,int top)
{
    if(top==bot)
    {
        return 0;
    }
    int mid=(bot+((top-bot)>>1));
    int invCount=0;
    invCount+=mergeSort(arr,aux,bot,mid);
    invCount+=mergeSort(arr,aux,mid+1,top);
    invCount+=merge(arr,aux,bot,mid,top);
    return invCount;
}

int main()
{
    int n;
    printf("Enter nr of elements: \n");
    scanf("%d",&n);
    int *arr=(int*)malloc(sizeof(int)*n);
    for(int i=0;i<n;i++)
    {
        printf("arr[%d]= ",i);
        scanf("%d",&arr[i]);
        printf("\n");
    }
    int *aux=(int*)malloc(sizeof(int)*n);
    for(int i=0;i<n;i++)
    {
        aux[i]=arr[i];
    }
    printf("Inversion count is: %d",mergeSort(arr,aux,0,n-1));
    return 0;
}
