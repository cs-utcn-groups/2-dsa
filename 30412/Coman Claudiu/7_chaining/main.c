#include "io.h"
#include "files.h"
#include "hashTable.h"

int main()
{
    int N = _100;
    char ** content = readFromFile(N);
    initHashTable(N);
    for(int i=0;i<N;i++)
    {
        insertElement(content[i]);
    }
    computeDistributionsPerBucket(N);
    return 0;
}