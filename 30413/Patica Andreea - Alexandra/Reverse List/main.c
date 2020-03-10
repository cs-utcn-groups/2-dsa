#include <stdio.h>
#include <stdlib.h>
#include "header.h"

int main()
{
    printf("Insert the number of elements in the list:\n");
    int n;
    scanf("%d", &n);
    printf("\nInsert %d numbers:\n", n);

    Initialize();

    for (int i=0; i<n; i++)
    {
        int val;
        scanf("%d", &val);
        AddValue(val);
    }

    ReverseList();
    PrintList();

    return 0;
}
