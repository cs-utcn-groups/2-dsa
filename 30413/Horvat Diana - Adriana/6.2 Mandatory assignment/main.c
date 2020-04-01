#include "head.h"

int main()
{
    FILE *f=fopen("input.in","r");
    FILE *g=fopen("output.out","w");

    int *n=(int *)malloc(sizeof(int)*10);
    char **inputData=readFile(f,n);
    processCommandsFromInputData(inputData,n,g);

    return 0;
}
