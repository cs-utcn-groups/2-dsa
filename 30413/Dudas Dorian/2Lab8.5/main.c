/*
Count occurrences of a number in sorted array with duplicates

Given a sorted array of integers containing duplicates, count occurrences of a number provided.
If the element is not found in the array, report that as well.
*/
#include <stdio.h>
#include <stdlib.h>

int firstOccurrence(int array[], int arrayLength, int target)
{
    int left = 0, right = (arrayLength - 1);

    int pursuedIndex = -1;

    while (left <= right)
    {
        int middle = (left + right)/2;

        if(target == array[middle])
        {
            pursuedIndex = middle;
            right = middle - 1;
        }
        else if(target < array[middle])
        {
            right = middle - 1;
        }
        else
        {
            left = middle + 1;
        }
    }
    return pursuedIndex;
}

int lastOccurrence(int array[], int arrayLength, int target)
{
    int left = 0, right = (arrayLength - 1);

    int pursuedIndex = -1;

    while (left <= right)
    {
        int middle = (left + right)/2;

        if(target == array[middle])
        {
            pursuedIndex = middle;
            left = middle + 1;
        }
        else if(target < array[middle])
        {
            right = middle - 1;
        }
        else
        {
            left = middle + 1;
        }
    }
    return pursuedIndex;
}


int main()
{
    int array[] = {1, 2, 3, 3, 3, 4, 5, 5, 5, 5, 5, 7, 7, 8, 9, 9, 12, 12, 12};
    int arrayLength = sizeof(array)/sizeof(array[0]);

    int target, firstIndexOfTarget, lastIndexOfTarget;
    printf("Enter the targeted number: ");
    scanf("%d", &target);

    firstIndexOfTarget = firstOccurrence(array, arrayLength, target);
    lastIndexOfTarget = lastOccurrence(array, arrayLength, target);

    if(firstIndexOfTarget >= 0)
    {
        printf("\nElement %d appears %d times in the array.", target, (lastIndexOfTarget - firstIndexOfTarget + 1));
    }
    else
    {
        printf("\nThe element doesn't appear in the array.");
    }


    return 0;
}
