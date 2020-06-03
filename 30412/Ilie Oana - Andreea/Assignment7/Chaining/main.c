#include "io.h"
#include "files.h"
#include "hashTable.h"

int main()
{
    int N = _50000;
    char ** content = readFromFile(N);
    initHashTable(N);
    for(int i = 0; i<N; i++) {
        insertElement(*(content+i));
    }
    printf("The distributions/bucket are: \n");
    computeDistributionsPerBucket(N);
    printf("The standard deviation is: %.4lf\n",calculateStandardDeviation(N));
    return 0;
}