#include <stdio.h>

int main()
{
    FILE *ifptr, *ofptr;
    ifptr = fopen("input.dat", "r");
    ofptr = fopen("output.dat", "w");

    return 0;
}