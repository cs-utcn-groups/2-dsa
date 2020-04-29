#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int difference;
int firstElement;
bool found=false;

void computeDifference(int * arr, int arrSize)
{
    if(arr[1]-arr[0]!=arr[2]-arr[1])
    {
        if(arr[1]-arr[0]==arr[3]-arr[2])
        {
            printf("missing term %d between indexes 1 and 2",arr[1]+arr[1]-arr[0]);
            found=true;
            return;
        }

        else if(arr[2]-arr[1]==arr[3]-arr[2])
        {
            printf("missing term %d between indexes 0 and 1",arr[0]+arr[2]-arr[1]);
            found=true;
            return;
        }
    }

    else
    {
        difference=arr[1]-arr[0];
    }
}
//////////////////////////////////////// fa cu time elapsed sa vad comparatii
void find(int * arr,int arrSize, int index, int lastIntroducedIndex)
{

    int currentTheoreticalElement=firstElement+index*difference;

    if(arr[index]-arr[index-1]!=difference)
    {
        printf("missing term %d between indexes %d and %d",currentTheoreticalElement,index-1,index);
        exit(0);
    }

    if(arr[index+1]-arr[index]!=difference)
    {
        printf("missing term %d between indexes %d and %d",currentTheoreticalElement+difference,index,index+1);
        exit(0);
    }

    if(currentTheoreticalElement==arr[index]) /// it means that there is something wrong on the right
    {
        find(arr,arrSize,(arrSize+index)/2,index);
    }

    else if(currentTheoreticalElement<arr[index])/// it means that there is something wrong on the left
    {
        find(arr,arrSize,(lastIntroducedIndex+index)/2,index);
    }
}

int main()
{
    int arrSize;
    scanf("%d",&arrSize);
    int * arr=(int *) malloc(sizeof(int) * arrSize);

    for(int i=0; i<arrSize; i++)
    {
        scanf("%d",&arr[i]);
    }
//////////////////////////////////////////////////////// suppose that the ratio (difference) > 0 <=> array is ascending
    computeDifference(arr,arrSize);

    if(found==false)
    {
        firstElement=arr[0];
        find(arr,arrSize,arrSize/2,0);
    }

    return 0;
}

/// 17 1 3 5 7 9 11 13 15 17 21 23 25 27 29 31 33 35
/// 12 1 3 5 7 9 11 13 15 17 21 23 25
/// 5 5 7 9 11 15
/// 5 1 4 7 13 16
