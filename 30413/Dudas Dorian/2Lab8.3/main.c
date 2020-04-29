/*
Find first or last occurrence of a given number in sorted array

Given a sorted array of integers, find index of first and last occurrence of a given number.
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

    if(firstIndexOfTarget >= 0) ///if it appears only once, that's enough to guarantee both a first and last appearance
    {
        if(firstIndexOfTarget == lastIndexOfTarget)
        {
            printf("\nThe element appears only once at index %d", firstIndexOfTarget);
        }
        else
        {
            printf("\nThe element first occurs at index %d, and last does so at index %d", firstIndexOfTarget, lastIndexOfTarget);
        }
    }
    else
    {
        printf("\nThe element doesn't appear in the array.");
    }


    return 0;
}
