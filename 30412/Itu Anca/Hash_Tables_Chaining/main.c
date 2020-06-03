#include "io.c"
#include "files.h"
#include "hashTable.c"

int main()
{
    int N = _100;

    char ** content = readFromFile(N);
    printContentToConsole(content,N);

    initHashTable(N);
    printf("%d\n", size);

    for(int i = 0; i < N; i++){
        insertElement(*(content+i));
    }

    computeDistributionsPerBucket(N);

    printf("The standard deviation is: %.2f", standardDeviation(N));
    return 0;
}

