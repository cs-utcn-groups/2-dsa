#include "io.h"
#include "files.h"
#include "hashTable.h"
int main()
{
    int N = _5000;

    char ** content = readFromFile(N);
    initHashTable(N);
    size=(INITIAL_HT_SIZE_FACTOR * N);
    for(int i=0;i<N;i++)
    {
        insertElement(*(content+i));

    }
    computeDistributionsPerBucket(N, content);
    computeStandardDeviation();
    return 0;
}