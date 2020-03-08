#include <stdio.h>
#include "queue.h"
int main()
{
    FILE *ifptr = fopen("input.dat", "r");
    FILE *ofptr = fopen("output.dat", "w");
    readData(ifptr, ofptr);
    solve(ofptr);

    return 0;
}