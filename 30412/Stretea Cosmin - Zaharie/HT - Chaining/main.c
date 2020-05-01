#include "io.h"
#include "files.h"
#include "hashTable.h"

void computeStandardDeviation(int N);

int main()
{
    int N = _1000;

    char ** content = readFromFile(N);
    //printContentToConsole(content,N);
    initHashTable(N);

    for (int i = 0; i < N; ++i) {
        insertElement(content[i], i);
    }
    computeDistributionsPerBucket(N);

    computeStandardDeviation(N);
    return 0;
}


