#include "io.h"
#include "files.h"
#include "hashTable.h"

int main()
{
    int N = _100;
    initHashTable(N);
    char ** content = readFromFile(N);
    for(int i=0;i<N;i++)
    {
        insertElement(content[i]);
    }
    computeDistributionsPerBucket(N);
    //printContentToConsole(content,N);

    return 0;
}
