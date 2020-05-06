#include "head.h"

int main()
{
    FILE *f=fopen("input.in","r");

    int n,lBound,rBound;
    readFile(f,&n);
    lBound=0;
    rBound=n-1;
    mergesort(&n,lBound,rBound);
    printArray(&n);

        return 0;
}
